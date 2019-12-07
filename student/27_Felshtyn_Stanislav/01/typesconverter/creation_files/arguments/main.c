#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void summ(int a,...) {
	int *s = &a;
	int sum = 0;
	while (*s) {
		sum = sum + (*s);
		s++;
	}
	printf("Your sum = %d", sum);
}	

void main() {
	summ(10, 20, 30, 40, 50, 0);
}