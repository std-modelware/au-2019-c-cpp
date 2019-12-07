#include "./moduleex.h"

static struct bun *queue_start;
static struct bun *queue_pointer;
static struct bun *queue_finish;
static struct bun *queue_look;
static size_t queue_size;
static int lastErrorCode = 0;
struct bun {
	char a;
	int prior;
 };

void auqueue_init(size_t size) {
	queue_start = calloc(sizeof(struct bun), size);
	queue_pointer = queue_start;                
	queue_finish = queue_start;
	queue_look = queue_start;
	queue_size = size;
	if (queue_start == NULL) lastErrorCode = 1;
}

void auqueue_release() {
	free(queue_start);
}

void auqueue_enqueuefirst(char a, int prior) {
	lastErrorCode = 0;
	if (queue_pointer - queue_start >= queue_size) {
		lastErrorCode = 2;
		return;
	}
	(*queue_pointer).a = a;
	(*queue_pointer).prior = prior;
	*queue_pointer++;
	*queue_finish++;
}

void auqueue_enqueue(char a, int prior) {
	lastErrorCode = 0;
	if (queue_pointer - queue_start >= queue_size) {
		lastErrorCode = 2;
		return;
	}
	queue_look = queue_start;
	while (queue_look != queue_finish) {
		char rat = (*queue_look).prior;
		if (prior > rat) break;
		*queue_look++;
	}
	if (queue_look != queue_finish) {
		memcpy(queue_look + 1, queue_look, (queue_finish - queue_look) * sizeof(struct bun));
	} 
	queue_finish++;
	queue_pointer = queue_look;
	(*queue_pointer).a = a;
	(*queue_pointer).prior = prior;
	//*queue_pointer++;
}

char auqueue_dequeue() {
	lastErrorCode = 0;
	if (queue_start == queue_finish) {
		return 'x';
		lastErrorCode = 3;
	}
	char ret = (*queue_start).a;

	memcpy(queue_start, queue_start + 1, (queue_finish - queue_start - 1)* sizeof(struct bun));

	queue_finish--;

	return ret;
}

int auqueue_last_error() {
	return lastErrorCode;
}

char auqueue_print() {
	struct bun *p = queue_start;
	while (p != queue_finish) {
		printf("%c ", (*p++).a);
	}
	printf("\n");
}