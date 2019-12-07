#include <stdio.h>
#include "queue.h"

int main() {
    PriorityQueue q = auqueue_init(11);
    q = au_enqueue(q, 1, 1);

    auqueue_print(q);
    q = au_enqueue(q, 2, 2);


    auqueue_print(q);
    for (size_t i = -10; i < -2; i++) {
//        printf("%d %d\n", i, i);
        q = au_enqueue(q, i, i);
//        auqueue_print(q);
        printf("\n");
    }

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

