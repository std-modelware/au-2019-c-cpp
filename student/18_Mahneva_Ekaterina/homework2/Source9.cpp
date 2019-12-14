#include <stdio.h>
#include <stdlib.h>

void main() {
	int a=-15;
	int b=4;
	int del;



	del = a % b;
	if (del < 0) {
		del = del + abs(b);
		printf("-15 4 %d\n", del);
	}
	else {
		printf("-15 4 %d\n", del);
	}

	a = -15;
	b = -7;

	del = a % b;
	if (del < 0) {
		del = del + abs(b);
		printf("-15 -7 %d\n", del);
	}
	else {
		printf("-15 -7 %d\n", del);
	}

	a = 113;
	b = -3;

	del = a % b;
	if (del < 0) {
		del = del + abs(b);
		printf("113 -3 %d\n", del);
	}
	else {
		printf("113 -3 %d\n", del);
	}

	a = 27;
	b = 4;

	del = a % b;
	if (del < 0) {
		del = del + abs(b);
		printf("27 4 %d\n", del);
	}
	else {
		printf("27 4 %d\n", del);
	}
}