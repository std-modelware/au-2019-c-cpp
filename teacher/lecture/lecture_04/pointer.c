#include <stdio.h>
#include <stdlib.h>

void func1(int i);
void func2(int *i);
void func3(int **i);

void main() {
	printf("pointer\n");

	int x = 10;
	int *px = &x;

	printf("%p -> %d\n", px, x);
	printf("%p -> %d\n", px, *px);


	int nums[] = { 1,2,3,4,5,6,7,8,9 };
	int *pnums1 = nums;
	int *pnums2 = &nums[0];

	printf("%p = %p\n", pnums1, pnums2);

	printf("%d ", *pnums1); // 1
	printf("%d ", ++*pnums1); // 2
	printf("%d ", ++*pnums1);
	printf("%d ", ++*pnums1);
	printf("%d\n", ++*pnums1);

	int i1 = 1;
	func1(i1);
	printf("func1() i = %d\n", i1);

	int i2 = 5;
	func2(&i2);
	printf("func2() i = %d\n", i2);

	int i3 = 8;
	int *pi3 = &i3;
	int **ppi3 = &pi3;
	func3(ppi3);
	printf("func3() i = %d\n", i3);
	printf("func3() i = %d\n", **ppi3);

	printf("pointer\n");
}

void func1(int i) {
	i = i + 1;
}
void func2(int *i) {
	(*i)++;
}
void func3(int **i) {
	// **i = 22;
	int *p = malloc(sizeof(int));
	*p = 22;
	*i = p;
}