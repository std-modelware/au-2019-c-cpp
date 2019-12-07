#include <stdio.h>
#include <stdlib.h>

void func1(int x);
void func2(int *x);
void func3(int **x);


void main()
{
	printf("pointers\n");
	
	int x = 10;
	int *px = &x;

	printf("%p -> %d\n", px, x);
	printf("%p -> %d\n", px, *px);
	printf("%p -> %d\n", &x, *px);

	int nums[] = { 1,2,3,4,5,6,7,8,9 };
	int *pnums1 = nums; // = &nums[0]
	int *pnums2 = &nums[0];

	printf("%p -> %d\n", pnums1, nums[0]);
	printf("%p -> %d\n", pnums2, nums[0]);

	printf("%d ", *pnums1);
	printf("%d ", ++*pnums1);
	printf("%d ", ++*pnums1);
	printf("%d\n", ++*pnums1);

	int i1 = 1;
	func1(i1);
	printf("func1() %d\n", i1);

	int i2 = 10;
	func2(&i2);
	printf("func2() %d\n", i2);

	int i3 = 99;
	int *pi3 = &i3;
	func2(pi3);
	printf("func2() %d\n", i3);

	int i4 = 88;
	int *pi4 = &i4;
	int **ppi4 = &pi4;
	func3(ppi4);
	printf("i4 = %d\n", i4);
	printf("**ppi4 = %d\n", **ppi4);

	printf("pointers\n");
}

void func1(int i) {
	i = i + 1;
}

void func2(int *i) {
	(*i)++;
}

void func3(int **i) {
	//**i = 8;
	int *p = malloc(sizeof(int));
	*p = 123;
	*i = p;
}