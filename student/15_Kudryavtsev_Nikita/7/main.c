#include <stdlib.h>
#include <stdio.h>

typedef struct List_Node *Node;

struct List_Node {
    int data;
    Node next;
};

Node list = NULL;

void create_node(int data) {
    Node node;
    Node *head = &list;
    node = (Node) malloc(sizeof(struct List_Node));
    node->data = data;
    node->next = NULL;
    if (*head == NULL) *head = node; else {
        Node temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
    }
}

void create_list(int *arr, int len) {
    for (size_t i = 0; i < len; i++) create_node(arr[i]);
}

void recursive(Node head, int x, int x1) {
    if (x == head->data) x1 = 0;
    if (x1 >= 0) {
        x1++;
    }
    if (head->next == NULL) {
        printf("%d-th element with recursive: %d\n", x, x1);
        return;
    }
    recursive(head->next, x, x1);
}

void two_pointer(int x) {
    Node a, b;
    a = list;
    b = list;
    while (labs(b - a) / 2 != x) a = a->next;
    while (a->next != NULL) {
        a = a->next;
        b = b->next;
    }

    printf("%d-th element with two_pointer: %d\n", x, b->next->data);
}

void two_pass(int x) {
    Node t = list;
    int count = 0;
    while (t->next != NULL) {
        count++;
        t = t->next;
    }

    t = list;
    for (int i = 0; i < count - x + 1; i++) t = t->next;
    printf("%d-th element with two_pass: %d\n", x, t->data);
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = (int) sizeof(arr) / sizeof(arr[0]);
    create_list(arr, len);
    for (Node i = list; i != NULL; i = i->next) printf("%d ", i->data);
    printf("\n");
    recursive(list, 5, 0);
    two_pointer(3);
    two_pass(1);
}
