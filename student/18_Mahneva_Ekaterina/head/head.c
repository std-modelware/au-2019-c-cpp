#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define k 10 

void head(int n);
void headb(int n);
int int10(char c[]);
int int16(char c[]);

void main(int argc,char*argv[]) {
	setlocale(LC_ALL, "Russian");
	int a=1;
	
	if ((argv[1][0] == 'n')) {
		a = int10(argv[2]);
		head(a, argv[3]); }
	if ((argv[1][0]=='c')) {
		a = int10(argv[2]);
		headb(a, argv[3]);
	}
	
}

void head(int n, char* assgard) {

	FILE* katya888 = NULL;
	char u[256];
	katya888 = fopen(assgard, "r"); 
	if (katya888 == NULL) {
		printf("Не удалося"); 
		return;
	}
	int r; 
	for (int i = 0; i < n; i++) {
		if (!feof(katya888)) {
			r = fgets(u, 256, katya888);
			if ((r == 256) && (u[255] != '\n')) i--;
			if (r != 0) 
		   if (i+1<10)
				printf("  %d. %s",i+1, u);
		   else if (i+1<100) 
			   printf(" %d. %s", i + 1, u);
		   else printf("%d. %s", i + 1, u);
			
		}
	}
	fclose(katya888);
	printf("\nHappy Endиком\n");
}
void headb(int n, char* assgard) {
	int U[k];
	FILE* katya888 = NULL;
	char u;
	int r;
	katya888 = fopen(assgard, "rb"); 
	if (katya888 == NULL) {
		printf("Не удалосоя"); return;
	}
	printf("         ");
	int g = 0;
	for (; g < k; g++) if (g < 16)
		printf("0%X ", g);
	else printf("%X", g);
	int t=0;
	for (int i = 0; (i<n)&& (fread(&u, sizeof(char), 1, katya888) == 1) ; i++) {
		if (g == k) { 
			if (t > 0) for (int p = 0; p < k; p++) if (((U[p] >= 33) && (U[p] <= 126)) || ((U[p] >= 128) && (U[p] <= 175)) || ((U[p] >= 224) && (U[p] <= 252))) {
				printf("%c", U[p]);

			}
			else printf("..");
			printf("\n");
			if (t < 16) printf("0000000%X ", t);
			else if (t < 256) printf("000000%X ", t);
			else if (t < 4096) printf("00000%X ", t);
			else if (t < 65536) printf("0000%X ", t);
			else if (t < 1048576) printf("000%X ", t);
			else if (t < 16777216) printf("00%X ", t);
			else if (t < 268435456) printf("0%X ", t);

			else printf("%X ", t);
			t = t + g;
			g = 0;

		}
		if (u < 0) r = u + 256; else r = u; 
		U[g] = r;
		if (r >= 16) printf("%X ", r); else printf("0%X ", r);
			g++;
	}
	for (int p = 0; p < k - g; p++) printf("   ");
	for (int p = 0; p < g; p++) if (((U[p] >= 33) && (U[p] <= 126)) || ((U[p] >= 128) && (U[p] <= 175)) || ((U[p] >= 224) && (U[p] <= 252))) {///если не конец реальной строки 
		printf("%c", U[p]);

	}
	else {
		printf(".");
	}
	fclose(katya888);
	printf("\nHappy Endиком\n");
}
int int10(char c[]) {
	int a = 0;
	int i = 0;
	while ((c[i] >= '0') && (c[i] <= '9')) {
		a = a * 10 + c[i] - '0';
		i++;
	}
	return a;
}
int int16(char c[]) {
	int a = 0;
	int i = 0;
	while (((c[i] >= '0') && (c[i] <= '9')) || ((c[i] >= 'a') && (c[i] <= 'f'))) {
		if ((c[i] >= '0') && (c[i] <= '9')) a = a * 16 + c[i] - '0';
		else a = a * 16 + c[i] - 'a' + 10; 
		i++;
	}
	return a;
}