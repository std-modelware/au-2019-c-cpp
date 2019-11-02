#include <stdio.h>
#include "aupqueue.h"

void main() {
	
	aupqueue_last_error();
	aupqueue_init(5);
	
	aupqueue_last_error();
	aupqueue_enqueue('1', 10);
	aupqueue_last_error();
	aupqueue_print();
	
	aupqueue_last_error();
	aupqueue_enqueue('2', 1);
	aupqueue_last_error();
	aupqueue_print();
	
	aupqueue_last_error();
	aupqueue_enqueue('3', 0);
	aupqueue_last_error();
	aupqueue_print();
	
	aupqueue_last_error();
	aupqueue_enqueue('4', 7);
	aupqueue_last_error();
	aupqueue_print();
	
	aupqueue_last_error();
	aupqueue_enqueue('5', 4);
	aupqueue_last_error();
	aupqueue_print();


	char p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	p = aupqueue_dequeue();
	aupqueue_last_error();
	printf("remove = %c\n", p);
	aupqueue_print();

	aupqueue_last_error();
	aupqueue_release();
	aupqueue_last_error();
}