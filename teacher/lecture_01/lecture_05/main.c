#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("memory\n");

	int *pi1 = (int *) malloc(sizeof(int));
	printf("pi1 = %p - %d\n", pi1, _msize(pi1));

	int *pi2 = (int *) malloc(sizeof(int) * 2);
	printf("pi2 = %p - %d\n", pi2, _msize(pi2));

	int *pi3 = (int *) calloc(sizeof(int), 10); // обнуляется содержимое памяти
	printf("pi3 = %p - %d\n", pi3, _msize(pi3));

	*pi1 = 1;

	int *pi4 = (int *)calloc(sizeof(int), 100000000000);
	if (pi4 == NULL) 
		printf("not enough memory\n");
	else
		printf("pi4 = %p - %d\n", pi4, _msize(pi4));

	pi1 = realloc(pi1, sizeof(int) * 3);
	printf("pi1 = %p - %d\n", pi1, _msize(pi1));

	free(pi1);
	free(pi2);
	free(pi3);

	printf("memory\n");
}