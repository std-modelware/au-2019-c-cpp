#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void dns_request(unsigned char *host, const char* dns_server, int query_type, int brute, int mail, int whois);
void change_to_dns_name_format(unsigned char *dns, unsigned char *host);  // www.google.com -> 3www6google3com
u_char *read_name(unsigned char *reader, unsigned char *buffer, int *count);
void check_mail(char *ip);

struct DNS_HEADER {
    unsigned short id;
    unsigned char rd :1;
    unsigned char tc :1;
    unsigned char aa :1;
    unsigned char opcode :4;
    unsigned char qr :1;
    unsigned char rcode :4;
    unsigned char cd :1;
    unsigned char ad :1;
    unsigned char z :1;
    unsigned char ra :1;
    unsigned short q_count;
    unsigned short ans_count;
    unsigned short auth_count;
    unsigned short add_count;
};

// Тело запроса
struct QUESTION {
    unsigned short qtype;
    unsigned short qclass;
};

// Структура записей ресурсов
#pragma pack(push, 1)
struct R_DATA {
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
};
#pragma pack(pop)

// Указатели на содержимое записи ресурса
struct RES_RECORD {
    unsigned char *name;
    struct R_DATA *resource;
    unsigned char *rdata;
};
