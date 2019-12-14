#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
//количество столбцов в бинарном выводе
#define k 10

//вывод строк
void head(int n, char* name) {
	
	FILE* f = NULL;
	char u[256];
	f = fopen(name, "r");
	if (f == NULL) return;
	int r;
	for (int i = 0; i < n; i++) {
		if (!feof(f)) {
			r = fgets(u, 256, f);
			if ((r == 256) && (u[255] != '\n')) i--;
			if (r != 0)if(i+1<10)printf("%d.   %s", i+1, u); 
			else if(i+1<100)printf("%d.  %s", i + 1, u);
			else printf("%d. %s", i + 1, u);
		}
	}
	fclose(f);
	//printf("\nEnd\n");
}

//бинарный вывод
void headb(int n, char* name) {
	int U[k];
	FILE* f = NULL;
	char u;
	int r;
	int j = 0;
	f = fopen(name, "rb");
	if (f == NULL) return;
	printf("         ");
	for (; j < k; j++) if (j < 16)printf("0%X ", j); else printf("%X ", j);
	int t = 0;
	for (int i = 0; (i < n) && (fread(&u, sizeof(char), 1, f) == 1); i++) {
		if (j == k) {

		if (t > 0) for (int p = 0; p < k; p++) if (((U[p] >= 33) && (U[p] <= 126)) || ((U[p] >= 128) && (U[p] <= 175)) || ((U[p] >= 224) && (U[p] <= 252))) {
			printf("%c", U[p]);

			}
		else printf(".");
			printf("\n");
			
			if (t < 16) printf("0000000%X ", t);
			else if(t<256) printf("000000%X ", t);
			else if(t<4096) printf("00000%X ", t);
			else if(t<65536) printf("0000%X ", t);
			else if(t<1048576) printf("000%X ", t);
			else if(t<16777216) printf("00%X ", t);
			else if(t<268435456) printf("0%X ", t);
			else printf("%x ", t);
			t = t + j;
			j = 0;
		}
		if (u < 0) r = u + 256; else r = u;
		U[j] = r;
		if (r >= 16) printf("%X ", r); else  printf("0%X ", r);
		j++;
	}
	
	for (int p = 0; p < k - j; p++) printf("   ");
	for (int p = 0; p < j; p++) if (((U[p] >= 33) && (U[p] <= 126)) || ((U[p] >= 128) && (U[p] <= 175)) || ((U[p] >= 224) && (U[p] <= 252))) {
		printf("%c", U[p]);

	}
	else { 
		printf("."); 
	}
	fclose(f); 
	//printf("\n End\n");
}

//string -> int (0..9)
int int10(char c[]) {
	int a = 0;
	int i = 0;
	while ((c[i] >= '0') && (c[i] <= '9')) {
		a = a * 10 + c[i] - '0';
		i++;
	}
	return a;
}

//string -> int (0..f)
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
 
void main(int argc, char* argv[]) {
//*setlocale(LC_ALL, "Russian");
	int a;

	if (argv[1][0] == '-') {
		if (argv[1][1] == 'n') {
			if (isdigit(argv[2][0])) {
				a = int10(argv[2]);
				head(a, argv[3]);
			}
			else {
				head(10, argv[3]);
			}

		}
		else if ((argv[1][1] == 'c')) {
			if (isdigit( argv[2][0]) ) {
				a = int10(argv[2]);
				headb(a, argv[3]);
			}
			else {
				headb(10, argv[2]);
			}
		}
	}

	printf("\n");
	//for (int i = 0; i < 256; i++) printf(" %d = %x = %c\n", i, i, i);
	

}