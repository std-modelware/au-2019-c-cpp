#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#define LEN 100

int digits;
char c;
char utilityName[LEN];
char fileName[LEN];
char option[LEN];
char str[LEN];
bool flag = 0;

void readString(){
    scanf("%s%s%d%s", utilityName, option, &digits, fileName);

    if (digits == 0) {
        digits = 10;
        scanf("%s", fileName);
    }
    printf("Считано: (%s) (%s) (%d) (%s)\n", utilityName, option, digits, fileName);
}

void checkArgs() {
    if (strncmp(utilityName, "head", 4)) {
        printf("%s%s%s\n", "No command ", utilityName, " found");
        exit(EXIT_FAILURE);
    }
    else {
        if (strncmp(option, "-n", 2) && strncmp(option, "-c", 2)) {
            printf("%s'%s'\n", "head: invalid operation ", option);
            exit(EXIT_FAILURE);
        }
        else {
            if (!exists(fileName)) {
                printf("%s'%s'%s\n", "head: cannot open ", fileName, " for reading: No such file or directory");
                exit(EXIT_FAILURE);
            }
            else {
                printf("Все окей!1\n");
            }
        }
    }
}

void nOption() {
    if (!(strncmp(option, "-n", 2))) {
        printf("Все окей!2\n");
        char s[200];
        char c;
        FILE* file;
        int count = 0;
        file = fopen(fileName, "r");
        printf("Все окей!3\n");
        for (count = 0; count < digits; count++) {
            while(1) {
                c = fgetc(file);
                if (c == '\n') break;
                printf("%c", c);
            }
            printf("\n");
        }
    }
}

int main(void) {
    readString();
    checkArgs();
    nOption();
}