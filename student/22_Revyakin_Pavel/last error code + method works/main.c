
#include <stdio.h>

static size_t stackSize;
static char *stackBottom;
static char *stackPointer;
static int error = 0;

void au_init(size_t sz) {
    stackSize = sz;
    stackBottom = calloc(sizeof(char), sz);
    stackPointer = stackBottom;
}

void au_release() {
    free(stackBottom);
    stackSize = 0;
    stackBottom = NULL;
    stackPointer = NULL;
}

void au_push(char i) {
    if (stackPointer - stackBottom >= stackSize) {
        error= 1;
        return;
    }
    *stackPointer = i;
    stackPointer++;
}

char au_pop() {
    if (stackBottom == stackPointer) {
        error=2;
        return 0;
    }
    stackPointer--;
    return *stackPointer;
}

int au_get_last_error() {
    return error;
}

void au_print() {
    char *p = stackBottom;
    while (p != stackPointer)
    {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}
void main() {

    au_init(5);
    au_print();

    au_push(1);
    au_print();

    au_push(2);
    au_print();

    au_push(3);
    au_print();

    au_push(4);
    au_print();

    au_push(5);
    au_print();

    au_push(6);
    au_print();

    char r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    r = au_pop();
    printf("r = %d\n", r);
    au_print();

    au_release();
}
