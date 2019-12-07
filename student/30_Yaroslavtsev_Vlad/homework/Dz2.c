#include <stdio.h>
#include <math.h>
void main() {
	int a, b, c;
	scanf_s("%d%d", &a, &b);
	c = a % b;
	if (a < 0) {	
		printf("%d", abs(b) - abs(a) % abs(b));
	}
	else {
		printf("%d", c);
	}

}