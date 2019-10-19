#include <stdio.h>
#include "./stack.h"

void main() {

	au_init(5);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(1);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(2);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(3);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(4);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(5);
	au_print();
	printf("%d ", au_get_last_error());

	au_push(6);
	au_print();
	printf("%d ", au_get_last_error());
	

	char r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	r = au_pop();
	printf("r = %d\n", r);
	au_print();
	printf("%d ", au_get_last_error());

	au_release();
}
