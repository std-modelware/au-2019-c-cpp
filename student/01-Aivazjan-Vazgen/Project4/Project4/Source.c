#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void head(int n);
void headb(int n);


void main() {
	setlocale(LC_ALL, "Russian");///����������� �������� �����
	int a = 1;
	char spokidoki[512];///����� �������,������� ����� ����������(head...)
	char spokidoki1[512];///����� �������,������� ����� ����������(head...)

	char spokidoki3[512];///����� �������,������� ����� ����������(head...)

	scanf("%s %s", spokidoki, spokidoki1);

	if (!((spokidoki[0] == 'h') && (spokidoki[1] == 'e') && (spokidoki[2] == 'a') && (spokidoki[3] == 'd') && (spokidoki1[0] == '-')));
	else if ((spokidoki1[1] == 'n')) {
		scanf("%d %s", &a, spokidoki3);
		head(a, spokidoki3);
	}
	else if ((spokidoki1[1] == 'c')) {
		scanf("%x %s", &a, spokidoki3);
		headb(a, spokidoki3);
	}

}

void head(int n, char* assgard) {

	FILE* katya888 = NULL;
	//char* assgard = (char*)malloc(256); ///���������� ������ ������
	char u;
	/*printf("��������� ������,��������������� ��������\n");
	scanf("%s", assgard); ///������ ������
	katya888 = fopen(assgard, "r"); ///��������� ���� �� ������
	while (katya888 == NULL) {///���� ����� ����������,��� ��� �� �������� ����,�� ��������
	printf("�� ������� ������� ����\n");
	printf("��������� ������ ��������\n");
	scanf("%s", assgard); ///������ ������
	katya888 = fopen(assgard, "r"); ///��������� ���� �� ������

	}*/
	katya888 = fopen(assgard, "r"); ///��������� ���� �� ������
	for (int i = 0; i < n; i++) {///������� ������� � ���-�� ����� �������� ���
		u = 'a';
		while (!((u == '\n') || (u == EOF))) {///�������� �� ����� �����
			if (!feof(katya888)) {///�� ��� � ����� ����� �����
				fscanf(katya888, "%c", &u);
				printf("%c", u);
			}
		}
	}
	fclose(katya888);
	printf("\nHappy End����\n");
}
void headb(int n, char* assgard) {

	FILE* katya888 = NULL;
	//char* assgard = (char*)malloc(256); ///���������� ������ ������
	char u = 'a';
	/*printf("��������� ������,��������������� ��������\n");
	scanf("%s", assgard); ///������ ������
	katya888 = fopen(assgard, "r"); ///��������� ���� �� ������
	while (katya888 == NULL) {///���� ����� ����������,��� ��� �� �������� ����,�� ��������
	printf("�� ������� ������� ����\n");
	printf("��������� ������ ��������\n");
	scanf("%s", assgard); ///������ ������
	katya888 = fopen(assgard, "r"); ///��������� ���� �� ������

	}*/
	katya888 = fopen(assgard, "rb"); ///��������� ���� �� ������
	for (int i = 0; (i < n) && (u != EOF); i++) {///������� ������� � ���-�� ����� �������� ���
		if (!feof(katya888)) {///�� ��� � ����� ����� �����
			fscanf(katya888, "%c", &u);
			printf("%x ", u);
		}
	}
	fclose(katya888);
	printf("\nHappy End����\n");
}