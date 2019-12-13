#define _CRT_SECURE_NO_WARNINGS
#include "./struct.h"
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#define size 300

int count_lines(char *S3find) {
	setlocale(LC_ALL, "Russian");
	int k = 0;
	FILE *S3;
	char w[size];
	S3 = fopen(S3find, "r");
	while ((fgets(w, size, S3))!= NULL) {
		k++;
	}
	fclose(S3);
	return k;
}

void print_lines(int n,int k) {
	FILE *S3;
	char w[size];
	S3 = fopen("S3.txt", "r");
	for (int i =1; i <=k-n ; i++){
		fgets(w, size, S3);
		
	}
	
	for (int i = k - n + 1; i <= k; i++) {
		fgets(w, size, S3);
		printf("%s", w);
	}
	fclose(S3);
}

int count_bites(char *S3find) {
	setlocale(LC_ALL, "Russian");
	int b = 0;
	FILE *S3;
	char w;
	S3 = fopen("S3.txt", "rb");
	while ((fread(&w, sizeof(char),1, S3)) == 1) {
		b++;
	}
	fclose(S3);
	return b;
}

char* translate(char w) {
	char*c = (char*)malloc(sizeof(char) * 2);
	sprintf(c, "%0.2hhX", w);
	return c;
}


void print_bites(int a, int b) {
	setlocale(LC_ALL, "Russian");
	FILE *S3;
	char w;
	S3 = fopen("S3.txt", "rb");
	int t = 0;
	fseek(S3, -a, SEEK_END);
	/*for (int h = 0; h < 16; h++) {
		char r=
		printf("%c%c ", "0",)
	}*/
	char mas[16] = "";

	for (int i = b - a + 1; i <= b; i++) {
		int end;
		end = fread(&w, sizeof(char), 1, S3);
		if (end == 0) { break; }
		int k = (int)w;
		if (k <= 255 && k >= 0) { mas[t] = w; }
		else { mas[t] = '.'; }
		char* c = translate(w);
		printf("%s ", c);
		t++;
		if (t == 16) {
			for (int j = 0; j < 16; j++) {
				printf("%c", mas[j]);
			}
			printf("\n"); t = 0; }

	}
	if (t != 16) {
		for (int j = 0; j < 16; j++) {
			printf("%c", mas[j]);
		}
	}

	fclose(S3);
}



