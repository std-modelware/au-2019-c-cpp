#include "auqueue.h"
#include <stdlib.h>
#include <string.h>

static char *queue_start;
static char *queue_pointer;
static size_t queue_size;
static char* last_error_string = "";

void auqueue_init(size_t size) {
	queue_start = (char*)calloc(sizeof(char), size);
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

void auqueue_enqueue(char i) {
	if (queue_pointer - queue_start >= queue_size) {
	    last_error_string = "Auqueue is full";
	    auqueue_last_error();
	} else {
	    (*queue_pointer++) = i;
	}
}

char auqueue_dequeue() {
	if (queue_start == queue_pointer) {
	    last_error_string = "Auqueue is empty";
	    auqueue_last_error();
	    return 'x';
	}
	char ret = *queue_start;
	
	char* tmp = queue_start;
    for (tmp; tmp < queue_pointer; tmp++) {
        *tmp = tmp[1];
    }
    
    queue_pointer--;
	
	return ret;
}

void auqueue_print() {
	char *p = queue_start;
	while (p != queue_pointer) {
		printf("%c ", *(p++));
	}
	printf("\n");
}

void auqueue_last_error() {
    printf("%s\n", last_error_string);
}