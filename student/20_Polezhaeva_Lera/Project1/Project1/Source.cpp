#include <stdio.h>
#include < stdlib.h >  

int main() {
	int a = 113;
	int b = -3;
	int c;
	if (a >= 0) {
		c = a - abs(b * (a/b));
	            }
	else if (b > 0) {
		c = a / b - 1;
		c = a - c * b;
	                 }
	else {
		c = a / b + 1;
		c = a - c * b;
	     }
	printf("%d\n",c);
}