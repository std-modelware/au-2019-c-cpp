#include <stdio.h>
#include "./aupqueue.h"

static struct queue *queue_start;
static struct queue *queue_pointer;
static size_t queue_size;

static int ERROR = 0;
struct queue {
	char elem;
	int priority;
};

void aupqueue_init(size_t size) {
	ERROR = 0;
	if (size <= 0) {
		ERROR = 1;
		return;
	}
	queue_start = calloc(sizeof(struct queue), size);
	queue_pointer = queue_start;
	queue_size = size;
}

void aupqueue_release() {
	free(queue_start);
	queue_start = NULL;
	queue_pointer = NULL;
	queue_size = 0;
	ERROR = 0;
}

void aupqueue_enqueue(char elem, int priority) {
	ERROR = 0;
	if (queue_pointer - queue_start >= queue_size) {
		ERROR = 2;
		return;
	}
	if (queue_pointer == queue_start) {
		(*queue_pointer).elem = elem;
		(*queue_pointer).priority = priority;
		*queue_pointer++;
		return;
	}
	int i = 0;
	while (queue_start + i != queue_pointer) {
		int check = (*(queue_start + i)).priority;
		if (priority > check) break;
		i++;
	}
	if (queue_start + i != queue_pointer) {
		memcpy(queue_start + i + 1, queue_start + i, (queue_pointer - (queue_start + i)) * sizeof(struct queue));
	}
	(*(queue_start + i)).elem = elem;
	(*(queue_start + i)).priority = priority;
	queue_pointer++;
}

char aupqueue_dequeue() {
	ERROR = 0;
	if (queue_start == queue_pointer) {
		ERROR = 3;
		return 'x';
	}
	char removing = (*queue_start).elem;
	memcpy(queue_start, queue_start + 1, (queue_pointer - queue_start - 1) * sizeof(struct queue));

	queue_pointer--;

	return removing;
}

void aupqueue_last_error() {
	if (ERROR == 1) {
		printf("Queue is not created! STOP");
		exit(1);
	}
	if (ERROR == 2) {
		printf("Queue is full! STOP");
		exit(2);
	}
	if (ERROR == 3) {
		printf("Queue is empty! STOP");
		exit(3);
	}
	return;
}

char aupqueue_print() {
	struct queue *p = queue_start;
	while (p != queue_pointer) {
		printf("%c ", (*p++).elem);
	}
	printf("\n");
}