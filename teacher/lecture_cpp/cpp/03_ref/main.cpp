#include <iostream>

using namespace std;

void func(const int& i);

void main() {
	// ������ - ��� �������������� ��� �������
	int a = 12;
	int *pa = &a;

	int& ra = a;
	cout << "a = " << a << " pa = " << pa << endl;
	cout << "a = " << a << " ra = " << ra << endl;

	ra = 23;
	cout << "a = " << a << " ra = " << ra << endl;

	// int &ra2; // ������ (!) ������ ������ ���� ������ ��������������������
	ra++;
	cout << "a = " << a << " ra = " << ra << endl;

	int z = 12;
	func(z);
	cout << "z = " << z << endl;
}

void func(const int& i) {
	// i++;
}