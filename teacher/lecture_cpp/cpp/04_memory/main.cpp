#include <iostream>

using namespace std;

void main() {
	// выделение памяти для char
	char *pc = new char;
	*pc = 'a';
	cout << "*pc = " << *pc << endl;
	delete(pc);
	//pc = NULL;
	//delete(pc);
	// cout << "*pc = " << *pc << endl;

	char *pac = new char[10];

	char *bpac = pac;
	*pac++ = 'H';
	*pac++ = 'e';
	*pac++ = 'l';
	*pac++ = 'l';
	*pac++ = 'o';
	*pac++ = '!';
	*pac = 0;

	cout << "pac = " << *bpac << endl;
	cout << "pac = " << bpac << endl;

	delete[](bpac);

	try {
		while (1) new char[1000000];
	}
	catch (bad_alloc) {
		cout << "The memory is out" << endl;
	}


}