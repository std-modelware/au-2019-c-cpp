#include <stdio.h>

typedef struct elem {
    int num;
    struct elem *next;
} elem;

void main(){
    int N, x;
    elem *head;
    head = NULL;
    printf("N = ?\n");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        elem *tmp = (elem*)malloc(sizeof(elem));
        (*tmp).num = x;
        (*tmp).next = head;
        head = tmp;
    }
    elem *runner = head;
    while (runner != NULL) {
        printf("%d ", (*runner).num);
        runner = (*runner).next;
    }
}
