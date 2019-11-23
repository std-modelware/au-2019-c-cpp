#ifndef _AUQUEUE_H

#define _AUQUEUE_H
#include <stdio.h>

typedef struct auq_ {
	char i;
	int key;
} auq;

void auqueue_init(size_t size);
void auqueue_release();
void auqueue_enqueue(char item, int key);
char auqueue_dequeue();
void auqueue_print();
void auqueue_last_error();

#endif