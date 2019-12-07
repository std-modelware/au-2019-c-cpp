#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int summ( int num, int first, ...) {
	int sum = 0;
	int testsum = 0;
	int* p = &first;
	while (num--) {
		sum += *p;
		/*if (testsum >= sum) {
			sum = testsum;
		}
		else {
			exit(1);
		}*/
		p++;
	}
	return sum;
}

void main() {

	int sum = summ(5, 1, 2, 3, 4, 5);
	printf("summ = %d\n", sum);
	sum = summ(7, 0, 27, 0, 4, 5, 60, 33);
	printf("summ = %d\n", sum);
	
}