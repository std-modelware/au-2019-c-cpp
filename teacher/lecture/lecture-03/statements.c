#include <stdio.h>

void main() {
	printf("statements\n");

	int a = 10;
	if (a == 10) {
		printf("a == 10\n");
	}

	if (a != 10) printf("a == 10\n");

	if (a == 10) {
		printf("a == 10\n");
	}
	else {
		printf("a != 10\n");
	}

	if (a > 10) {
		printf("a > 10\n");
	}
	else if (a < 10) {
		printf("a < 10\n");
	}
	else {
		printf("a == 10\n");
	}

	///////
	int b = 2;
	switch (b) {
	case 1:
	{
		int z = 1;
		z = z - 10;
		printf("b == 1 - %d\n", z);
		break;
	}
	case 2:
	case 3:
		printf("b == 2 or b == 3\n");
		break;
	case 4:
		printf("b == 4\n");
		break;
	default:
		printf("b == ?\n");
		break;
	}

	///////////
	for (int i = 0;  i < 10; i++) {
		printf("%d", i);
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		if (i == 8) break;
		if (i < 3) continue;
		printf("%d", i);
	}
	printf("\n");

	////////////
	int index = 0;
	do {
		if (index == 8) break;
		if (index < 3) continue;
		printf("%d", index);
	} while (index++ < 10);
	printf("\n");

	index = 0;
	while (index < 10) {
		printf("%d", index++);
	}
	printf("\n");

	printf("statements\n");
}