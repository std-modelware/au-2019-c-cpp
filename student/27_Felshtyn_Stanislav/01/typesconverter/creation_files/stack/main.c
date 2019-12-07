#include <stdio.h>

static size_t stackSize;	
static char* stackBottom;
static char* stackPointer;
static int lastErrorCode = 0;

void au_init(size_t sz) {
	stackSize = sz;
	stackBottom = calloc(sizeof(char), sz);
	if (stackBottom == NULL) lastErrorCode = 1;
	stackPointer = stackBottom;
}

void au_release() {
	free(stackBottom);
	stackSize = 0;
	stackBottom = NULL;
	stackPointer = NULL;
}

void au_push(char i) {
	if (stackPointer - stackBottom >= stackSize) {
		lastErrorCode == 2;
		return;
	}
	*stackPointer = i;
	stackPointer++;
}

char au_pop() {
	if (stackBottom == stackPointer) {
		lastErrorCode == 3;
		return 0;
	}
	stackPointer--;
	return *stackPointer;
}

int au_get_last_error() {
	return lastErrorCode;
}

void au_print() {
	char* p = stackBottom;
	while (p != stackPointer)
	{
		printf("%d ", *p);
		p++;
	}
	printf("\n");
}