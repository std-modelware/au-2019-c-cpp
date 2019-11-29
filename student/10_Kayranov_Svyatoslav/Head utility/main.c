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

/*
♔ Модуль считывания команд ♔
Доступный синтаксис: 
    head filename.txt
    head -n filename.txt - построчное считывание (по умолчанию)
    head -с filename.txt - поБайтовое считывание 
    head -n 20 filename.txt - изменение количества считываемых строк
    head -с 20 filename.txt - изменение количества считываемых Байтов
*/

void readString(){
    scanf("%s%s", utilityName, option);

    //сравнение на наличие опции (-n или -c) в аргументах
    if (strncmp(option, "-", 1)) {
        //опции нету
        copy(fileName, option);
        copy(option, "-n");
        digits = 10;
    }
    else { 
        scanf("%d", &digits);
        if (digits == 0) {
            digits = 10;
            scanf("%s", fileName);
        }
        else {
            scanf("%s", fileName);
        }
    }
    printf("Считано: (%s) (%s) (%d) (%s)\n", utilityName, option, digits, fileName);
}

//проверка введенных аргументов на корректность
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
        }
    }
}
 
void Option() {
    if (!(strncmp(option, "-n", 2))) {
        char c;
        int count = 0;
        FILE* file;
        file = fopen(fileName, "rb");
        printf("Все окей!\n");

        for (count = 0; count < digits; count++) {
            printf("(%d) ", count+1);
            while(1) {
                c = getc(file);
                if ((c == '\n') || (c == EOF))  break;
                printf("%c", c);
            }
            printf("\n");
        }
        fclose(file);
    }
    // проверка если выбрана опция -с
    else {
        char c;
        int count = 0;
        FILE* file;
        file = fopen(fileName, "rb");
        printf("Все окей!\n");

        for (count = 0; count < digits; count++) {
                c = getc(file);
                if ((count == digits) || (c == EOF))  break;
                printf("%c", c);
        }
        fclose(file);
    }
    // доказательство правильной работы программы 
    // https://i.imgur.com/YKYSLca.png
}

int main(void) {
    readString();
    checkArgs();
    Option();
}
