#include <stdio.h>
#include <stdlib.h>
#define s 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	#include <stdio.h>



void main() {
	FILE *feed; //создание указателя на фаилл 
	char i;
	feed = fopen("new.txt", "w"); //создание с параметром на запись присвоение указател адреса
	scanf("%c", &i);
	fprintf(fill, "%c", i); //печать в фаил значения
	fclose(fill);

	FILE *copy, *paste;
	char z;
	copy = fopen("copy.txt", "r");//открытие на чтение
	paste = fopen("paste.txt", "w");//открытие на запись(всегда пустой)
	while ((z = fgetc(copy)) != EOF)  //проходимся по фаилу посимвольно забираем элемент и передвигаемся дальше пока он определён и вставляем его в нужный фаиил
	fputc(z, paste);
	fclose(copy);
	fclose(paste);
	
	FILE *scopy, *spaste;
	char buffer[s];
	scopy = fopen("scopy.txt", "r");
	spaste = fopen("spaste.txt", "w");
	while ((fgets(buffer,s,scopy)) != NULL) { //пока fets находит нужное количество символов в scopy
		fputs(buffer, spaste);                //вставляем эти символы в spaste
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
