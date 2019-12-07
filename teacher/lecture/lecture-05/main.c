#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("memory\n");

	int *pi1 = malloc(sizeof(int));
	printf("%p = %d\n", pi1, _msize(pi1));

	int *pi2 = malloc(sizeof(int) * 2);
	printf("%p = %d\n", pi2, _msize(pi2));

	int *pi3 = calloc(sizeof(int), 2);
	printf("%p = %d\n", pi3, _msize(pi3));

	*pi1 = 12;

	int *pi4 = calloc(sizeof(int), 1000000000000);
	if (pi4 == NULL) {
		printf("not enough memory\n");
	}
	else {
		printf("%p = %d\n", pi4, _msize(pi4));
	}

	pi1 = realloc(pi1, sizeof(int) * 3);

	free(pi1);
	free(pi2);
	free(pi3);

	printf("memory\n");
}