#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define size 300

void main() {
	FILE *fill;
	char a;
	fill = fopen("test_file.txt", "w");
	scanf("%c", &a);
	fprintf(fill, "%c", a);
	fclose(fill);
	//////////////////

	FILE *S1, *S2;
	char x;
	S1 = fopen("S1.txt", "r");
	S2 = fopen("S2.txt", "w");
	while ((x = fgetc(S1)) != EOF) {
		fputc(x, S2);
	}
	fclose(S1);
	fclose(S2);
	///////////////////////////

	FILE *S3, *S4;
	char w[size];
	S3 = fopen("S3.txt", "r");
	S4 = fopen("S4.txt", "w");
	while ((fgets(w,size,S3)) != NULL) {
		fputs(w, S4);
	}
	fclose(S3);
	fclose(S4);
	////////////////////

	FILE *S5,*S6;
	char e[size];
	int g;
	S5 = fopen("S5.txt", "r");
	S6 = fopen("S6.txt", "w");
	do {
		g = fread(e, 1, size, S5);
		fwrite(e, g, 1, S6);
	} while (g == size);
	
	fclose(S5);
	fclose(S6);
}

