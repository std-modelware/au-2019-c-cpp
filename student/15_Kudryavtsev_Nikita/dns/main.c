#include "requests.h"

#define T_A 1
#define T_NS 2

void help();
void bruteforce();
void get_ns();

unsigned char hostname[30];
char dns_server[30] = "1.1.1.1";
char f_path[30] = "5000.txt";

int main(int argc, char **argv) {
    int i;
    if(argc <= 1) {
        help();
        return 0;
    }
    for (i = 1; i < argc; i++) {
        if(!strcmp(argv[i], "--host")) {
            strncpy((char *)hostname, argv[i + 1], 30);
        }
        else if(!strcmp(argv[i], "--file")) {
            strncpy(f_path, argv[i + 1], 30);
        }
        else if(!strcmp(argv[i], "--dns")) {
            strncpy(dns_server, argv[i + 1], 30);
        }
    }
    if (hostname[0] == '\0') {
        help();
        return 0;
    }

    get_ns();
    bruteforce();

    return 0;
}

void help() {
    printf("Syntax: dns hostname [options]\n");
    printf("OPTIONS:\n");
    printf("\t--host: hostname\n");
    printf("\t--file: file path with prefixes\n");
    printf("\t--dns: dns server\n");
    printf("EXAMPLE:\n");
    printf("\tdns --host spbstu.ru\n");
    printf("\tdns --host spbstu.ru --file 5000.txt\n");
    printf("\tdns --host spbstu.ru --file 5000.txt --dns 8.8.8.8\n");
}

void get_ns() {
    printf("DNS Servers for spbstu.ru:\n");
    dns_request(hostname, dns_server, T_NS, 0, 0, 0);
}

void bruteforce() {
    FILE *file;
    char arr[100];
    char dom[30];
    file = fopen(f_path, "r");
    printf("\nPerforming 5000 tests...");
    while (fgets(arr, 100, file) != NULL) {
        if (arr[strlen(arr) - 1] == '\n') arr[strlen(arr) - 1] = '\0';
        unsigned char m_Test[20];
        snprintf(dom, sizeof dom, "%s.%s", arr, hostname);
        strcpy((char *) m_Test, dom);
        dns_request(m_Test, dns_server, T_A, 1, 1, 1);
    }
}
