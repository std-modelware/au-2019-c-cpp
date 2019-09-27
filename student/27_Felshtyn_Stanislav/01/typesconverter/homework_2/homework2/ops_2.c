#include <stdio.h>
#include <stdlib.h>

void main() {
	int a, b, c, d, l; 
	printf("Input your numbers\n");
	scanf_s("%d%d", &a, &b);
	c = a / b;
	printf("%d\n", c);
	if (b != 0) {
		if ((a > 0) && (b > 0)) {		// > >
			c = a / b;
			d = b * c;
			l = a - d;
			printf("%d", l);
		}
		if ((a < 0) && (b > 0)) {		// < >
			c = a / b; 
			if ((b * c == a)) {
				printf("%d", 0);
			}
			else {
				c--;		//-4
				d = b * c; //-16
				l = a - d;
				printf("%d", l);
			}
		}
		if ((a > 0) && (b < 0)) {		// > <
			c = a / b;
			if ((b * c == a)) {
				printf("%d", 0);
			}
			else {
				d = b * c;
				l = a - d;
				printf("%d", l);
			}
		}
		if ((a < 0) && (b < 0)) {		// < <
			c = a / b;
			if ((b * c == a)) {
				printf("%d", 0);
			}
			else {
				c++;
				d = b * c;
				l = a - d;
				printf("%d", l);
			}
		}
	}
	else {
		printf("Division is impossible!");
	}
}