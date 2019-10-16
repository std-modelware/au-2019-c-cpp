#include <stdio.h>
#include <stdlib.h>
typedef struct List *node;

struct List {
    int val;
    node next, prev;

};

void add_elem(node *head, node *tail, int val) {
    node tmp;
    tmp = (node) malloc(sizeof(struct List));
    tmp->val = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (*head == NULL) {
        *head = tmp;
    } else {
        node current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        tmp->prev = current;
        current->next = tmp;
    }
    *tail = tmp;
}

void create_list(node *head, node *tail, int n) {
    for (int i = 0; i < n; i++) {
        add_elem(head, tail, i);
    }
}
int main() {
    node head, tail = NULL;
    create_list(&head, &tail, 10);

    node tmp = head;
    while(tmp->next != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("%d \n", tmp->val);

    for (node temp = tail; temp != NULL; temp = temp->prev) {
        printf("%d ", temp->val);
    }
    return 0;
}