#include <stdio.h>
#include "auqueue.h"

int main()
{
    printf("queue\n");

	auqueue_init(7);

	auqueue_enqueue('1');
	auqueue_print();
	auqueue_enqueue('2');
	auqueue_print();
	auqueue_enqueue('3');
	auqueue_print();
	auqueue_enqueue('4');
	auqueue_print();
	auqueue_enqueue('5');
	auqueue_print();
	auqueue_enqueue('6');
	auqueue_print();
	auqueue_enqueue('7');
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
    return 0;
}
