#include <stdio.h>
#include "queue.h"

static char *LastError = "";

void auqueue_last_error() {
    printf("%s\n", LastError);
}

PriorityQueue auqueue_init(size_t cap) {
    PriorityQueue tmp;
    tmp.Size = 0;
    tmp.Capacity = cap;
    tmp.Arr = calloc(tmp.Capacity, sizeof(struct Node));
    return tmp;
}

PriorityQueue au_enqueue(PriorityQueue heap, char item, int priority) {
    if (heap.Size >= heap.Capacity - 1) {
        LastError = "Unable to add more elements\n";

        return heap;
    }

    heap.Size++;
    size_t i = heap.Size;
    size_t j = i / 2;
    while (i > 1 && heap.Arr[j].priority <= priority) {
        heap.Arr[i] = heap.Arr[j];
        i = j;
        j /= 2;
    }
//    printf("%d %d %d %d\n", item, priority, j, i);
    heap.Arr[i].priority = priority;
    heap.Arr[i].data = item;
    return heap;
}

char auqueue_dequeue(PriorityQueue *q) {
    if (q->Size == 0) {
        LastError = "No elements to pop\n";
        return 0;
    }
    char data = q->Arr[1].data;
    q->Arr[1] = q->Arr[q->Size];
    size_t i = 1;
    while (i != q->Size) {

        size_t k = q->Size;
        size_t j = 2 * i;

        if (j <= q->Size && q->Arr[j].priority > q->Arr[k].priority) {
            k = j;
        }

        if (j + 1 <= q->Size && q->Arr[j + 1].priority > q->Arr[k].priority) {
            k = j + 1;
        }

        q->Arr[i] = q->Arr[k];
        i = k;
    }
    q->Arr[q->Size].priority = 0;
    q->Arr[q->Size].data = 0;
    q->Size -= 1;

    return data;
}

void auqueue_print(PriorityQueue q) {
    for (size_t i = 0; i < q.Capacity; i++) {
        printf("%d ", q.Arr[i].priority);
    }
    printf("\n");
    for (size_t i = 0; i < q.Capacity; i++) {
        printf("%d ", q.Arr[i].data);
    }
    printf("\n");
}

PriorityQueue auqueue_release(PriorityQueue q) {
    q.Arr = calloc(q.Capacity, sizeof(struct Node));
    return q;
}


