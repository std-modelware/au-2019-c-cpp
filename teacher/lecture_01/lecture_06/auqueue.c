#include "auqueue.h"

static char *queue_start;
static char *queue_pointer;
static size_t queue_size;

void auqueue_init(size_t size) {
	queue_start = calloc(sizeof(char), size);
	queue_pointer = queue_start;
	queue_size = size;
}

void auqueue_release() {
	free(queue_start);
}

void auqueue_enqueue(char i) {
	if (queue_pointer - queue_start >= queue_size) return;

	(*queue_pointer++) = i;
}

char auqueue_dequeue() {
	if (queue_start == queue_pointer) return 'x';

	char ret = *queue_start;

	memcpy(queue_start, queue_start + 1, queue_pointer - queue_start - 1);
	queue_pointer--;
	
	return ret;
}

char auqueue_print() {
	char *p = queue_start;
	while (p != queue_pointer) {
		printf("%c ", *p++);
	}
	printf("\n");
}