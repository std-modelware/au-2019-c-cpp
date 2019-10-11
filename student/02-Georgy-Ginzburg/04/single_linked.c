#include <stdio.h>
#include "single_linked.h"

int main() {
    int arr[] = {10, 7, 11, 38, 49};
    node list = CreateList(arr, 5);
    for (node iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", iter->data);
    }
}