#include <stdio.h>

#include "au_queue.h"

void main() {
	printf("queue\n");

	au_init(5);

	au_enqueue(1);
	au_print();
	au_enqueue(2);
	au_print();
	au_enqueue(3);
	au_print();
	au_enqueue(4);
	au_print();
	au_enqueue(5);
	au_print();
	au_enqueue(6);
	au_print();
	au_enqueue(7);
	au_print();

	char res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();
	res = au_dequeue();
	printf("res = %d\n", res);
	au_print();

	au_release();
}