#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

void CreateList(node *head, int *arr, int len) {
    for (size_t i = 0; i < len; i++) {
        NewNode(head, arr[i]);
    }
}

void TwoPassTraversal(node list, int k) {
    node t = list;
    int count = 0;
    while (t->next != NULL) {
        count++;
        t = t->next;
    }

    t = list;
    for (int i = 0; i < count - k + 1; i++) {
        t = t->next;
    }
    printf("%d-th element with TwoPassTraversal: %d\n", k, t->data);
}

void TwoPointerTraversal(node list, int k) {
    node p, q;
    p = list;
    q = list;
    while (abs(q - p) / 2 != k) {
        p = p->next;
    }
    while (p->next != NULL) {
        p = p->next;
        q = q->next;
    }

    printf("%d-th element with TwoPointerTraversal: %d\n", k, q->next->data);
}

void RecursiveTraversal(node head, node *p, int k, int *count) {
    if (head == NULL)
        return;

    RecursiveTraversal(head->next, p, k, count);
    *count += 1;

    if (*count == k)
        *p = head;
}

void RecursiveTraversalWrapper(node list, int k) {
    node p = NULL;
    int count = 0;

    RecursiveTraversal(list, &p, k, &count);
    printf("%d\n", p->data);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = (int) sizeof(arr) / sizeof(arr[0]);
    node list = NULL;
    CreateList(&list, arr, length);
    for (node iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", iter->data);
    }
    printf("\n");
    TwoPassTraversal(list, 4);
    TwoPointerTraversal(list, 2);
    RecursiveTraversalWrapper(list, 6);
}
