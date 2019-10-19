// как же хочется спать  _ ))))))
#include <stdio.h>

typedef struct elem {
    int num;
    struct elem *next;
    struct elem *prev;
} elem;

elem *head;

elem *add(int x) {
    elem *tmp = (elem*)malloc(sizeof(elem));
    (*tmp).num = x;
    (*tmp).next = NULL;
    (*tmp).prev = NULL;
    return tmp;
}
void atstart(int x) {
    elem *tmp = add(x);
    if (head == NULL) {
        head = tmp;
        return;
    }
    (*head).prev = tmp;
    (*tmp).next = head;
    head = tmp;
}
void main() {
    int N, x;
    head = NULL;
    printf("N = ?\n");
    scanf("%d", &N);
    //вывод списка
    for(int i = 1; i <= N; i++) {
        scanf("%d", &x);
        atstart(x);
    }

    elem *runner = head;
    while (runner != NULL) {
        printf("%d ", (*runner).num);
        runner = (*runner).next;
    }
    printf("\n");
    //вывод списка в обратном порядке
    elem *reverser = head;
    if (reverser == NULL) {
        return;
    }
    while ((*reverser).next != NULL) {
        reverser = (*reverser).next;
    }

    while (reverser != NULL)
    {
        printf("%d ", (*reverser).num);
        reverser = (*reverser).prev;
    }

}
