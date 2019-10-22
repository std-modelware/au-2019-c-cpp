#include <stdio.h>

int	multy(int n, int a1, ...) {
	int mult = 1;
	int* p = &a1;
	while (n--) {
		mult *= *p;
		p++;
	}
	return mult;
}

void main() {
	int answer = multy(6, 2, 2, 2, 2, 2, 2);
	printf("answer = %d", answer);
}
