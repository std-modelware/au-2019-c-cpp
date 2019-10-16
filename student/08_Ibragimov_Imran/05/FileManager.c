//#include "stdio.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h> 

void PrintHelp();
void PrintSelectionMenu(int ind);
void GetNewStr();
FILE* files[5];
char str[80] = "THIS IS WRONG STRING";

void main() {
	int printing = 0;
	int index = 1;
	char strBufer[20][80];
	char charBuf[100];
	char wholeBuf[1600];

	PrintHelp();
	GetNewStr();

	while (strcmp(str, "-exit\n") != 0) {			
			if (strcmp(str, "-create\n") == 0) {
				char cBuffer[40] = "MyFile";
				printf("Enter file index from 0 to 4: \n");
				
				char buf[2];
				if (fgets(buf, sizeof(buf), stdin) != NULL) {
					index = atoi(buf);
				}

				char indx[4];
				indx[0] = index + '0';
				indx[1] = '\0';
				strcat_s(cBuffer, 40, indx);
				strcat_s(cBuffer, 40, ".txt");
				fopen_s(&files[index], cBuffer, "w+");
				fclose(files[index]);
			}
			if (strcmp(str, "-select\n") == 0) {
				index = -1;
				while (index == -1) {
					printf("Enter file index from 0 to 4: \n");
					scanf_s("%d", &index);
					if (files[index] == NULL) {
						printf("Wrong index, try again \n");
						index = -1;
					}
				}
				PrintSelectionMenu(index);

				char fileName[40] = "MyFile";
				char indx[4];
				indx[0] = index + '0';
				indx[1] = '\0';
				strcat_s(fileName, 40, indx);
				strcat_s(fileName, 40, ".txt");
				GetNewStr();

				while (strcmp(str, "-exit\n") != 0) {
					if (strcmp(str, "-print\n") == 0) {
						GetNewStr();

						if(fopen_s(&files[index], fileName, "a") != 0) exit(3);
						while (strcmp(str, "-exit\n") != 0) {
							fprintf(files[index], "%s", str);
							GetNewStr();
						}
						fclose(files[index]);
						PrintSelectionMenu(index);
					}
					if (strcmp(str, "-copyc\n") == 0) {
						int startChar, count;
						printf("Enter number of starting char and lenght of copy zone: \n");
						scanf_s("%d %d", &startChar, &count); //error check is needed

						FILE * curFile = files[index];
						int currentCount = 0;
						if (fopen_s(&curFile, fileName, "r") != 0) exit(3);
						do
						{
							// Taking input single character at a time 
							currentCount++;
							char c = fgetc(curFile);
							if (currentCount >= startChar) {
								charBuf[currentCount - startChar] = c;
							}
							
							if ((currentCount - startChar) == count) { 
								charBuf[currentCount - startChar + 1] = '\0';
								break;
							}
							// Checking for end of file 
							if (feof(curFile)) {
								charBuf[currentCount - startChar + 1] = '\0';
								break;
							}

						} while (1);
						printf("Copy buffer: %s \n", charBuf);

						fclose(curFile);
						PrintSelectionMenu(index);
					}
					if (strcmp(str, "-pastec\n") == 0) {
						//emtiness of buffer need to be checked
						FILE * curFile = files[index];
						if (fopen_s(&curFile, fileName, "r+") != 0) exit(3);
						int startChar;
						printf("Enter number of char (-1 to paste at the end): \n");
						scanf_s("%d", &startChar); //error check is needed
						if (startChar < 0) fprintf(files[index], "%s", charBuf);
						else {
							fseek(curFile, startChar, SEEK_SET);
							for (int i = 0; charBuf[i] != '\0'; i++)
								fputc(charBuf[i], curFile);
							fclose(curFile);
							PrintSelectionMenu(index);
						}
					}
					if (strcmp(str, "-copys\n") == 0) {
						int startChar, count;

						for (int i = 0; i < 20;i++) { //Wipe previous buffer
							strBufer[i][0] = '\0';
						}

						printf("Enter number of starting string and how many strings to copy: \n");
						scanf_s("%d %d", &startChar, &count); //error check is needed

						FILE * curFile = files[index];
						char ch[80] = "trash";
						if (fopen_s(&curFile, fileName, "r") != 0) exit(3);
						for (int i = 0; i < startChar; i++) {
							fgets(ch, 80, curFile);
							if (feof(curFile)) {
								break;
							}
						}

						for (int i = 0; i < count; i++) {
							fgets(strBufer[i], 80, curFile);
							// Checking for end of file 
							if (feof(curFile)) {
								break;
							}
						}
						printf("Copy buffer: \n");
						for (int i = 0; i < count; i++) {
							printf("%s", strBufer[i]);
						}

						fclose(curFile);
						PrintSelectionMenu(index);
					}
					if (strcmp(str, "-pastes\n") == 0) {
						FILE * curFile = files[index];
						if (fopen_s(&curFile, fileName, "r+") != 0) exit(3);
						int startChar;
						printf("Enter number of string (-1 to paste at the end): \n");
						scanf_s("%d", &startChar); //error check is needed
						if (startChar < 0) {
							int i = 0;
							while (strBufer[i][0] != '\0') {
								fprintf(curFile, "%s", strBufer[i]);
								i++;
							}
							fclose(curFile);
							PrintSelectionMenu(index);
						}
						else {
							int charcount = 0;
							char ch[80] = "trash";
							for (int i = 0; i < startChar; i++) {
								fgets(ch, 80, curFile);
								charcount += strlen(ch);
								if (feof(curFile)) {
									exit(10);
								}
							}
							fclose(curFile);
							if (fopen_s(&curFile, fileName, "r+") != 0) exit(3);
							fseek(curFile, charcount, SEEK_SET);
							fputc('\n', curFile);
							for (int i = 0; (strBufer[i][0] != '\0' && i<20); i++)
								fputs(strBufer[i], curFile);
							fclose(curFile);
							PrintSelectionMenu(index);
						}
					}
					if (strcmp(str, "-copyw\n") == 0) {
						wholeBuf[0] = '\0';
						if (fopen_s(&files[index], fileName, "r") != 0) exit(3);
						int sz = 0;
						char c;
						for (c = getc(files[index]); c != EOF; c = getc(files[index]))
							sz++;
						rewind(files[index]);
						fread(wholeBuf, sz, 1, files[index]);
						wholeBuf[sz] = '\0';
						rewind(files[index]);
						fclose(files[index]);
						PrintSelectionMenu(index);
						printf(wholeBuf);
					}
					if (strcmp(str, "-pastew\n") == 0) {
						if (fopen_s(&files[index], fileName, "r+") != 0) exit(3);
						fseek(files[index], 0, SEEK_END);
						//fprintf(files[index], "\n");
						fprintf(files[index], wholeBuf);
						fclose(files[index]);
						PrintSelectionMenu(index);
					}

					GetNewStr();
				}
			}
			PrintHelp();
			GetNewStr();
	}
}

	void PrintHelp() {
		printf("Current session files id's: ");
		for (int i = 0; i < 5; i++)
			if (files[i] != NULL) printf(" %d" , i);
		printf("\n");
		printf("\"-create\" to create new \n");
		printf("\"-select\" to select created file \n");
		printf("\"-exit\" to exit program \n \n");
	}
	
	void PrintSelectionMenu(int ind) {
		printf("You are selecting MyFile%d. \n", ind);
		printf("\"-print\" to start printing in current file \n");
		printf("\"-copyc\" and \"-pastec\" to copy and paste by char \n");
		printf("\"-copys\" and \"-pastes\" to copy and paste by string \n");
		printf("\"-copyw\" and \"-pastew\" to copy and paste whole text in file \n");
		printf("\"-exit\" to exit select mode \n");
	}

	void GetNewStr() {
		fseek(stdin, 0, SEEK_END);
		if (fgets(str, sizeof(str), stdin) == NULL) exit(2);
	}
