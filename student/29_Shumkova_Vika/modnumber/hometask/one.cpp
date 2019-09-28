#include <stdio.h>

int func(int a) {
	if (a < 0) return a * (-1);
	else return a;
}

int main() {
	int a,b,c;
 a=27;
 b =4;
 if (a >= 0) {
	 c = a / b;
	 c = a -func( b * c);
 }
 else if (b>=0) { c = a / b - 1;
 c = a - c*b;
 }
 else { c = a / b +1; 
 c = a - c * b; }

 printf("%d\n", c);
 printf("hello");
}