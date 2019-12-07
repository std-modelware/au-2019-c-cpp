#include <stdio.h>

int mod( int p, int q ){
	int r = p % q;
	if(r < 0){
		if(q < 0) q *= -1;
		r += q;
	}
	return r;
}

int main() {

	int x1, x2;

	scanf_s("%d %d", &x1, &x2);
	printf("%d\n", mod(p, q));

	return 0;
}