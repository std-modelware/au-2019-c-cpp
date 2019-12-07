#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define LEN 100


void main() {
	  
	FILE* file_ptr;
	char str[LEN];
	file_ptr = fopen("test_file.txt", "w");

	if (file_ptr != NULL){
		printf("file new_file.txt is open!\n");
		fgets(str, 20, stdin);
		fprintf(file_ptr, "%s", str);
		fclose(file_ptr);
	} else {
		printf_s("Ошибка");
		exit(0);
	}
	
	//copy file (char)

	FILE* start_file, * end_file;
	char i;
	start_file = fopen("start_file.txt", "r");
	end_file = fopen("end_file.txt", "w");

	if (start_file != NULL && end_file != NULL) {
		while ((i = fgetc(start_file)) != EOF) {
			fputc(i, end_file);
		}
		fclose(start_file);
		fclose(end_file);
		printf("yes i do!\n");
	} else {
		printf_s("Ошибка");
		exit(0);
	}

	//  copy file (sring)
	
	FILE* start_file2, * end_file2;
	start_file2 = fopen("start_file2.txt", "r");
	end_file2 = fopen("end_file2.txt", "w");

	if (start_file2 != NULL && end_file2 != NULL) {
		while ((fgets(str, LEN, start_file2)) != NULL) {
			fputs(str, end_file2);
		}
		fclose(start_file2);
		fclose(end_file2);
		printf("yes i do!\n");
	} else {
		printf_s("Ошибка");
		exit(0);
	}


	//cope file (all)

	FILE* start_file3,* end_file3;
	int cnt;
	start_file3 = fopen("start_file3.txt", "r");
	end_file3 = fopen("end_file3.txt", "w");

	if (start_file3 != NULL && end_file3 != NULL) {
		while (!feof(start_file3)) {
			cnt = fread(&str, 1, LEN, start_file3);
			fwrite(&str, cnt, 1 , end_file3);
		}
		fclose(start_file3);
		fclose(end_file3);
		printf("yes i do!\n");
	}
	else {
		printf_s("Ошибка");
		exit(0);
	}
	return 0;
}