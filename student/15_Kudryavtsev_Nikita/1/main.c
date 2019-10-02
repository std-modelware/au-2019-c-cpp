#include <stdio.h>
#include <time.h>

void method_one(long int a, long int b) {
    printf("\n======= METHOD 1 =======");
    clock_t start = clock();

    long int result = a % b;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nResult: %ld\n", result);
    printf("Time: %f seconds\n", seconds);
}


long int mod(long int a, long int b) {
    if (a == b) {
        return 0;
    }
    else if (a > b) {
        while (a >= b) {
            a -= b;
        }
    }
    else {
        while (a <= b) {
            a += b;
        }
    }
    return a;
}


void method_two(long int a, long int b) {
    printf("\n======= METHOD 2 =======");
    clock_t start = clock();
    long int ost = 0;
    long int mod_;

    if (a < 0 && b > 0) {
        mod_ = mod(-a, b);
        ost = b - mod_;
    }
    else if (a > 0 && b < 0) {
        b = -b;
        ost = mod(a, b);
    }
    else if (a > 0 && b > 0) {
        ost = mod(a, b);
    }
    else if (a < 0 && b < 0) {
        b = -b;
        mod_ = mod(-a, b);
        ost = b - mod_;
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nResult: %ld\n", ost);
    printf("Time: %f seconds\n", seconds);
}

void test() {
    long int a;
    long int b;
    char percent = 37;

    printf("\n\n\n27 %c 4", percent);
    a = 27;
    b = 4;
    method_one(a, b);
    method_two(a, b);
    printf("\n\n\n-15 %c 4", percent);
    a = -15;
    b = 4;
    method_one(a, b);
    method_two(a, b);
    printf("\n\n\n113 %c -3", percent);
    a = 113;
    b = -3;
    method_one(a, b);
    method_two(a, b);
    printf("\n\n\n-15 %c -7", percent);
    a = -15;
    b = -7;
    method_one(a, b);
    method_two(a, b);
}

int main() {

//    test();
//    return 0;

    char percent = 37;
    long int a;
    long int b;

    printf("Операция a %c b", percent);
    printf("\nВведите a: ");
    scanf("%ld", &a);
    printf("Введите b: ");
    scanf("%ld", &b);

    method_one(a, b);
    method_two(a, b);

    return 0;
}
