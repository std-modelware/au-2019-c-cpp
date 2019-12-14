#include "requests.h"
#include "whois.h"

void dns_request(unsigned char *host, const char* dns_server, int query_type, int brute, int mail, int whois) {
    unsigned char buf[65536], *qname, *reader;
    int i, j, stop, s;

    struct sockaddr_in a;
    struct RES_RECORD answers[20];
    struct sockaddr_in dest;

    struct DNS_HEADER *dns = NULL;
    struct QUESTION *qinfo = NULL;

    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // UDP пакеты для DNS-запросов

    dest.sin_family = AF_INET; // iPv4
    dest.sin_port = htons(53);// Порт 53
    dest.sin_addr.s_addr = inet_addr(dns_server);

    struct timeval timeout={0,100000}; // Устанавливаем таймаут на 0.1 секунду
    setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(struct timeval));

    // Структура стандартного DNS запроса
    dns = (struct DNS_HEADER *) &buf;

    // https://www2.cs.duke.edu/courses/fall16/compsci356/DNS/DNS-primer.pdf
    dns->id = 1;
    dns->qr = 0;
    dns->opcode = 0;
    dns->aa = 0;
    dns->tc = 0;
    dns->rd = 1;
    dns->ra = 0;
    dns->z = 0;
    dns->ad = 0;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1);
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;

    // Указатель на 2 часть пакета
    qname = (unsigned char *) &buf[sizeof(struct DNS_HEADER)];
    change_to_dns_name_format(qname, host);
    // Указатель на 3 часть пакета
    qinfo = (struct QUESTION *) &buf[sizeof(struct DNS_HEADER) + (strlen((const char *) qname) + 1)];

    qinfo->qtype = htons(query_type); // Тип запроса (A, NS, SOA)
    qinfo->qclass = htons(1); // Интернет

    sendto(s, (char *) buf, sizeof(struct DNS_HEADER) + (strlen((const char *) qname) + 1) + sizeof(struct QUESTION), 0,
           (struct sockaddr *) &dest, sizeof(dest));

    // Получаем ответ
    i = sizeof dest;
    recvfrom(s, (char *) buf, 65536, 0, (struct sockaddr *) &dest, (socklen_t *) &i);

    dns = (struct DNS_HEADER *) buf;

    // Проходим через DNS_HEADER и тело запроса
    reader = &buf[sizeof(struct DNS_HEADER) + (strlen((const char *) qname) + 1) + sizeof(struct QUESTION)];

    // Начинаем читать ответ
    stop = 0;

    for (i = 0; i < ntohs(dns->ans_count); i++) {
        answers[i].name = read_name(reader, buf, &stop);
        reader = reader + stop;

        answers[i].resource = (struct R_DATA *) (reader);
        reader = reader + sizeof(struct R_DATA);

        if (ntohs(answers[i].resource->type) == 1) // Если iPv4
        {
            long *p;
            answers[i].rdata = (unsigned char *) malloc(ntohs(answers[i].resource->data_len));

            for (j = 0; j < ntohs(answers[i].resource->data_len); j++) {
                answers[i].rdata[j] = reader[j];
            }

            answers[i].rdata[ntohs(answers[i].resource->data_len)] = '\0';

            reader = reader + ntohs(answers[i].resource->data_len);
            p = (long *) answers[i].rdata;
            a.sin_addr.s_addr = (*p);
            if (brute) {
                printf("\n%s\t %s", inet_ntoa(a.sin_addr), host);
                if (whois) check_whoice(inet_ntoa(a.sin_addr));
                if (mail) check_mail(inet_ntoa(a.sin_addr));
            }
        } else {
            if (!brute) {
                answers[i].rdata = read_name(reader, buf, &stop);
                reader = reader + stop;
                printf("    %s\n", answers[i].rdata);
            }
        }
    }
}

