#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct array1 {
    int data;
    struct array1 *next;
} array1;

typedef struct array2 {
    int data;
    struct array2 *prev;
    struct array2 *next;
} array2;

typedef struct array2_head {
    array2 *start;
    array2 *end;
} array2_head;

void push1(array1 **start, int data) {
    array1 *temp = (array1*) malloc(sizeof(array1));
    temp->data = data;
    temp->next = *start;
    *start = temp;
}

void push2(array2_head *head, int data) {
    array2 *temp = (array2*) malloc(sizeof(array2));
    temp->data = data;
    temp->next = head->start;
    temp->prev = NULL;
    if (head->start) {
        head->start->prev = temp;
    }
    head->start = temp;
    if (head->end == NULL) {
        head->end = temp;
    }
}

void passage1(array1 *start) {
    while (start->next) {
        printf("%d\n", start->data);
        start = start->next;
    }
    printf("%d\n", start->data);
}

void passage2(array2_head *head) {
    array2 *start = head->start;
    while (start->next) {
        printf("%d\n", start->data);
        start = start->next;
    }
    printf("%d\n", start->data);
}

void passage2_reverse(array2_head *head) {
    array2 *end = head->end;
    while (end->prev) {
        printf("%d\n", end->data);
        end = end->prev;
    }
    printf("%d\n", end->data);
}

int main() {
    array1 *start = NULL;
    for(int i=1; i<=N; i++) {
        push1(&start, i);
    }
    passage1(start);

    array2_head head = {NULL, NULL};
    for(int i=1; i<=N; i++) {
        push2(&head, i);
    }
    passage2(&head);
    passage2_reverse(&head);

    return 0;
}
