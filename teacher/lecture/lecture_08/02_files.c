#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	FILE *f1;
	f1 = fopen("f1.txt", "w"); // test 123
	// записать данные в файл
	char *s = "TEST_STRING";
	int d = 123;
	//scanf("%s %d", &s[0], &d);
	fprintf(f1, "%s %d %d\n", s, d, d);
	fclose(f1);

	// чтение
	f1 = fopen("f1.txt", "r");
	char str[100];
	int d1 = 0;
	int d2 = 0;
	int f = fscanf(f1, "%s %d %d", str, &d1, &d2);
	printf("%s %d %d\n", s, d1, d2);
	fclose(f1);

	// запись в файл (с обнулением)
	f1 = fopen("f1.txt", "w");
	fprintf(f1, "%s %d %d\n", s, d1, d2);
	fprintf(f1, "%s %d %d\n", s, d1, d2);
	fclose(f1);

	// запись в файл (с обнулением)
	f1 = fopen("f1.txt", "a");
	fprintf(f1, "1%s %d %d\n", s, d1, d2);
	fprintf(f1, "2%s %d %d\n", s, d1, d2);
	fprintf(f1, "3%s %d %d\n", s, d1, d2);
	fclose(f1);


	// копирование
	FILE *fi = fopen("f1.txt", "r");
	FILE *fo = fopen("f2.txt", "w");

	int c;
	while (1) {
		c = fgetc(fi);
		if (feof(fi)) break;
		fputc(c, fo);
	}

	fclose(fi);
	fclose(fo);



	// копирование построчно
	fi = fopen("f2.txt", "r");
	fo = fopen("f3.txt", "w");

	char s1[100];
	while (fgets(s1, 100, fi) != NULL) {
		fputs(s1, fo);
	}

	fclose(fi);
	fclose(fo);

	// копирование блоками
	fi = fopen("f3.txt", "rb");
	fo = fopen("f4.txt", "wb");
	int sz;
	do {
		sz = fread(s1, sizeof(char), 100, fi);
		fwrite(s1, sizeof(char), sz, fo);
	} while (sz == 100);
	fclose(fi);
	fclose(fo);

}