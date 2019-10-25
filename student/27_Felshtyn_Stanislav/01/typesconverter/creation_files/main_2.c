#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int value;
void Creation_newFile() {
	FILE* new;
	switch (value) {
	case 1:
		if (value == 1) {
			new = fopen("new.txt", "w");
			fprintf(new, "Hello, my name is Bob! (CHAR_COPY)\n");
			fclose(new);
		}
	case 2:
		if (value == 2) {
			new = fopen("new.txt", "w");
			fprintf(new, "We need to copy the line now (STRING_COPY)\n");
			fclose(new);
		}
	case 3:
		if (value == 3) {
			new = fopen("new.txt", "w");
			fprintf(new, "We copied the entire file (FULL_COPY)\n");
			fclose(new);
		}
	}
}

void CopyFile_char() {
	value = 1;
	char ch;
	FILE* copy;
	FILE* new;
	Creation_newFile();
	new = fopen("new.txt", "r");
	copy = fopen("copy.txt", "w");
	do {
		ch = fgetc(new);
		if (feof(new)) {
			break;
		}
		fputc(ch, copy);
	} while (ch != EOF);
	fclose(new);
	fclose(copy);
}

void CopyFile_string() {
	value = 2;
	char ch[42];
	FILE* copy;
	FILE* new;
	Creation_newFile();
	new = fopen("new.txt", "r");
	copy = fopen("copy.txt", "w");
	while (fgets(ch, sizeof(ch), new) != NULL) {
		if (feof(new)) {
			break;
		}
		fputs(ch, copy);
	}
	fclose(new);
	fclose(copy);
}

void CopyFile_full() {
	value = 3;
	char ch[37];
	FILE* copy;
	FILE* new;
	Creation_newFile();
	new = fopen("new.txt", "r");
	copy = fopen("copy.txt", "w");
	fread(&ch, sizeof(ch), 1, new);
	fwrite(&ch, sizeof(ch), 1, copy);
	fclose(new);
	fclose(copy);
}

int main()
{	
	int c;
	printf("Please, choose the function.\n");
	scanf_s("%d", &c);
	switch (c) {
	case 1:
		if (c == 1) CopyFile_char();
	case 2:
		if (c == 2) CopyFile_string();
	case 3:
		if (c == 3) CopyFile_full();
	}
	printf("Look at the file\n");
 return 0;
}