#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int a[10];
    int *b = malloc(sizeof(int)*10);

    a[5] = 7;
    b[5] = 7;

    *(b+5) = 1;
    *(a+5) = 1;

    return 0;
}
