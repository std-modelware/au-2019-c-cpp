#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define len 100

void console() {
    FILE* file_hwr;
    char str_scanf[100];

    file_hwr = fopen("file_handle_write.txt", "w");
    scanf("%s", str_scanf);
    fprintf(file_hwr,"%s\n", str_scanf);
    fclose(file_hwr);
}

void fgetChar() {
    char c;
    FILE* file_1;
    FILE* file_2;
	if ((file_1 = fopen("file_source.txt", "r")) == NULL) {
		printf("INVALID OPEN fgetChar()\n");
		return 0;
	}
	file_2 = fopen("file_fgetc.txt", "w");


    while ((c = fgetc(file_1)) != EOF) {
		fputc(c, file_2);
	}
    fclose(file_1);
    fclose(file_2);
}

void fgetString() {
    char s[len];
    FILE* file_1;
    FILE* file_2;

	if ((file_1 = fopen("file_source.txt", "r")) == NULL) {
		printf("INVALID OPEN fgetString()\n");
		return 0;
	}
	file_2 = fopen("file_fgets.txt", "w");

	while ((fgets(s,len,file_1)) != NULL) {
        fputs(s, file_2);
	}
	fclose(file_1);
	fclose(file_2);
}

void fgetFull() {
    char s[len];
    FILE* file_1;
    FILE* file_2;
    int count;

	if ((file_1 = fopen("Engel.mp3", "rb")) == NULL) {
		printf("INVALID OPEN fgetFull()\n");
		return 0;
	}
	file_2 = fopen("file_fread.txt", "wb");

	do {
		count = fread(s, 1, len, file_1);
		fwrite(s, count, 1, file_2);
	} while (count == len);

	fclose(file_1);
	fclose(file_2);
}

int main() {
    console();
    fgetChar();
    fgetString();
    fgetFull();
}