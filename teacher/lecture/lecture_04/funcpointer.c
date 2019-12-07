#include <stdio.h>

typedef void(*F1)();
typedef int(*F2)(int);

void run12(F1 f) {
	f();
}

void run34(F2 f, int i) {
	f(i);
}

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

void main()
{
	printf("function pointer\n");

	/*
	void f1()

	1)     (*func)
	2)     (*func)()
	3) void(*func)()
	*/

	/*
	int f4(int i)

	1)    (*func)
	2)    (*func)(int)
	3) int(*func)(int)
	*/

	void(*pf1)() = f1;
	void(*pf2)() = f2;
	int(*pf3)(int) = f3;
	int(*pf4)(int) = f4;

	f1();
	f2();
	f3(10);
	f4(20);
	
	(*pf1)(); // f1()
	(*pf2)(); // f2()
	(*pf3)(10); // f3()
	(*pf4)(20); // f4()

	run12(f1);
	run12(f2);
	run34(f3, 100);
	run34(f4, 200);

	printf("function pointer\n");
}