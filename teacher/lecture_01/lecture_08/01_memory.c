#include <stdio.h>
#include <memory.h>

#define ARR_SIZE 10

void main() {
	printf("memcpy error\n");

	int *pi;

	pi = calloc(sizeof(int), ARR_SIZE);

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
		memcpy(pi, pi + 1, sizeof(int));
		pi++;
	}

	pi -= (ARR_SIZE - 1);
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d ", *pi++);
	}
	printf("\n");


}