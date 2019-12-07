#include <stdio.h>
#include <stdlib.h>

int N, x;

int main() {
    scanf("%d", &N);
    
    int* adressFirstElem = malloc( sizeof(*adressFirstElem) * N);

    for(int i = 1; i < N+1; i++) {
        scanf("%d", &x);
        int* a = (adressFirstElem + (i-1));
        *a = x;    
    }

    for(int i = 1; i < N+1; i++) {
        printf("i = %d %p = %d\n",i, adressFirstElem + (i - 1), *(adressFirstElem + (i - 1)));
    }
}