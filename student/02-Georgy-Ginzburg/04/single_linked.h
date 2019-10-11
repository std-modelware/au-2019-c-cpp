#include <stdlib.h>

#pragma once
typedef struct SingleLinkedList *node;

struct SingleLinkedList {
    int data;
    node next;
};

void NewNode(node *head, int val) {
    node new;
    new = (node) malloc(sizeof(struct SingleLinkedList));
    new->data = val;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
    } else {
        node temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

node CreateList(int *arr, int len) {
    node head = NULL;
    for (size_t i = 0; i < len; i++) {
        NewNode(&head, arr[i]);
    }
    return head;
}

