#include <stdio.h>

void main() {
	printf("statements\n");

	int a = 10;
	if (a == 10) {
		printf("1. a == 10\n");
	}

	if (a == 10) printf("2. a == 10\n");

	if (a != 10); printf("3. a == 10\n");

	if (a != 10) {
		printf("4. a != 10\n");
	}
	else {
		printf("5. a == 10\n");
	}

	if (a > 10) {
		printf("6. a > 10\n");
	}
	else if (a < 10) {
		printf("7. a < 10\n");
	}
	else {
		printf("8. a == 10\n");
	}

	/////////////////////
	int b = 1;
	switch (b)
	{
	case 1:
	{
		int j = 1;
		j++;
		printf("9. b == 1\n");
		break;
	}
	case 2:
		printf("10. b == 2\n");
		break;
	case 3:
		printf("11. b == 3\n");
		break;
	case 4:
		printf("12. b == 4\n");
		break;
	default:
		printf("14. b == ?\n");
		break;
	}

	////////////////
	for (int i1 = 0; i1 < 10; i1++) {
		printf("%d", i1);
	}
	printf("\n");

	int i1 = 0;
	for (; i1 < 10;) {
		printf("%d", i1++);
	}
	printf("\n");

	i1 = 0;
	for (; i1 < 10; i1++) {
		if (i1 == 8) break; // #75
		if (i1 < 3) continue; // #70
		printf("%d", i1);
	}
	printf("\n");

	////////////////
	int index = 0;
	do {
		if (index < 3) continue;
		printf("%d", index);
		if (index == 8) break;
	} while (index++ < 10);
	printf("\n");

	index = 0;
	while (index++ < 10) {
		if (index < 3) continue;
		printf("%d", index);
		if (index == 8) break;
	}
	printf("\n");

	printf("statements\n");
}