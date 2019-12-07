#include <stdlib.h>
#include <stdio.h>
#include "double_linked.h"

int main() {
    int arr[] = {1, 3, 34, 292, 90};
    node head = NULL;
    node tail = NULL;
    int l = (int) sizeof(arr) / sizeof(arr[0]);
    CreateList(&head, &tail, arr, l);

    for (node temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("%c", '\n');
    for (node temp = tail; temp != NULL; temp = temp->prev) {
        printf("%d ", temp->data);
    }
    return 0;
}
