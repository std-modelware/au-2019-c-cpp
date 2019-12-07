#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct bun* queue_start;
static struct bun* queue_finish;
static struct bun* queue_look;
static size_t queue_size;
static int lastErrorCode = 0;
struct bun {
	char a;
	int prior;
};

void auqueue_init(size_t size) {
	queue_start = (bun*)calloc(sizeof(struct bun), size);
	queue_finish = queue_start;
	queue_look = queue_start;
	queue_size = size;
	if (queue_start == NULL) lastErrorCode = 1;
}

void auqueue_release() {
	free(queue_start);
}



void auqueue_enqueue(char a, int prior) {
	lastErrorCode = 0;
	if (queue_finish - queue_start >= queue_size) {
		lastErrorCode = 2;
		return;
	}
	queue_look = queue_start;
	if (queue_look == queue_finish) {
		(*queue_finish).a = a;
		(*queue_finish).prior = prior;
		*queue_finish++;
		return;
	}
	while (queue_look != queue_finish) {
		char rat = (*queue_look).prior;
		if (prior > rat) break;
		*queue_look++;
	}
	if (queue_look != queue_finish) {
		memcpy(queue_look + 1, queue_look, (queue_finish - queue_look) * sizeof(struct bun));
	}
	queue_finish++;
	(*queue_look).a = a;
	(*queue_look).prior = prior;
}

char auqueue_dequeue() {
	lastErrorCode = 0;
	if (queue_start == queue_finish) {
		return 'x';
		lastErrorCode = 3;
	}
	char ret = (*queue_start).a;

	memcpy(queue_start, queue_start + 1, (queue_finish - queue_start - 1) * sizeof(struct bun));

	queue_finish--;

	return ret;
}

int auqueue_last_error() {
	return lastErrorCode;
}

void auqueue_print() {
	struct bun* p = queue_start;
	while (p != queue_finish) {
		printf("%c ", (*p++).a);
	}
	printf("\n");
}

void main() {
	printf("queue\n");

	auqueue_init(5);

	auqueue_enqueue('1', 10);
	auqueue_print();
	auqueue_enqueue('2', 9);
	auqueue_print();
	auqueue_enqueue('3', 6);
	auqueue_print();
	auqueue_enqueue('4', 8);
	auqueue_print();
	auqueue_enqueue('5', 4);
	auqueue_print();
	auqueue_enqueue('6', 7);
	auqueue_print();
	auqueue_enqueue('7', 3);
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
	printf("res =%c\n", p);
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
}