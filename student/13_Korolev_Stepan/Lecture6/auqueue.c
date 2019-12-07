#include "auqueue.h"
#include <stdlib.h>
#include <string.h>

static auq* queue_start;
static auq* queue_pointer;
static size_t queue_size;
static char* last_error_string = "";

void auqueue_init(size_t size) {
	queue_start = (auq*)calloc(sizeof(auq), size);
	if (queue_start == NULL) {
		last_error_string = "Not enough memory in auqueue_init";
		auqueue_last_error();
	}
	queue_pointer = queue_start;
	queue_size = size;
}

void auqueue_release() {
	free(queue_start);
}

void auqueue_enqueue(char i, int key) {
	if (queue_pointer - queue_start >= queue_size) {
		last_error_string = "Auqueue is full";
		auqueue_last_error();
	}
	else {
		queue_pointer->i = i;
		queue_pointer++->key = key;
	}
}

char auqueue_dequeue() {
	if (queue_start == queue_pointer) {
		last_error_string = "Auqueue is empty";
		auqueue_last_error();
		return 'x';
	}
	
	auq* tmp = queue_start;
	auq _tmp;
	char ret = tmp[0].i;
	int key = tmp[0].key;
	for (tmp; tmp < queue_pointer - 1; tmp++) {
		if (key < tmp[1].key) {
			_tmp = tmp[0];
			tmp[0] = tmp[1];
			tmp[1] = _tmp;
		}
		else {
			ret = tmp[1].i;
			key = tmp[1].key;
		}
	}

	queue_pointer--;

	return ret;
}

void auqueue_print() {
	auq* p = queue_start;
	while (p != queue_pointer) {
		printf("%c ", p++->i);
	}
	printf("\n");
}

void auqueue_last_error() {
	printf("%s\n", last_error_string);
}