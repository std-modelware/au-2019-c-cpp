#include <stdlib.h>
#include <stdio.h>
#include "double_linked.h"

int main() {
    int arr[] = {3, 494, 292, 193, 491};
    node head, tail = NULL;
    CreateList(&head, &tail, arr, 5);

    for (node temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("%c", '\n');
    for (node temp = tail; temp != NULL; temp = temp->prev) {
        printf("%d ", temp->data);
    }
    return 0;
}
