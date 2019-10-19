#include <stdio.h>

typedef struct elem{
    int num;
    struct elem *next;
} elem;

void main(){
    int n, x;
    elem *head;
    head = NULL;
    printf("n = ?\n");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&x);
        elem* tmp = (elem*)malloc(sizeof(elem));
        (*tmp).num = x;
        (*tmp).next = head;
        head = tmp;
    }
    elem *runner = head;
    while(runner != NULL){
        printf("%d ",(*runner).num);
        runner=(*runner).next;
    }

}
