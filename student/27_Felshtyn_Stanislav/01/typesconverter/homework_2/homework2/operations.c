#include <stdio.h>

void main () {
	int a, b;
	int i, c;
	i = 0;
	printf("Input your numbers\n");
	scanf_s("%d%d", &a, &b);
	if (b == 0) {
		printf("Cannot be divided by 0\n");
	}
	else {
		c = a % b;
		printf("%d\n", c);
		/*if ((a > 0) && (b > 0)) {
			c = a % b;
			printf("Your result = %d\n", c);
		}*/
		/*if ((a > 0) && (b < 0)) {
			c = a % b;
			printf("Your result = %d\n", c);
		}*/
		if ((a < 0) && (b > 0)) {
			//c = a % b;
			//printf("%d\n", c);
			do {
				if (a % b == 0) {
					printf("Your result = %d\n", i);
					break;
				}
				else {
					i++;
					a--;
				}
			} while ((a % b == 0));
		}
		/*if ((a < 0) && (b < 0)) {
			c = a % b;
			printf("your result = %d\n", c);
		}*/
	}
}