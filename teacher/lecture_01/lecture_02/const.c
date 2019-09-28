#include <stdio.h>

void main() {
	printf("const\n");

	const double PI = 3.14;

	// PI = 3.15;

	enum {
		ONE = 2,
		TWO = 8,
		THREE
	};

	printf("ONE = %d\n", ONE);
	printf("TWO = %d\n", TWO);
	printf("THREE = %d\n", THREE);

	enum BOOLEAN {
		B_FALSE,
		B_TRUE
	} b5, b6 = B_TRUE, b7;

	enum BOOLEAN b1 = B_FALSE, g6;
	int b2 = B_TRUE;

	typedef unsigned short int USHORT;
	USHORT x = 18;


	if (0) {
		printf("OK - 0\n");
	}
	else {
		printf("NOT OK - 0\n");
	}

	if (1) {
		printf("OK - 1\n");
	}
	else {
		printf("NOT OK - 1\n");
	}

	if (100) {
		printf("OK - 100\n");
	}
	else {
		printf("NOT OK - 100\n");
	}

	int z = 1;
	int t = (z == 1) ? 100 : 200;

	printf("result = %d\n", (z == 1) ? 100 : 200);
	printf("result = %d\n", (z != 1) ? 100 : 200);

	printf("const\n");
}