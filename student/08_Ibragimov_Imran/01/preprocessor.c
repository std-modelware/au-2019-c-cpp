#include <stdio.h>

void main() {
	printf("preprocessor\n");

	int n = 27;
	int divideby = 4;


#define MOD printf("%d mod %d = %u \n", n, divideby, n%divideby > 0 ? (n%divideby): -(n%divideby));  

	MOD

	 n = -15;
	 divideby = 4;

	MOD

	 n = 113;
	 divideby = 3;

	MOD

	 n = -15;
	 divideby = -7;

	MOD


}