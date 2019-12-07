#include "header.h"

typedef struct element {
    int priority_of_element;
    char value_of_element;
} element;

static element *queue_start;
static element *queue_end;
static size_t queue_size;
static element *queue_run;

int getLastError(int i) {
	switch(i){
        case '1':
            printf("Error: auqueue_enqueue\n\tqueue_end - queue_start >= queue_size");
            break;
        case '2':
            printf("");
            break;
        case '3':
            printf("");
            break;
    }
}

void auqueue_init(size_t size) {
	queue_start = calloc(sizeof(element), size);
	queue_end = queue_start;
	queue_size = size;
    queue_run = queue_start;
}

void auqueue_release() {
	free(queue_start);
}

void auqueue_enqueue(char element_of_auqueue, int priority) {
    queue_run = queue_start;
	if (queue_end - queue_start >= queue_size) {
        getLastError(1);
        return;
    }

    if (queue_start == queue_end) {
        (*queue_end).value_of_element = element_of_auqueue;
        (*queue_end).priority_of_element = priority;
        queue_end ++;
        return;
    }

    for (int i = 1; i <= queue_end - queue_start; i++){
		if ((*queue_run).priority_of_element < priority)  break;
		queue_run++;
	};

    memcpy(queue_run + 1, queue_run, (queue_end - queue_run ) * sizeof(element));
	(*queue_run).value_of_element = element_of_auqueue;
	(*queue_run).priority_of_element = priority;

	queue_end++;
	//(*queue_end++) = i;
}

char auqueue_dequeue() {
	if (queue_start == queue_end) return 'x';

	char ret = (*queue_start).value_of_element;

	memcpy(queue_start, queue_start + 1, (queue_end - queue_start - 1) * sizeof(element));
	queue_end--;
	
	return ret;
}

char auqueue_print() {
	element *p = queue_start;
	while (p != queue_end) {
		printf("%c ", (*p).value_of_element);
        p++;
	}
	printf("\n");
}