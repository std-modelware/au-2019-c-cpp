#include <stdio.h>
#include "single_linked.h"

int main() {
    int arr[] = {10, 7, 11, 38, 49, 292};
    int l = (int) sizeof(arr) / sizeof(arr[0]);
    node list = NULL;
    CreateList(&list, arr, l);
    for (node iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", iter->data);
    }
}