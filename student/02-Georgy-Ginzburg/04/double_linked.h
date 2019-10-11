#include <stdlib.h>

#pragma once
typedef struct DoubleLinkedList *node;

struct DoubleLinkedList {
    int data;
    node next;
    node prev;

};


// After creation, nodes are pushed into the back of the list
void NewNode(node *head, node *tail, int val) {
    node new;
    new = (node) malloc(sizeof(struct DoubleLinkedList));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    if (*head == NULL) {
        *head = new;
    } else {
        node temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
    }
    *tail = new;
}

void CreateList(node *head, node *tail, int *arr, int len) {
    for (size_t i = 0; i < len; i++) {
        NewNode(head, tail, arr[i]);
    }
}
