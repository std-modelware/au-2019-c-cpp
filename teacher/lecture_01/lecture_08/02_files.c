#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

void main() {
	printf("file\n");

	FILE *f1;

	f1 = fopen("f1.txt", "w");

	assert(f1 != NULL);

	//char s[100];
	//scanf("%s", s);
	char *s = "TEST STRING";
	fprintf(f1, "%s\n", s);
	fclose(f1);

	// чтение
	f1 = fopen("f1.txt", "r");
	char s1[100];
	fscanf(f1, "%s", s1);
	printf("%s\n", s1);
	fclose(f1);

	// добавление в файл с обнулением
	f1 = fopen("f1.txt", "w");
	fprintf(f1, "%s\n", s);
	fprintf(f1, "%s\n", s);
	fprintf(f1, "%s\n", s);
	fprintf(f1, "%s\n", s);
	fclose(f1);

	// добавление в файл без обнулением
	f1 = fopen("f1.txt", "a");
	
	fseek(f1, 0, SEEK_END);
	
	fprintf(f1, "%s---\n", s);
	fprintf(f1, "%s--\n", s);
	fprintf(f1, "%s-\n", s);
	fclose(f1);

	// ---------------
	FILE *input = fopen("f1.txt", "r");
	FILE *output = fopen("f2.txt", "w");
	int c;
	while (1) {
		c = fgetc(input);
		if (feof(input)) {
			break;
		}
		fputc(c, output);
	}
	fclose(input);
	fclose(output);

	// ---------------
	input = fopen("f2.txt", "r");
	output = fopen("f3.txt", "w");
	char str[128];
	while (fgets(str, sizeof(str), input) != NULL) {
		fputs(str, output);
	}
	fclose(input);
	fclose(output);

	// ---------------
	input = fopen("01_memory.obj", "rb");
	output = fopen("f4.txt", "wb");
	int sz;
	do {
		sz = fread(str, sizeof(char), 128, input);
		fwrite(str, sizeof(char), sz, output);
	} while (sz == 128);
	fclose(input);
	fclose(output);
}