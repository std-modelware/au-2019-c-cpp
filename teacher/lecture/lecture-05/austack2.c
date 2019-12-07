#include <stdio.h>
#include "austack2.h"

struct StackItem {
	char i;
	struct StackItem *next;
};

static struct StackItem *head = NULL;

void au_init(size_t sz) {
	head = NULL;
	struct StackItem *curr = NULL;
	for (int i = 0; i < sz; i++) {
		struct StackItem *p = malloc(sizeof(struct StackItem));

		if (head == NULL) {
			head = p;
			curr = p;
			continue;
		}

		curr->next = p;
		curr = p;
	}
}

void au_release() {
}

void au_push(char i) {
}

char au_pop() {
}

void au_print() {
}