#include <stdio.h>
#include "header.h"

int main() {
	printf("queue\n");
	auqueue_init(6);

		auqueue_enqueue('9', 0);
		auqueue_print();
		auqueue_enqueue('2', 5);
		auqueue_print();
		auqueue_enqueue('3', 3);
		auqueue_print();
		auqueue_enqueue('4', 8);
		auqueue_print();
		auqueue_enqueue('5', 5);
		auqueue_print();
		auqueue_enqueue('6', 6);
		auqueue_print();
		auqueue_enqueue('7', 7 );
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

		auqueue_release();
}