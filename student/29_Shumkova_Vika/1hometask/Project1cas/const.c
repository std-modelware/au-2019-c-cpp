#include <stdio.h>

void main() {
	printf("const\n");
	const double PI = 3.14;
	 //PI = 3.15;

	enum {
		ONE = 1,
	TWO,
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

	enum BOOLEAN {
		B_NEW_FAlSE,
		B_NEW_TRUE,
	};


	//usigned short int z = 12;

	//typedef unsigned short int USHORT;

	//USHORT
		//-------------

		//if (0) {
		//	print("OK - 0\n")
		//}


	//--------------
	int z = 1;
	printf("result = %d\n", (z == 1) ? 100 : 200);
	printf("result = %d\n", (z != 1) ? 100 : 200);

	printf("const\n");
}