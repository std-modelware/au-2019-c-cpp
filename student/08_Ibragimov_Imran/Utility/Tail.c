#include "string.h"
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <ctype.h>
#pragma warning(disable : 4996)

void main(int argc, char* argv[]) {
	int lenght = 20;
	char mode = 'n';

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-c")) { mode = 'c'; continue; }
		if (atoi(argv[i])) {
			lenght = atoi(argv[i]);
		}
	}

	assert(argv[argc - 1] != NULL);
	FILE *curFile = fopen(argv[argc - 1], "rb");

	if (mode == 'n') {
		int count = 1;
		int stringCount = 0;
		long startPos = ftell(curFile);
		assert(curFile != NULL);
		fseek(curFile, -1, SEEK_END);  
		char ch = 'a';

		for (int i = 0; (i < lenght) && (ftell(curFile) != 0); i++) {
			ch = fgetc(curFile);
			fseek(curFile, -2, SEEK_CUR);

			while (ch != '\n') {  
				ch = fgetc(curFile);
				fseek(curFile, -1, SEEK_CUR);
				if (ftell(curFile) == 0) break;
				fseek(curFile, -1, SEEK_CUR);

			}
			stringCount++;
		}

		char curStr[128];

		for (int i = 0; i < stringCount; i++) {
			fgets(curStr, 128*sizeof(char), curFile);
			printf("%d. %s", count, curStr);
			count++;
		}
	}
	else if (mode == 'c') {
		fseek(curFile, -lenght, SEEK_END);
		char buffer[18] = "error";
		printf("          00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
		int n = 16;
		int offset = 0;
		while (n == 16) {
			n = fread(buffer, 1, 16, curFile);
			printf("%08X  ", offset);
			offset = offset + 16;

			for (int i = 0; i < n; i++) {;
				printf("%02X ", buffer[i]);
			}

			if (n < 16) {
				for (int i = 0; i < 16-n; i++) {
					printf("   ");
				}
			}

			printf("             ");
			for (int j = 0; j < n; j++) {
				if (isprint(buffer[j]) != 0 && isspace(buffer[j]) == 0)
					printf("%c", buffer[j]);
				else printf(".");
			}
			printf("\n");
		}
	}
	fclose(curFile);
}
