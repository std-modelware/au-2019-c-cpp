#include "string.h"
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#define ARGS 10
#define ARGSLEN 50
#pragma warning(disable : 4996)

char str[100];
char args[ARGS][ARGSLEN];

void main() {
	char *fileName = calloc(sizeof(fileName), 100);
	int lenght = 20;
	char mode = 'n';
	int numberOfArgs = 0;

	if (fgets(str, sizeof(str), stdin) == NULL) exit(2);
	//printf("String is: %s\n", str);

	char *p = str;
	for (int i = 0; i < ARGS; i++) {
		char *nextSpace = strchr(p, ' ');
		if (nextSpace == NULL ) nextSpace = strchr(p, '\0');
		memcpy(&args[i][0], p, nextSpace - p);
		numberOfArgs++;
		if (*nextSpace == '\0') break;
		p = nextSpace + 1;
	}

	if (!strcmp(&args[0][0], "tail")) {
		for (int i = 1; i < numberOfArgs; i++) {
			if (!strcmp(&args[i][0], "-c")) { mode = 'c'; continue; }
			if (atoi(&args[i][0])) {
				lenght = atoi(&args[i][0]);
			}
		}
		fileName = &args[numberOfArgs - 1][0];
		fileName[strlen(fileName) - 1] = '\0';


		printf("readMode is: %c \n", mode);
		printf("number of strings is: %d\n", lenght);

		printf("Filename: \"%s\"\n", fileName);
		assert(fileName != NULL);

		FILE *curFile = fopen(fileName, "rb");
		if (mode == 'n') {
			assert(curFile != NULL);
			fseek(curFile, -1, SEEK_END);  
			char ch = 'a';
			for (int i = 0; i < lenght; i++) {
				ch = fgetc(curFile);
				fseek(curFile, -2, SEEK_CUR);
				while (ch != '\n') {     //start of file too
					ch = fgetc(curFile);
					//printf("%c",ch);
					fseek(curFile, -2, SEEK_CUR);
				}
			}
			fseek(curFile, 2, SEEK_CUR);
			char curStr[128];
			for (int i = 0; i < lenght; i++) {
				fgets(curStr, 128*sizeof(char), curFile);
				printf(curStr);
			}
		}
		else if (mode == 'c') {
			fseek(curFile, -lenght, SEEK_END);
			char buffer[10] = "error";
			int n = 9;
			while (n == 9) {
				n = fread(buffer, 1, 9, curFile);
				buffer[9] = '\0';
				if (n==9)
				printf(buffer);
			}
			if (n != 0) {
				buffer[n] = '\0';
				printf(buffer); 
			}
		}
		fclose(curFile);
	}

}