#include "filesys.h"
#include <stdio.h>
#include <stdlib.h>

void createfile(char name[]) {
    char input [100];
    FILE* fp = fopen(name, "w");
    fgets(input, 100, stdin);
    fprintf(fp, "%s", input);
    fclose(fp);
}

void c_copyfile(char name[], char copyname[]) {
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Unable to open file: %s", name);
    } else {
        FILE* fpcopy = fopen(copyname, "w");
        char c;
        while(1) {
            c = fgetc(fp);
            if (feof(fp)) {
                break;
            }
            fputc(c, fpcopy);
        }
        fclose(fpcopy);
    }
    fclose(fp);
}

void s_copyfile(char name[], char copyname[]) {
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Unable to open file: %s", name);
    } else {
        FILE* fpcopy = fopen(copyname, "w");
        char c[50];
        while(1) {
            fgets(c, 50, fp);
            if (feof(fp)) {
                break;
            }
            fputs(c, fpcopy);
        }
        fclose(fpcopy);
    }
    fclose(fp);
}

void f_copyfile(char name[], char copyname[]) {
    FILE* fp = fopen(name, "r");
    
    if (fp == NULL) {
        printf("Unable to open file: %s", name);
    } else {
        FILE* fpcopy = fopen(copyname, "w");
        char buffer[50];
        int count = 0;
        while(!(feof(fp))) {
            count = fread(buffer, 1, 50, fp);
            fwrite(buffer, 1, count, fpcopy);
        }
        fclose(fpcopy);
        // завершение работы
    }
    fclose (fp);
}