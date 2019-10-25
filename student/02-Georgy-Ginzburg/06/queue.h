#include <stdlib.h>

#pragma once

typedef struct PriorityQueue PriorityQueue;
typedef struct Node Node;

PriorityQueue auqueue_init(size_t cap);

PriorityQueue au_enqueue(PriorityQueue heap, char item, int priority);

char auqueue_dequeue();

PriorityQueue auqueue_release(PriorityQueue q);

void auqueue_print(PriorityQueue q);

void auqueue_last_error();


struct Node {
    int priority;
    char data;
};

struct PriorityQueue {
    size_t Capacity;
    size_t Size;
    Node *Arr;
};


