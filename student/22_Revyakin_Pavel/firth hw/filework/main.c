#include <stdio.h>
#include <stdlib.h>
#define s 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	#include <stdio.h>



void main() {
	FILE *feed; //�������� ��������� �� ����� 
	char i;
	feed = fopen("new.txt", "w"); //�������� � ���������� �� ������ ���������� �������� ������
	scanf("%c", &i);
	fprintf(fill, "%c", i); //������ � ���� ��������
	fclose(fill);

	FILE *copy, *paste;
	char z;
	copy = fopen("copy.txt", "r");//�������� �� ������
	paste = fopen("paste.txt", "w");//�������� �� ������(������ ������)
	while ((z = fgetc(copy)) != EOF)  //���������� �� ����� ����������� �������� ������� � ������������� ������ ���� �� �������� � ��������� ��� � ������ �����
	fputc(z, paste);
	fclose(copy);
	fclose(paste);
	
	FILE *scopy, *spaste;
	char buffer[s];
	scopy = fopen("scopy.txt", "r");
	spaste = fopen("spaste.txt", "w");
	while ((fgets(buffer,s,scopy)) != NULL) { //���� fets ������� ������ ���������� �������� � scopy
		fputs(buffer, spaste);                //��������� ��� ������� � spaste
	}
	fclose(scopy);
	fclose(spaste);

	FILE *flcopy,*flpaste;
	char buff[s];
	int l;
	flcopy = fopen("flcopy.txt", "r");
	flpaste = fopen("flpaste.txt", "w");
	do {
		l = fread(buff, 1, s, flcopy);
		fwrite(buff, l, 1, flpaste);
	} while (l == size);
	
	fclose(flcopy);
	fclose(flpaste);
}

	return 0;
}
