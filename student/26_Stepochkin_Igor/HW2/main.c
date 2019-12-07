#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x >= 0)
        printf("%d", x % y);
    else
        printf("%d", abs(y) - abs(x) % abs(y));
}
