#include "stdio.h"
#include "module.h"

static char *stackBottom = NULL;
static char *stackTop = NULL;
static size_t count = 0;
static size_t stackSize = 0;

void au_init(size_t sz) {
	stackBottom = calloc(sizeof(char), sz);
	stackTop = stackBottom;
	count = 0;
	stackSize = sz;
}

void au_release() {
	free(stackBottom);
}

void au_push(char i) {
	if (count == stackSize) {
		return;
	}
	*stackTop = i;
	count++;
	stackTop++;
}

char au_pop() {
	if (count == 0) {
		return 0;
	}
	stackTop--;
	count--;
	return *(stackBottom + count);
}

void au_print() {
	for (int i = 0; i < count; i++) {
		printf("%d ", *(stackBottom + i));
	}
	printf("\n");
}