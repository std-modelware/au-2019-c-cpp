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

void method_two(long int a, long int b) {
    printf("\n======= METHOD 2 =======");
    clock_t start = clock();

    if (a < 0 && b > 0) {
        b = -b;
        while (a <= b) {
            a -= b;
        }
    }
    else if (a > 0 && b < 0) {
        b = -b;
        while (a >= b) {
            a -= b;
        }
    }
    else if (a > 0 && b > 0) {
        while (a >= b) {
            a -= b;
        }
    }
    else if (a < 0 && b < 0) {
        while (a <= b) {
            a -= b;
        }
    }
    long int result = a;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nResult: %ld\n", result);
    printf("Time: %f seconds\n", seconds);
}

void test() {
    long int a;
    long int b;

    a = 27;
    b = 4;
    method_one(a, b);
    method_two(a, b);
    a = -15;
    b = 4;
    method_one(a, b);
    method_two(a, b);
    a = 113;
    b = -3;
    method_one(a, b);
    method_two(a, b);
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
