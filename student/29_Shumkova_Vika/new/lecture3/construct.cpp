#include <stdio.h>

void main() {
	int a = 10;
		if (a == 10) {
			printf("1. a ==10\n");
		}

		if (a == 10) {
			printf("4\n");
		}
		else {
			printf("5\n");
		}
		//////////////
		int b = 1;
		switch (b)
		{
		case 1: printf("2");
			break;
		case 2: printf("3");
		default:
		}
		////////////
		for (int i1 = 0, j1 = 1; i1 < 10; i1++) {
			printf("%d", i1);

		}
		///////////
		int y = 0;
		do {
			printf("%d", y);
		} while (y++ < 10);
	
		while (y++<10) {
			printf("%d", y);
		};
		//////////////
}
void funnc() {
	printf("hi");
 }
int myfun(int p) {
	return p + 1;
}

void main() {
	funnc();
}
//////////////
void main() {
	int a = 100;
	while (a % 2 == 0) {
		a = a/2;
	}
	printf("a=%d\n");
}
/////////////////////
int myfuncw(int u) {
	if (u % 2 == 0) {
		return myfuncw(u >> 1);
	}
	else return u;
}
int myfer(int a) {
	return(a % 2 == 0) ? myfer(a >> 1) : a;
 }