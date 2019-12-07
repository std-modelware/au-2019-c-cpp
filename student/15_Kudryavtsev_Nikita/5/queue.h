#pragma once

typedef struct Queue queue;
typedef struct Node node;

queue auqueue_init(size_t cap);
queue au_enqueue(queue heap, char item, int priority);
char auqueue_dequeue();
queue auqueue_release(queue q);
void auqueue_print(queue q);
void auqueue_last_error();

struct Node {
    int priority;
    char data;
};

struct Queue {
    size_t capacity;
    size_t size;
    node *arr;
};
