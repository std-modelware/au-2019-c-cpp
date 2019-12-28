#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int Get_TextCode(char* file_name[]);
int Count_Symbol(char* file_name[]);
int Count_String(char* file_name[]);
int Count_Words(char* file_name[]);
int Count_Byte(char* file_name[]);
int MaxSize_String(char* file_name[]);
int ISLetter(char c);

int main(int argc, char *argv[]) {
	int key;
	key = 1;
	
	char* file_name;	
	file_name = "example3.txt";

	for (int i = 0; i < argc; i++) {
		printf("Argument %d: %s\n", i, argv[i]); 
	}
	//printf("%d", argc);
	if (argc < 3) {
		printf("Command line has no additional arguments\n");
		printf("%c", argc);
	}
	//printf(" %s", argv[1]);
	if (argc == 3) {
		if (strcmp(argv[1], "-l") == 0) key = 1;
		if (strcmp(argv[1], "-c") == 0) key = 2;
		if (strcmp(argv[1], "-m") == 0) key = 3;
		if (strcmp(argv[1], "-L") == 0) key = 4;
		if (strcmp(argv[1], "-w") == 0) key = 5;
		file_name = argv[2];

		//printf("%c", key);
	}
	else printf("It is too much arguments. Enter 3 arguments.\n");

	if (Get_TextCode(file_name) == 1) {
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);			// установка русской кодировки
	}
	/*
	 wc -l <filename> вывести количество строк
	 wc -c <filename> вывести количество байт
	 wc -m <filename> вывести количество символов
	 wc -L <filename> вывести длину самой длинной строки
	 wc -w <filename> вывести количество слов
	*/
	switch (key) {

	case 1: 
		{
			Count_String(file_name);
			break;
		}
	case 2:
		{
			Count_Symbol(file_name);
			Count_Byte(file_name);
			break;
		}
	case 3:
		{
			Count_Symbol(file_name);
			break;
		}
	case 4:
		{
			MaxSize_String(file_name);
			break;
		}
	case 5:
		{
			Count_Words(file_name);
			break;
		}
	}
	return 0;
}

int Count_Symbol(char* file_name[]) {
	int s = 0;
	int count = 0;
	unsigned char c;
	FILE* file;
	file = fopen(file_name, "r");
	
	while (!feof(file)) {
		c = fgetc(file);
		count++;
		if (c == ' ') s++; //' '
	}
	printf("%d %d\n", count, s); //+ EOF char
	fclose(file);
	return 0;
}

int Count_String(char* file_name[]) {
	unsigned char c;
	int count = 0;
	FILE* file;
	file = fopen(file_name, "r");
	while (!feof(file)) {
		c = fgetc(file);
		if (c == '\n') count++;
	}
	printf("%d\n", count+1); //+ EOF char
	fclose(file);
	return 0;
}

int Count_Words(char* file_name[]) {
	unsigned char c;
	int count = 0;
	int flg = 0;

	FILE* file;
	file = fopen(file_name, "r");
	
	while (!feof(file)) {
		c = fgetc(file);
		if (ISLetter(c) == 1) {
			if (flg == 0) {
				count++;
				flg = 1;
			}
			continue;
		}
		else {
				if (c == '-') {
				if (feof(file)) break;
				c = fgetc(file);
				if (ISLetter(c) == 1) continue;
				else if (c == '\n') {
						if (feof(file)) break;
						c = fgetc(file);
						if (ISLetter(c) == 1) continue;
					}
				}
			flg = 0;

		}
	}
	printf("%d\n", count);
	fclose(file);
	return 0;
}

int Count_Byte(char* file_name[]) {
	//fopen(file_name, "r");
	return 0;
}

int Count_Words_UTF8(char* file_name[]) {
	unsigned char c;
	int count = 0;
	int flg = 0;

	FILE* file;
	file = fopen(file_name, "r");

	while (!feof(file)) {
		c = fgetc(file);
		if (ISLetter(c) == 1) {
			if (flg == 0) {
				count++;
				flg = 1;
			}
			continue;
		}
		else {
			if (c == '-') {
				if (feof(file)) break;
				c = fgetc(file);
				if (ISLetter(c) == 1) continue;
				else if (c == '\n') {
					if (feof(file)) break;
					c = fgetc(file);
					if (ISLetter(c) == 1) continue;
				}
			}
			flg = 0;

		}
	}
	printf("%d\n", count);
	fclose(file);
	return 0;
}

int MaxSize_String(char* file_name[]) {
	char c;
	int max = 0;
	int temp = 0;
	FILE* file;
	file = fopen(file_name, "r");

	while (!feof(file)) {
		c = fgetc(file);
		if (c == '\n') {
			if (temp > max) {
				max = temp;
			}
			temp = 0;
			continue;
		}
		temp++;
	}
	printf("%d\n", max); //+ EOF char
	fclose(file);
	return 0;
}

int ISLetter(char c) {
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) {
		return 1; //&& (!EOF) && (!'\n')
	}
	else return 0;
}

int Get_TextCode(char *file_name[]) {			// Маркер последовательности байтов
	unsigned char c[3];
	int flgresult=0;
	FILE* file;
	file = fopen(file_name, "r");

	for (int i = 0; i <= 2; i++) {
		c[i] = fgetc(file);
		if (feof(file)) break;
	}
	if ((c[0] == 0xEF) && (c[1] == 0xBB) && (c[2] == 0xBF)) { 
		printf("Coding page UTF-8\n");	
		flgresult = 1; // UTF-8
	} 
	else { 
		flgresult = 0; 
		printf("Coding page is not UTF-8\n"); 
	}
	fclose(file);
	return flgresult;
}