#include <stdio.h>
#include "module.h"
#include "austack2.h"

void main() {
	printf("module\n");

	myfunction();

	struct MyStruct m;
	m.i = 12;
	printf("%d\n", m.i);

	extern int myvar;
	printf("%d\n", myvar);

	//extern int myvar2;
	//printf("%d\n", myvar2);
	printf("module\n");



	au_init(5);
	au_print();

	au_push(1);
	au_print();

	au_push(2);
	au_print();

	au_push(3);
	au_print();

	au_push(4);
	au_print();

	au_push(5);
	au_print();

	au_push(6);
	au_print();

	char r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	r = au_pop();
	printf("r = %d\n", r);
	au_print();

	au_release();
}