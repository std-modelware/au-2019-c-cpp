#include <stdio.h>

void myfunc1() {
	printf("myfunc1()\n");
}

void myfunc2();

int myfunc3() {
	return 1;
}

int myfunc4(int p) {
	return p + 1;
}

void myfunc5(int p) {
	p = p + 1;
	printf("inside p = %d\n", p);
}

int myfunc6(int p) {
	return (p % 2 == 1) ? p : myfunc6(p >> 1);
}

void main() {
	printf("functions\n");

	myfunc1();

	myfunc2();

	printf("%d\n", myfunc3());
	
	printf("%d\n", myfunc4(100));

	int p = 100;
	printf("before p = %d\n", p);
	myfunc5(p);
	printf("after p = %d\n", p);

	printf("%d\n", myfunc6(100)); // 25
	printf("%d\n", myfunc6(25)); // 25
	printf("%d\n", myfunc6(12)); // 3
	printf("%d\n", myfunc6(8)); // 1

	printf("functions\n");
}

void myfunc2() {
	printf("myfunc2()\n");
}