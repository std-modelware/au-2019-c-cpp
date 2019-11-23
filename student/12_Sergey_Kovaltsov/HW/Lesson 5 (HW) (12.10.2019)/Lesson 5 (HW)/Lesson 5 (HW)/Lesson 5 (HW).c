#include <stdio.h>
#define size 1
/*
scanf()
%�	������� ���� ������
%d	������� ���������� ����� ������ ����
%i	������� ���������� ����� ������ ����
%�	������� ����� � ��������� �������
%f	������� ����� � ��������� �������
%g	������� ����� � ��������� �������
%�	������� ������������ �����
%s	������� ������
%�	������� ����������������� �����
%�	������� ���������
%n	��������� ����� ��������, ������ ���������� ��������� �� �������� ������� ��������
%u	��������� ����������� �����
%[]	������������� ����� ��������
%%	��������� ������ %
%*s - ������������� �� ����� ����������

*/

int main() {

	// r - read (������ ������������� �����)
	// w - write (������ � ������������ (����������) ��� � �����)
	// a - add (���������� ������ � ���. ���� ��� �������� ������)
	// ������ + ������ � .txt
	// r+ - �� ������ � ������ (���. ����)
	// w+ - �� ������ � ������ ������� �����
	// a+ - �� ������ � ��������
	// rb, wb - �������� ����
	FILE *filein, *fileoutc, *fileouts, *fileoutf;

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileoutc = fopen("fileoutc.txt", "w");
		if (fileoutc != NULL) {
			printf("Symbol copying...\n");
			char k = fgetc(filein);
			while (k != EOF) {
				fputc(k, fileoutc);
				k = fgetc(filein);
			}
			printf("Complited!\n");
			fclose(fileoutc);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileouts = fopen("fileouts.txt", "w");
		if (fileouts != NULL) {
			printf("String copying...\n");
			char b[100];
			while (fgets(b, 100, filein)) {
				fputs(b, fileouts);
				b[100];
			}
			printf("Complited!\n");
			fclose(fileouts);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}

	filein = fopen("filein.txt", "r");
	if (filein != NULL) {
		printf("It's OK!\n");
		fileoutf = fopen("fileoutf.txt", "w");
		if (fileoutf != NULL) {
			printf("Text copying...\n");
			char d[size];
			int k;
			do {
				k = fread(d, sizeof(char), size, filein);
				fwrite(d, k, sizeof(char), fileoutf);

			} while (k == size);

			printf("Complited!\n");
			fclose(fileoutf);
			fclose(filein);
		}
		else {
			printf("Oops.File wasn't open\n");
			exit(1);
		}
	}
	else {
		printf("Oops.File wasn't open\n");
		return 1;
	}
}
