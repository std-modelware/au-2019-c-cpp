#include <iostream>

using namespace std;

int der(int a, int b) {
	
	if (a > 0 && b > 0) {
		return (a % b);
	} else if (a > 0 && b < 0) {
		return ((a % b));
	} else if (a < 0 && b > 0){
		return (b + (a % b));
	} else {
		return (- b + (a % b));
	}

}

void main() {

	int a, b;

	cin >> a;
	cin >> b;

	cout << der(a, b) << endl;

	system("pause");

}