#include <stdio.h>
#include "stack.h"

void main() {

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
