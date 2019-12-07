#include <stdio.h>
#define size 1
/*
scanf()
%с	Считать один символ
%d	Считать десятичное число целого типа
%i	Считать десятичное число целого типа
%е	Считать число с плавающей запятой
%f	Считать число с плавающей запятой
%g	Считать число с плавающей запятой
%о	Считать восьмеричное число
%s	Считать строку
%х	Считать шестнадцатиричное число
%р	Считать указатель
%n	Принимает целое значение, равное количеству считанных до текущего момента символов
%u	Считывает беззнаковое целое
%[]	Просматривает набор символов
%%	Считывает символ %
%*s - Игнорирование во время считывания

*/

int main() {

	// r - read (чтение существующего файла)
	// w - write (запись в существующий (перезапись) или в новый)
	// a - add (добавление текста в сущ. файл или создание нового)
	// режимы + только в .txt
	// r+ - на чтение и запись (сущ. файл)
	// w+ - на чтение и запись пустого файла
	// a+ - на чтение и дозапись
	// rb, wb - бинарный файл
	FILE *filein, *fileoutc, *fileouts, *fileoutf;

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileoutc = fopen("fileoutc.txt", "w");
		if (fileoutc != NULL) {
			printf("Symbol copying...\n");
			char k = fgetc(filein);
			while (k != EOF) {
				fputc(k, fileoutc);
				k = fgetc(filein);
			}
			printf("Complited!\n");
			fclose(fileoutc);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileouts = fopen("fileouts.txt", "w");
		if (fileouts != NULL) {
			printf("String copying...\n");
			char b[100];
			while (fgets(b, 100, filein)) {
				fputs(b, fileouts);
				b[100];
			}
			printf("Complited!\n");
			fclose(fileouts);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileoutf = fopen("fileoutf.txt", "w");
		if (fileoutf != NULL) {
			printf("Text copying...\n");
			char d[size];
			int k;
			do {
				k = fread(d, sizeof(char), size, filein);
				fwrite(d, k, sizeof(char), fileoutf);

			} while (k == size);

			printf("Complited!\n");
			fclose(fileoutf);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}
}
