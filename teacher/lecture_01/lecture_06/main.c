#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

void main() {
	printf("string\n");

	// строка оканчивается на символ 0
	const char *s_source = "string 1";
	char s[] = "string 2";

	// копирование всей строки
	char *s_dest1 = (char *)malloc(sizeof(char) * strlen(s_source));
	char *ps = strcpy(s_dest1, s_source);
	
	// копирование части строки
	char *s_dest2 = (char *)malloc(sizeof(char) * strlen(s_source));
	ps = strncpy(s_dest2, s_source, 4);

	// "склеивание" строк
	char *s_dest3 = (char *)malloc(sizeof(char) * strlen(s_source) * 2);
	ps = strcpy(s_dest3, s_source);
	strcat(s_dest3, s_source);

	// "склеивание" строк (ограничение по размеру)
	char *s_dest4 = (char *)malloc(sizeof(char) * strlen(s_source) * 2);
	ps = strcpy(s_dest4, s_source);
	strncat(s_dest4, s_source + 2, 3);

	char *p = strstr(s_dest4, "str");
	char *p1 = strstr(s_dest4, "rin");
	char *p2 = strstr(s_dest4, "1rin");
	char *p3 = strstr(s_dest4, "2rin");

	// конвертация чего-либо в строку
	char *s_dest5 = malloc(sizeof(char) * 30);
	int len = sprintf(s_dest5, "%d - %s + %f", 123, "string", 1.23);

	char *s_dest6 = malloc(sizeof(char) * 30);
	memcpy(s_dest6, s_dest5, 30);

	len = sprintf(s_dest5, "%d", 123);

	int i = atoi(s_dest5);
	double d = atof(s_dest5);
	long l = atol(s_dest5);
}