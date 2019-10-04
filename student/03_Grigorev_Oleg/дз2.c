#include <stdio.h>

void main() {
	int a = -15;
	int b = -7;
	int c = 0;
	
	if (a > 0 && b > 0)
		while (a >= b) {
			a -= b;
		}

	if (a > 0 && b < 0)
		while (-a <= b) {
			a += b;
		}

	if (a < 0 && b > 0)
		while (-a >= b || a < 0) {
			a += b;
		}

	if (a < 0 && b < 0)
		while (a <= b || a < 0) {
			a -= b;
		}

	printf("%d\n", a);

}