void change_to_dns_name_format(unsigned char *dns, unsigned char *host) {
    int lock = 0, i;
    if (host[strlen((char *) host) - 1] != '.') strcat((char *) host, ".");

    for (i = 0; i < strlen((char *) host); i++) {
        if (host[i] == '.') {
            *dns++ = i - lock;
            for (; lock < i; lock++) {
                *dns++ = host[lock];
            }
            lock++; //or lock=i+1;
        }
    }
    *dns++ = '\0';
}

u_char *read_name(unsigned char *reader, unsigned char *buffer, int *count) {
    unsigned char *name;
    unsigned int p = 0, jumped = 0, offset;
    int i, j;

    *count = 1;
    name = (unsigned char *) malloc(256);

    name[0] = '\0';

    // Читаем имена вида 3www6google3com
    while (*reader != 0) {
        if (*reader >= 192) {
            offset = (*reader) * 256 + *(reader + 1) - 49152; // 49152 = 11000000 00000000
            reader = buffer + offset - 1;
            jumped = 1; // Мы попали в другое место -> подсчет не будет увеличиваться
        } else {
            name[p++] = *reader;
        }

        reader = reader + 1;

        if (jumped == 0) {
            *count = *count + 1; // Если мы не попали в другое место
        }
    }

    name[p] = '\0'; // Конец строки
    if (jumped == 1) {
        *count = *count + 1; // Количество шагов, на которое мы продвинулись
    }

    // Теперь конвертируем 3www6google3com0 в www.google.com
    for (i = 0; i < (int) strlen((const char *) name); i++) {
        p = name[i];
        for (j = 0; j < (int) p; j++) {
            name[i] = name[i + 1];
            i = i + 1;
        }
        name[i] = '.';
    }
    name[i - 1] = '\0'; // Удаляем последнюю точку
    return name;
}

void check_mail(char *ip) {

    int s, res, valopt; // Сокет, Ответ, Для обработки ошибок соеднинения
    int first_port = 0;
    long arg; // Для установки сокета в неблокирующий режим
    struct sockaddr_in addr; // Описание сокета
    struct timeval tv; // Для таймаута
    fd_set myset; // Массив на 1024 элемента (для сокета)
    socklen_t lon = sizeof(int); // Для обработки ошибок соеднинения

    int ports[7] = {25, 58, 143, 158, 209, 366, 587};

    addr.sin_family = AF_INET; // iPv4
    addr.sin_addr.s_addr = inet_addr(ip); // Указываем Ip

    for (int i = 0; i < 7; i++) { // Проходимся по всем портам
        s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // Создаём новый сокет
        addr.sin_port = htons(ports[i]); // Указываем порт

        // Установка сокета в неблокирующий режим (чтобы была возможность использовать таймаут)
        arg = fcntl(s, F_GETFL, NULL);
        arg |= O_NONBLOCK;
        fcntl(s, F_SETFL, arg);

        // Пробуем подключиться к порту, пока не сработает таймаут
        res = connect(s, (struct sockaddr *) &addr, sizeof(addr)); // Подключение
        do { // Бесконечный цикл
            tv.tv_sec = 0; // Таймаут 1 секунда
            tv.tv_usec = 500000;
            FD_ZERO(&myset); // Очищаем
            FD_SET(s, &myset); // Вставляем новый сокет
            res = select(s + 1, NULL, &myset, NULL, &tv); // Ответ с порта
            if (res > 0) { // Если ошибок при подключении нет
                if (getsockopt(s, SOL_SOCKET, SO_ERROR, (void *) (&valopt), &lon) < 0) break; // Ошибка в getsockopt()
                if (valopt) break; // Ошибка в delayed connection()
                if (first_port == 0) {
                    printf(" | Mail ports: ");
                    printf("%d", ports[i]);
                    first_port = 1;
                } else printf(", %d", ports[i]);
                break;
            } else break; // Таймаут
        } while (1);
        close(s); // Закрываем сокет
    }
}
