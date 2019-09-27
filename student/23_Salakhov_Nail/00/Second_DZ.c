#include <stdio.h>
main() {
	int a, b, c;
	scanf_s("%d %d", &a, &b);
	c = a % b;
	printf("%d mod %d = %d", a, b, (c > 0) ? c : -1 * c);
	/*
	  27 mod 4 is 3
	 -15 mod 4 is -3
	 113 mod -3 is 2
	 -15 mod -7 is -1
	*/
}