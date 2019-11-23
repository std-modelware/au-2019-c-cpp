#include <stdio.h>
#include "auqueue.h"

void main() {
	printf("queue\n");

	auqueue_init(7);

	auqueue_enqueue('2', 9);
	auqueue_print();
	auqueue_enqueue('3', 6);
	auqueue_print();
	auqueue_enqueue('4', 8);
	auqueue_print();
	auqueue_enqueue('5', 4);
	auqueue_print();
	auqueue_enqueue('6', 7);
	auqueue_print();
	auqueue_enqueue('7', 3);
	auqueue_print();
	auqueue_enqueue('A', -1);
	auqueue_print();

	char p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res =%c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();
	p = auqueue_dequeue();
	printf("res = %c\n", p);
	auqueue_print();


	auqueue_release();
}