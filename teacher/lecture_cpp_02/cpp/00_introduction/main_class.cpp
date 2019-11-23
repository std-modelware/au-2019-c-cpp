#include <iostream>

using namespace std;

struct S {
	int i;
	char c;
};

class C {
private:
	int i;
	char c;

public:
	C() {
		i = 10;
		c = 'f';
	}

	C(int i, char c) {
		this->i = i;
		this->c = c;
	}

	void print() {
		cout << i << " " << c << endl;
	}
};

int main() {

	S s;
	s.i = 120;
	s.c = 's';

	cout << s.i << " " << s.c << endl;

	C c(33, 'p');
	// c.i = 1;
	c.print();

}