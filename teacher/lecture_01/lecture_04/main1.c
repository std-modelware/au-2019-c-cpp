#include <stdio.h>

typedef void(*F1)();
typedef int(*F2)(int);

void f1() {
	printf("f1()\n");
}

void f2() {
	printf("f2()\n");
}

int f3(int i) {
	printf("f3(%d)\n", i);
}

int f4(int i) {
	printf("f4(%d)\n", i);
}

void run12(F1 f) {
	f();
}

void run34(F2 f, int i) {
	f(i);
}

void main() {
	printf("function pointer\n");
	/*
	void f1()

	1)     (*f)
	2)     (*f)()
	3) void(*f)()

	*/

	/*
	int f4(int i)

	1)    (*f)
	2)    (*f)(int)
	3) int(*f)(int)
	*/

	void(*pf1)() = f1;
	void(*pf2)() = f2;

	int(*pf3)(int) = f3;
	int(*pf4)(int) = f4;

	F1 p1 = f1;
	F1 p2 = f2;
	F2 p3 = f3;
	F2 p4 = f4;

	f1();
	f2();
	f3(11);
	f4(22);

	(*pf1)();
	(*pf2)();
	(*pf3)(11);
	(*pf4)(22);

	printf("-----------\n");
	run12(f1);
	run12(f2);
	run34(f3, 99);
	run34(f4, 1000);

	printf("function pointer\n");
}