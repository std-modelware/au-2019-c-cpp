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
            if (c == EOF) {
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
        char* estr;
        while(1) {
            estr = fgets(c, sizeof(c), fp);
            if (estr == NULL) {
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
        fseek(fp , 0 , SEEK_END);
        long lSize = ftell(fp);
        rewind(fp);
        
        char* buffer = (char*)calloc(lSize, sizeof(char));
        fread(buffer, 1, lSize, fp);
        
        //содержимое файла теперь находится в буфере
        fputs(buffer, fpcopy);
        free (buffer);
        fclose(fpcopy);
        // завершение работы
    }
    fclose (fp);
}