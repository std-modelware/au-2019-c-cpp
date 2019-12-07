#include <iostream>

namespace NS1 {
	int i;
	void print(int);
}

namespace NS2 {
	int i;
	void print(int i = 5000);
}


namespace NS3 {
	int i = 1;
	int z = 10;
	namespace NS4 {
		int i = 2;
		int j1 = i;
		int j2 = NS3::i;
	}
}

namespace NS5 {
	int z1 = NS3::z;
	using namespace NS3;
	int z2 = z;
}

namespace {
	int unnamed = 99;
}

//namespace ZZZ {
//	int unnamed = 99;
//}
//
//using namespace ZZZ;

namespace MyClass {
	class MyClass {};

	void func1(MyClass m) {
		std::cout << "func1()" << std::endl;
	}

	void func2(int m) {
		std::cout << "func2()" << std::endl;
	}

}

namespace VeryLongNamespaceName {
	int i = 12345;
}

namespace VLNN = VeryLongNamespaceName;

namespace NS1 {
	int i100 = 200;
}

using namespace std;

void main() {
	cout << "namespaces" << endl;
	
	NS1::i = 120;
	NS2::i = 240;

	NS1::print(NS2::i);
	NS2::print(NS1::i);

	cout << "i = " << NS3::i << endl;
	cout << "i = " << NS3::NS4::i << endl;
	cout << "j1 = " << NS3::NS4::j1 << endl;
	cout << "j2 = " << NS3::NS4::j2 << endl;

	cout << "z1 = " << NS5::z1 << endl;
	cout << "z2 = " << NS5::z2 << endl;

	unnamed = 100;
	cout << "unnamed = " << unnamed << endl;

	MyClass::MyClass m;
	func1(m);
	MyClass::func2(10);

	cout << VLNN::i << endl;
}

namespace NS1 {
	void print(int i) {
		cout << "NS1 i = " << i << endl;
	}
}

namespace NS2 {
	void print(int i) {
		cout << "NS2 i = " << i << endl;
	}
}
