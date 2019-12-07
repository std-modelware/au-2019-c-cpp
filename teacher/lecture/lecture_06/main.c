#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {
	printf("string\n");

	// копирование строк
	char *s_src = "string 1";
	char s[] = "string 1";

	char *s_dest1 = (char *) malloc(sizeof(char) * strlen(s_src));
	strcpy(s_dest1, s_src);

	char *s_dest2 = (char *)malloc(sizeof(char) * strlen(s_src));
	strncpy(s_dest2, s_src, 3);

	char *s_dest3 = (char *)malloc(sizeof(char) * strlen(s_src) * 2);
	strcpy(s_dest3, s_src);
	strcat(s_dest3, s_src);

	char *s_dest4 = (char *)malloc(sizeof(char) * strlen(s_src) * 2);
	strcpy(s_dest4, s_src);
	strncat(s_dest4, s_src + 2, 3);

	char *p = strstr(s_dest4, "str");
	char *p1 = strstr(s_dest4, "rin");
	char *p2 = strstr(s_dest4, "1rin");
	char *p3 = strstr(s_dest4, "2rin");

	// конвертация чего-либо в строку
	char *s_dest5 = (char *)malloc(sizeof(char) * 30);
	int x = sprintf(s_dest5, "%d - %s + %c", 12, "rrrrrr1", 'z');

	char *s_dest6 = (char *)malloc(sizeof(char) * 30);
	memcpy(s_dest6, s_dest5, 10);

	int i = atoi("123");
	double d = atof("1.234");
	long l = atoi("111233");

	
}