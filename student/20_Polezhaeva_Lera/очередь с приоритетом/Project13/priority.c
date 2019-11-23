#include "priority.h"
#include <stdio.h>

typedef struct qu {
	int p;
	char a;
}q;

static q* queue_start;
static q* queue_pointer;
static size_t queue_size;
static q* queue_run;
int runner = 0;


void auqueue_init(size_t size) {
	queue_start = calloc(sizeof(q), size);
	queue_pointer = queue_start;
	queue_size = size;
	queue_run = queue_start;
}

void auqueue_release() {
	free(queue_start);
}

void auqueue_enqueue(char a, int p  ) {
	queue_run = queue_start;
	if (queue_pointer - queue_start >= queue_size) {
		return;
	}
	if (queue_pointer == queue_start) {

		(*queue_pointer).a = a;
		(*queue_pointer).p = p;

		*queue_pointer++;

		return;
	}
	for (int i = 1; i <= queue_pointer - queue_start; i++){
		if ((*queue_run).p < p)  break;
		queue_run++;
	};
	memcpy(queue_run + 1, queue_run, (queue_pointer - queue_run ) * sizeof(q));
	(*queue_run).a = a;
	(*queue_run).p = p;

	*queue_pointer++;
	
}

char auqueue_dequeue() {
	if (queue_start == queue_pointer) {
		getLastError(2);
		return;
	}
	char ret = (*queue_start).a;

	memcpy(queue_start, queue_start + 1, (queue_pointer - queue_start - 1) * sizeof(q));
	queue_pointer--;

	return ret;
};

int getLastError(int i) {
	return i;
};
	

char auqueue_print() {
	q* p = queue_start;
	while (p != queue_pointer) {
		printf("%c ", (*p).a);
		p++;
	}
	printf("\n");
}