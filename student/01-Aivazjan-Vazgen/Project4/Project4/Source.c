#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void head(int n);
void headb(int n);


void main() {
	setlocale(LC_ALL, "Russian");///подключение русского языка
	int a = 1;
	char spokidoki[512];///длина строчки,которая бцдет выводиться(head...)
	char spokidoki1[512];///длина строчки,которая бцдет выводиться(head...)

	char spokidoki3[512];///длина строчки,которая бцдет выводиться(head...)

	scanf("%s %s", spokidoki, spokidoki1);

	if (!((spokidoki[0] == 'h') && (spokidoki[1] == 'e') && (spokidoki[2] == 'a') && (spokidoki[3] == 'd') && (spokidoki1[0] == '-')));
	else if ((spokidoki1[1] == 'n')) {
		scanf("%d %s", &a, spokidoki3);
		head(a, spokidoki3);
	}
	else if ((spokidoki1[1] == 'c')) {
		scanf("%x %s", &a, spokidoki3);
		headb(a, spokidoki3);
	}

}

void head(int n, char* assgard) {

	FILE* katya888 = NULL;
	//char* assgard = (char*)malloc(256); ///предельный размер строки
	char u;
	/*printf("ВВВВедите имечко,расположейничко файличка\n");
	scanf("%s", assgard); ///читаем строку
	katya888 = fopen(assgard, "r"); ///открываем файл на чтение
	while (katya888 == NULL) {///если после выполнения,все еще не открылся файл,то прблемсы
	printf("Не удалось открыть файл\n");
	printf("ВВВВедите имечко файличка\n");
	scanf("%s", assgard); ///читаем строку
	katya888 = fopen(assgard, "r"); ///открываем файл на чтение

	}*/
	katya888 = fopen(assgard, "r"); ///открываем файл на чтение
	for (int i = 0; i < n; i++) {///столько сколько и кол-во строк проходим раз
		u = 'a';
		while (!((u == '\n') || (u == EOF))) {///проверка на конец файла
			if (!feof(katya888)) {///ну что б точно конец файла
				fscanf(katya888, "%c", &u);
				printf("%c", u);
			}
		}
	}
	fclose(katya888);
	printf("\nHappy Endиком\n");
}
void headb(int n, char* assgard) {

	FILE* katya888 = NULL;
	//char* assgard = (char*)malloc(256); ///предельный размер строки
	char u = 'a';
	/*printf("ВВВВедите имечко,расположейничко файличка\n");
	scanf("%s", assgard); ///читаем строку
	katya888 = fopen(assgard, "r"); ///открываем файл на чтение
	while (katya888 == NULL) {///если после выполнения,все еще не открылся файл,то прблемсы
	printf("Не удалось открыть файл\n");
	printf("ВВВВедите имечко файличка\n");
	scanf("%s", assgard); ///читаем строку
	katya888 = fopen(assgard, "r"); ///открываем файл на чтение

	}*/
	katya888 = fopen(assgard, "rb"); ///открываем файл на чтение
	for (int i = 0; (i < n) && (u != EOF); i++) {///столько сколько и кол-во строк проходим раз
		if (!feof(katya888)) {///ну что б точно конец файла
			fscanf(katya888, "%c", &u);
			printf("%x ", u);
		}
	}
	fclose(katya888);
	printf("\nHappy Endиком\n");
}