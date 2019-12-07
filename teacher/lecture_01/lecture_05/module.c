#include <stdio.h>
#include "./moduleex.h"
#include "./moduleex.h"
#include "./moduleex.h"
#include "./moduleex.h"
#include "./moduleex.h"

void main() {
	printf("module\n");

	myfunction();

	struct MyStruct s;
	s.i1 = 12;
	printf("i1 = %d\n", s.i1);

	extern int myvar;
	printf("myvar = %d\n", myvar);
	//extern int myvar2;
	//printf("myvar2 = %d\n", myvar2);


	// .h
	// описание функций + определение типов

	// .c
	// реализация функций + определение переменных (static - видимость ограничена границей модуля)

	printf("module\n");
}