#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a < 0)
        printf("%d", abs(b) - abs(a)% abs(b));
    else
        printf("%d", a % b);
}