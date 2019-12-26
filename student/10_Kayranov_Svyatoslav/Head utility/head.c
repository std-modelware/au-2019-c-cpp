#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 100

int digits;
char c;
char utilityName[LEN];
char fileName[LEN];
char option[LEN];
char str[LEN];
char syntax[] = { "	Avaliable syntax: \nhead -n 20 filename.txt - line-by-line reading \nhead -c 20 filename.txt - byte-by-byte reading" };
bool flag = 0;

/*
♔ Модуль считывания команд ♔
Доступный синтаксис:
	head -n 20 filename.txt - построчное считывание
	head -с 20 filename.txt - побайтовое считывание
*/

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

void check(int argc, char* argv[]) {
	char digitss[LEN];

	if (argc != 4) {
		printf("Invalid amount of arguments.\n");
		printf(syntax);
		exit(EXIT_FAILURE);
	}

	copy(option, argv[1]);
	copy(digitss, argv[2]);
	copy(fileName, argv[3]);

	if (strncmp(option, "-n", 2) && strncmp(option, "-c", 2)) {
		printf("%s'%s'\n", "head: invalid operation ", option);
		printf(syntax);
		exit(EXIT_FAILURE);
	}
	else {
		if (fileName == NULL) {
			copy(fileName, argv[2]);
			digits = 10;
		}
		else {
			digits = atoi(digitss);
		}
		if (!exists(fileName)) {
			printf("%s'%s'%s\n", "head: cannot open ", fileName, " for reading: No such file or directory");
			printf(syntax);
			exit(EXIT_FAILURE);
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
	return(EXIT_FAILURE);
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
		char c = 0;
		int count = 0;
		FILE* file;
		file = fopen(fileName, "rb");

		for (count = 0; count < digits; count++) {
			if (c != EOF) {
				printf("(%d) ", count + 1);
			}
			while (1) {
				c = getc(file);
				if ((c == '\n') || (c == EOF))  break;
				printf("%c", c);
			}
			if (c != EOF) {
				printf("\n");
			}
		}
		fclose(file);
	}

	// проверка если выбрана опция -с
	else {
		int c, str1[16];
		int count, strings = 0;
		int offset = 0;
		int counter = 0;
		int endOfFile = 0;
		FILE* file;
		file = fopen(fileName, "rb");

		int dig = digits;

		do {
			strings++;
			dig = dig - 16;
		} while (dig > 0);
		
		printf("           00 01 02 03  04 05 06 07  08 09 0A 0B  0C 0D 0E 0F\n");
		for (int i = 0; i < strings; i++) {
			printf("%08X  ", offset);
			offset = offset + 16;
			for (count = 0; count < 16; count++) {
				counter++;
				if (count % 4 == 0) printf(" ");
				c = getc(file);

				strcpy(str, binToHex(c));
				if (((count >= digits) || (c == EOF) || (counter > digits)) && (c != 255)) {
					str1[count] = ' ';
					printf(".. ");
					if ((counter % 16) == 0) {
						endOfFile = 1;
					}
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
			if (endOfFile == 1) return 0;
		}
		fclose(file);
	}
}

int main(int argc, char *argv[]) {
//	readString();
	check(argc, argv);
	Option();
	return 0;
}


/*
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

void check(int argc, char* argv[]) {
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
} */