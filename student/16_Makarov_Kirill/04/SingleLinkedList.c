#include <stdlib.h>
#include <stdio.h>

typedef struct List *node;

struct List {
    int val;
    node next;
};

void add_elem(node *head, int val) {
    node tmp;
    tmp = (node) malloc(sizeof(struct List));
    tmp->val = val;
    tmp->next = NULL;
    if (*head == NULL) {
        *head = tmp;
    } else {
        node cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void create_list(node *head, int n) {
    for (int i = 0; i < n; i++) {
        add_elem(head, i);
    }
}
int main() {
    node list = NULL;
    create_list(&list, 10);
    while(list->next != NULL){
        printf("%d ", list->val);
        list = list->next;
    }
    printf("%d ", list->val);
}