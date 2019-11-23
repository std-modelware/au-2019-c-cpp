#include <stdio.h>

void main() {
	printf("const\n");

	const double PI = 3.14;

	// PI = 3.15;

	enum {
		ONE = 1,
		TWO = 6,
		THREE
	};

	printf("ONE = %d\n", ONE);
	printf("TWO = %d\n", TWO);
	printf("THREE = %d\n", THREE);

	enum BOOLEAN {
		B_FALSE,
		B_TRUE
	};

	enum BOOLEAN b1;
	b1 = B_FALSE;
	int b2 = B_TRUE;
	int b3 = (enum BOOLEAN) B_FALSE;

	enum NEWBOOLEAN {
		B_NEW_FALSE,
		B_NEW_TRUE,
	} bvar, b1var = B_NEW_FALSE;

	unsigned short int z2 = 12;

	typedef unsigned short int USHORT;
	USHORT z1 = 13;

	// ----------------
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

	// ----------------
	int z = 1;
	printf("result = %d\n", (z == 1) ? 100 : 200);
	printf("result = %d\n", (z != 1) ? 100 : 200);

	printf("const\n");
}