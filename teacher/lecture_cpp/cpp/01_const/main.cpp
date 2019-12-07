#include <iostream>

using namespace std;

void func1(const int* p);

void main() {

	// const - указывает на то, что нельзя изменить непосредственно

	const int i = 100;
	// i = 1;
	const int v[] = { 1,2,3,4 };
	// v[1] = 2;

	int a = 26;
	func1(&a);
	cout << "a = " << a << endl;

}

void func1(const int* p) {
	int a = 11;
	p = &a;
	// *p = 22;
}

void func2(const int* const p) {
	int a = 11;
//	p = &a;
//	*p = 22;
}

void func3(int* const p) {
	int a = 11;
	//	p = &a;
	*p = 22;
}