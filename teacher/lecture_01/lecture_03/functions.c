#include <stdio.h>

// Определение функции
void myfunc1() {
	printf("myfunc1()\n");
}

// декларация или объявление или прототипирование
void myfunc2();

int myfunc3() {
	return 1;
}

int myfunc4(int p1) {
	return p1 + 1;
}

void myfunc5(int p1) {
	p1 = p1 + 1;
	printf("inside myfunc5() p1 = %d\n", p1);
}

int myfunc6(int p) {
	//if (p % 2 == 0) {
	//	return myfunc6(p >> 1);
	//}
	//else {
	//	return p;
	//}

	return (p % 2 == 0) ? myfunc6(p >> 1) : p;
}

void main() {
	printf("functions\n");

	myfunc1();

	myfunc2();

	printf("myfunc3() returns %d\n", myfunc3());
	
	printf("myfunc4() returns %d\n", myfunc4(123));

	int p1 = 100;
	printf("before call p1 = %d\n", p1);
	myfunc5(p1);
	printf("after call p1 = %d\n", p1);


	printf("%d\n", myfunc6(100));
	printf("%d\n", myfunc6(32));
	printf("%d\n", myfunc6(28));
	printf("%d\n", myfunc6(1));

	printf("functions\n");
}

void myfunc2() {
	printf("myfunc2()\n");
}