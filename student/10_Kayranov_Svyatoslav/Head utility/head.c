#define _CRT_SECURE_NO_WARNINGS
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

void readString() {
	scanf("%s%s", utilityName, option);

	if (strncmp(option, "-", 1)) {
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
	printf("Read: (%s) (%s) (%d) (%s)\n", utilityName, option, digits, fileName);
}

void check() {
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

char digit(int num)
{
	switch (num) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	}
}

int binToHex(b) {
	int h0 = 0;
	int h1 = 0;
	if (b > 0) {
		h1 = b % 16;
		if (b > 15) h0 = b / 16 % 16;
		else h0 = 0;
	}
	char str[2] = { digit(h0), digit(h1) };
	return str;
}

void Option() {
	if (!(strncmp(option, "-n", 2))) {
		char c;
		int count = 0;
		FILE* file;
		file = fopen(fileName, "rb");

		for (count = 0; count < digits; count++) {
			printf("(%d) ", count + 1);
			while (1) {
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
		char c, str1[16];
		int count, strings = 0;
		FILE* file;
		file = fopen(fileName, "rb");

		int dig = digits;

		do {
			strings++;
			dig = dig - 16;
		} while (dig > 0);
		
		printf("      00 01 02 03  04 05 06 07  08 09 0A 0B  0C 0D 0E 0F\n");

		for (int i = 0; i < strings; i++) {
			printf("%4d ", i);
			for (count = 0; count < 16; count++) {
				if (count % 4 == 0) printf(" ");
				c = getc(file);

				strcpy(str, binToHex((int)c));
				if ((count >= digits ) || (c == EOF)) {
					str1[count] = ' ';
					printf(".. ");
				}
				else {
					str1[count] = c;
					printf("%c%c ", str[0], str[1]);
				}
			}
			printf(" | ");
			for (int l = 0; l < 16; l++) {
				if ((str1[l] == '\n') || str1[l] == '\r') printf(" ");
				else {
					if ((str1[l] == NULL) || (str1[l] == 'М')) printf(" ");
					else printf("%c", str1[l]);
				}
			}
			printf("\n");
		}
		fclose(file);
	}
}

int main(void) {
	readString();
	check();
	Option();
}