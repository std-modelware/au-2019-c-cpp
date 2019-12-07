#include "au_queue.h"

static char * queue_start;
static char * queue_point;
static size_t queue_size;

void au_init(size_t sz) {
	queue_start = calloc(sizeof(char), sz);
	queue_point = queue_start;
	queue_size = sz;
}

void au_release() {
	free(queue_start);
}

void au_enqueue(char i, int prio) {
	if (queue_point - queue_start >= queue_size) return;

	*queue_point++ = i;
}


char au_dequeue() {
	if (queue_point == queue_start) return 'x';

	char ret = *queue_start;

	memcpy(queue_start, queue_start + 1, queue_point - queue_start - 1);
	queue_point--;
	return ret;
}

void au_print() {
	char *p = queue_start;
	while (p != queue_point) {
		printf("%d ", *p++);
	}
	printf("\n");
}