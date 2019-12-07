#include <stdlib.h>
#include <stdio.h>
#include "double_linked_with_arbitrary_args.h"

int main() {
    int arr[] = {1, 3, 34, 292, 90};
    node head = NULL;
    node tail = NULL;
    CreateList(&head, &tail, 5, 0, 9, 8, 5, 24);

    for (node temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("%c", '\n');
    for (node temp = tail; temp != NULL; temp = temp->prev) {
        printf("%d ", temp->data);
    }
    return 0;
}
