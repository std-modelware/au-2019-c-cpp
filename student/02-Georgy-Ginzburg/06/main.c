#include <stdio.h>
#include "queue.h"

int main() {
    PriorityQueue q = auqueue_init(11);
    q = au_enqueue(q, 9, 9);
    q = au_enqueue(q, 10, 10);
    for (size_t i = 1; i < q.Capacity - 2; i++)
        q = au_enqueue(q, i, i);
    auqueue_last_error();
    auqueue_print(q);
    char a;

    while (q.Size != 0) {
        a = auqueue_dequeue(&q);
        printf("%d\n", a);
        auqueue_print(q);
    }
    auqueue_last_error();
    q = auqueue_release(q);
    auqueue_print(q);
    return 0;
}

