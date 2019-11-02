#include "./aupqueue.h"
#include <memory.h>
static struct queue *queue_start;
static struct queue *queue_pointer;
static struct queue *queue_finish;
static struct queue *queue_look;
static size_t queue_size;

static int ERROR = 0;
struct queue {
	char elem;
	int priority;
};

void aupqueue_init(size_t size) {
	queue_start = calloc(sizeof(char), size);
	queue_pointer = queue_start;
	queue_finish = queue_start;
	queue_look = queue_start;
	queue_size = size;
	if (queue_start == NULL) ERROR = 1;
}


void aupqueue_enqueuefirst(char elem, int priority) {
	if (queue_pointer - queue_start >= queue_size) {
		ERROR = 2;
		return;
	}
	(*queue_pointer).elem = elem;
	(*queue_pointer).priority = priority;
	*queue_pointer++;
	*queue_finish++;

}

void aupqueue_enqueue(char elem, int priority) {
	if (queue_pointer - queue_start >= queue_size) {
		ERROR = 2;
		return;
	}
	queue_look = queue_start;
	while (queue_look != queue_finish) {
		char rat = (*queue_look).priority;
		if (priority > rat) break;
		*queue_look++;
	}
	if (queue_look != queue_finish) {
		memcpy(queue_look + 1, queue_look, (queue_finish - queue_look) * sizeof(struct queue));
		queue_finish++;
		queue_pointer = queue_look;
		(*queue_pointer).elem = elem;
		(*queue_pointer).priority = priority;
	}
}

char aupqueue_dequeue() {
	if (queue_start == queue_pointer) {
		ERROR = 3;
		return;
	}
	char ret = (*queue_start).elem;
	memcpy(queue_look + 1, queue_look, (queue_finish - queue_look) * sizeof(struct queue));
	queue_finish--;
	return ret;
}

void aupqueue_print() {
	struct queue *p = queue_start;
	while (p != queue_finish) {
		printf("%c", (*p++).elem);
	}
	printf("\n");
}

void aupqueue_release() {
	free(queue_start);
	queue_size = 0;
	queue_pointer = NULL;
	queue_finish = NULL;
	queue_look = NULL;
}

void aupqueue_last_error() {
	if (ERROR == 1) {
		printf("Queue is not created! STOP!");
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