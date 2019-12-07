#include <stdio.h>
#include <limits.h>

int global = 999;

extern int global2;

void main() {

	char c = 'a';
	int i = 123;
	float f = 3.1415926536;
	double d = 3.1415926536;

	printf("global = %d\n", global);
	printf("global2 = %d\n", global2);

	printf("c = %c\n", c);
	printf("i = %d\n", i);
	printf("f = %f\n", f);
	printf("d = %e\n", d);

	printf("c = %c(%d)\n", c, sizeof(c));
	printf("i = %d(%d)\n", i, sizeof(i));
	printf("f = %f(%d)\n", f, sizeof(f));
	printf("d = %e(%d)\n", d, sizeof(d));

	printf("f = %3.f\n", f);
	printf("f = %03.f\n", f);
	printf("f = %.10f\n", f);
	printf("f = %.10f\n", -1 * f);

	short int si = 10;
	long int li = 10;

	printf("i = %d(%d)\n", i, sizeof(i));
	printf("si = %d(%d)\n", si, sizeof(si));
	printf("li = %d(%d)\n", li, sizeof(li));

	printf("INT_MAX = %d\n", INT_MAX);

	si = -10;
	li = -10;

	unsigned short int usi = si;
	unsigned long int uli = li;
	
	printf("-------------\n");
	printf("si = %d(%d)\n", si, sizeof(si));
	printf("usi = %d(%d)\n", usi, sizeof(usi));
	
	printf("li = %d(%d)\n", li, sizeof(li));
	printf("uli = %lu(%d)\n", uli, sizeof(uli));

	{
		int a1 = 1;
		{
			int a2 = 2;
			{
				int a3 = 3;
				{
					int a4 = 4;
					a4++; // a4 = a4 + 1
					++a4; 
				}
				a3++;
				a3++;
			}
			a2++;
			a2++;
		}
		a1++;
		a1++;
	}


	register int z = 10;
	volatile int v = 10;


	float fl = 12.56;
	int i1 = fl;
	int i2 = (int)fl;


	printf("%d\n", i1);
	printf("%d\n", i2);
}

