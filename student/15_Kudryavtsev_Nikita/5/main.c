#include <stdio.h>

#include "queue.h"

int main() {
    char deq;

    queue _queue = auqueue_init(7);
    _queue = au_enqueue(_queue, 5, 5);
    for (size_t i = 1; i < _queue.capacity - 2; i++)
        _queue = au_enqueue(_queue, i, i);
    auqueue_print(_queue);
    while (_queue.size != 0) {
        deq = auqueue_dequeue(&_queue);
        printf("%d\n", deq);
        auqueue_print(_queue);
    }
    auqueue_last_error();
    _queue = auqueue_release(_queue);
    auqueue_print(_queue);

    return 0;
}

