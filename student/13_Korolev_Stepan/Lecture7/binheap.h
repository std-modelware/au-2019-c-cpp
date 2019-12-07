#ifndef _BINHEAP_H

#define _BINHEAP_H
#include <stdio.h>

typedef struct _ {
	struct _* left;
	struct _* right;
	struct _* parent;
	int value;
} node;

void binheap_init(size_t size, int value);
void binheap_insert(int value);
void binheap_print();
void binheap_last_error();

#endif