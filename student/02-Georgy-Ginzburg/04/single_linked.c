#include <stdio.h>
#include "single_linked.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int l = (int) sizeof(arr) / sizeof(arr[0]);
    node list = NULL;
    CreateList(&list, arr, l);
    for (node iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", iter->data);
    }
}