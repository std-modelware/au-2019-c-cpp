/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include<stdlib.h>

int sum(int n, ...)
{
	int result = 0;
	int* t = &n;
	for (int i = 0; i < n; i++)
	{
		result += *(++t);
	}
	
	return result;
}

void main()
{
	FILE *f, *d;
	char name[] = "my.txt";
	char name1[] = "cmy.txt";
	char name2[] = "smy.txt";
	char name3[] = "copmy.txt";

	// заполнение файла "my.txt"
	if ((f = fopen(name, "w")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}
	char c;
	scanf("%c", &c);
	while (c != '~') {
		fprintf(f, "%c", c);
		scanf("%c", &c);

	}
	fclose(f);

	// по символьное копирование
	if ((f = fopen(name, "r")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}
	if ((d = fopen(name1, "w")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}

	while ((c = fgetc(f)) != EOF) {
		fputc(c, d);
	}
	rewind(f);
	fclose(d);


	// по строчное копирование
	if ((d = fopen(name2, "w")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}
	char c2[128];
	while (!feof(f)) {
		if(fgets(c2, 126, f))
		fputs(c2, d);
	}
	fclose(f);
	fclose(d);

	if ((d = fopen(name3, "w")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}
	if ((f = fopen("28_09.exe", "r")) == NULL)
	{
		printf("Не удалось открыть файл f");
		getchar();
		return;
	}
	char c1[128];
	int i=128;
	while ((i == 128))
	{
		i = fread(c1, sizeof(char), 128, f);
        
		fwrite(c1, sizeof(char), i, d);
		
	}
	fclose(f);
	fclose(d);



	printf("sum(4, 1, 2, 3, 4) = %d \n", sum(4, 1, 2, 3, 4));
	printf("sum(5, 12, 21, 13, 4, 5) = %d \n", sum(5, 12, 21, 13, 4, 5));
	return 0;
}*/



#include <stdio.h>
#include "Wood.h"


void main() {
	//int key, velue;
	//scanf("%d %d", &key, &velue);
	create_root(1, 2);
	printWoods(&a);

}