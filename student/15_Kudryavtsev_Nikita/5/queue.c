#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

char *last_error;

void auqueue_last_error() {
    if (last_error != NULL) printf("%s\n", last_error);
}

queue auqueue_init(size_t cap) {
    queue tmp;
    tmp.size = 0;
    tmp.capacity = cap;
    tmp.arr = calloc(tmp.capacity, sizeof(struct Node));

    return tmp;
}

queue au_enqueue(queue heap, char item, int priority) {
    if (heap.size >= heap.capacity - 1) {
        last_error = "Can't add more elements\n";
        return heap;
    }
    heap.size++;
    size_t i = heap.size;
    size_t j = i / 2;
    while (i > 1 && heap.arr[j].priority <= priority) {
        heap.arr[i] = heap.arr[j];
        i = j;
        j /= 2;
    }
    heap.arr[i].priority = priority;
    heap.arr[i].data = item;

    return heap;
}

char auqueue_dequeue(queue *q) {
    if (q->size == 0) {
        last_error = "No elements\n";
        return 0;
    }
    char data = q->arr[1].data;
    q->arr[1] = q->arr[q->size];
    size_t i = 1;
    while (i != q->size) {
        size_t k = q->size;
        size_t j = 2 * i;
        if (j <= q->size && q->arr[j].priority > q->arr[k].priority) {
            k = j;
        }
        if (j + 1 <= q->size && q->arr[j + 1].priority > q->arr[k].priority) {
            k = j + 1;
        }
        q->arr[i] = q->arr[k];
        i = k;
    }
    q->arr[q->size].priority = 0;
    q->arr[q->size].data = 0;
    q->size -= 1;

    return data;
}

void auqueue_print(queue q) {
    for (size_t i = 0; i < q.capacity; i++) {
        printf("%d ", q.arr[i].priority);
    }
    printf("\n");
    for (size_t i = 0; i < q.capacity; i++) {
        printf("%d ", q.arr[i].data);
    }
    printf("\n");
}

queue auqueue_release(queue q) {
    q.arr = calloc(q.capacity, sizeof(struct Node));

    return q;
}
