#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "dirent.h"
#include <Windows.h>
#include <string.h>

void ListAllDirs(char path[260], int tab) {
	struct dirent* de;  // Pointer for directory entry 
	DIR* dr = opendir(path);

	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		return;
	}

	while ((de = readdir(dr)) != NULL) {
		if (strcmp(de->d_name, ".") && strcmp(de->d_name, "..") && strchr(de->d_name, '.') == NULL) {
			AnsiToOem(de->d_name, de->d_name);
			if (tab != 0) {
				for (int i = 0; i < tab; i++)
				{
					printf("\t");
				}
				printf("->");
			}
			printf("%s\n", de->d_name);
			if (strchr(de->d_name, '.') == NULL) {
				char newpath[260];
				strcpy(newpath, path);
				strcat(newpath, "\\");
				strcat(newpath, de->d_name);
				ListAllDirs(newpath, tab + 1);
			}
		}
	}
	closedir(dr);
}

int main(void)
{
	struct dirent* de;  // Pointer for directory entry 
	char path[260];
	// opendir() returns a pointer of DIR type.
	printf("Type a path with \\ on the end: ");
	scanf("%260s", path);
	ListAllDirs(path, 0);

	return 0;
}
