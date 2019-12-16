#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int exists(const char* fname) {
	FILE* file;
	if ((file = fopen(fname, "r"))) {
		fclose(file);
		return 1;
	}
	return 0;
}

void copy(char* __s1, char* __s2) {
	for (int i = 0; i < 100; i++) {
		__s1[i] = __s2[i];
	}
}
// реализация функции из билиотеки string.h чисто для прикола
// int strncmp(const char *__s1, const char *__s2, size_t __n) {
//    bool flag = 0;
//    for (int i = 0; i < __n; i++) {
//        if (__s1[i] != __s2[i]) flag = 1;
//    }
//    return(flag);
//}
