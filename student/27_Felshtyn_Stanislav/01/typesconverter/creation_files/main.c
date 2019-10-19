#include <stdio.h>
#include <stdlib.h>

void Creation_newFile() {
	FILE* new;
	//system("chcp 1251");
	//system("cls");
	new = fopen("new.txt", "w");
	fprintf(new, "Hello, my name is Bob!\n");
	fclose(new);
}

void CopyFile_char() {
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
	char ch[22];
	FILE* copy;
	FILE* new;
	Creation_newFile();
	new = fopen("new.txt", "r");
	copy = fopen("copy.txt", "w");
	
	fclose(new);
	fclose(copy);
}

void CopyFile_full() {

}

int main()
{	
	//CopyFile_char();
	CopyFile_string();
	//CopyFile_full();
	//char c;
	//printf("Please, choose function.\n");
	//scanf_s("%c", &c);

	return 0;
}