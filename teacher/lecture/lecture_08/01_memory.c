#include <stdio.h>
#include <memory.h>
#include <assert.h>

#define ARR_SIZE 10

void main() {
	int *pi;

	pi = calloc(sizeof(int), ARR_SIZE);

	assert(pi != NULL);

	for (int i = 0; i < ARR_SIZE; i++) {
		*pi++ = i;
	}

	pi -= ARR_SIZE;
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d ", *pi++);
	}
	printf("\n");

	pi -= ARR_SIZE;
	//memcpy(pi, pi + 1, ARR_SIZE - 1);

	for (int i = 0; i < ARR_SIZE - 1; i++) {
		memcpy(pi, pi + 1, 1);
		pi++;
	}

	pi -= (ARR_SIZE - 1);
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d ", *pi++);
	}
	printf("\n");

}