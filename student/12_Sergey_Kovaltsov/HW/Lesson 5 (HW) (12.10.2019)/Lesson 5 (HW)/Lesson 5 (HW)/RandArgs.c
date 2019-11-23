#include <stdio.h>

void RArgs(int count, int first, ...) {
	int *arg = &first;
	while (count--) {
		printf("%d\n", *arg);
		arg++;
	}
}


void main() {
	RArgs(3, 4, 7, 2);
}