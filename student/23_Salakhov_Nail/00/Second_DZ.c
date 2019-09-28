#include <stdio.h>
main() {
	int a, b, c, x;
	scanf_s("%d %d", &a, &b);
	c = a % b;
	x = (b > 0) ? b : -1 * b;
	printf("%d mod %d = %d", a, b, (c > 0) ? c : c + x);
}
