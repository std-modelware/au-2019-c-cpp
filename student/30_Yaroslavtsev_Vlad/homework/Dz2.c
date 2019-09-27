#include <stdio.h>
void main() {
	int a, b, c;
	scanf_s("%d%d", &a, &b);
	c = a % b;
	if (c < 0) {
		c *= (-1);
		printf("%d", c);
	}
	else {
		printf("%d", c);
	}

}