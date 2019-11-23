#include <iostream>

using namespace std;

struct S {
public:
	int i;
	double d;
};

class C {
private:
	int i;
	double d;

public:
	C() {
		i = 22;
		d = 22.22;
	}

	C(int i, double d) {
		this->i = i;
		this->d = d;
	}

	void print() {
		cout << "i = " << i << ", d = " << d << endl;
	}
};

void main() {

	S s;
	s.i = 10;
	s.d = 10.10;

	cout << s.i << "\\" << s.d << endl;

	C c(33, 33.33);
	//c.i = 11;
	//c.d = 11.11;

	//cout << c.i << "\\" << c.d << endl;

	c.print();
}