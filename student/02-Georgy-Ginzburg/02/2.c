//
// Created by georgyginzburg on 27.09.2019.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", (a % b) < 0 ? (a % b) + abs(b) : (a % b));

    return 0;
}


