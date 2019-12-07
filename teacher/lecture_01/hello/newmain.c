#include <stdio.h>
#include <limits.h>

int global = 999;

extern int global1;

void main() {
	printf("newmain.c\n");

	printf("global = %d\n", global);
	printf("global1 = %d\n", global1);

	global1 = 876;

	char c = 'a';
	int i = 123456;
	float f = 3.1415926536;
	double d = 3.1415926536;

	printf("c = %c\n", c);
	printf("i = %d\n", i);
	printf("f = %f\n", f);
	printf("d = %e\n", d);

	printf("f = %3.f\n", f);
	printf("f = %03.f\n", f);
	printf("f = %3.10f\n", f);
	printf("f = %3.10f\n", -1*f);

	printf("----------------\n");
	printf("c = %c(%d)\n", c, sizeof(c));
	printf("i = %d(%d)\n", i, sizeof(i));
	printf("f = %f(%d)\n", f, sizeof(f));
	printf("d = %e(%d)\n", d, sizeof(d));

	// спецификаторы

	short int si = 10;
	long int li = 10;

	printf("si = %d(%d)\n", si, sizeof(si));
	printf("li = %d(%d)\n", li, sizeof(li));

	printf("INT_MAX = %d\n", INT_MAX);

	si = -10;
	li = -10;

	unsigned short int usi = si;
	unsigned long int uli = li;

	printf("-===========-\n");
	printf("si = %d(%d)\n", si, sizeof(si));
	printf("usi = %u(%d)\n", usi, sizeof(usi));
	
	printf("li = %d(%d)\n", li, sizeof(li));
	printf("uli = %u(%d)\n", uli, sizeof(uli));

	{
		int a1 = 1;
		{
			int a2 = 2;
			{
				int a3 = 3;
				{
					int a4 = 4;
				}
				a3++; // a3 = a3 + 1
			}
			a2--;
		}
		a1++;
	}

	// переменные:
	// - локальные (объ¤влены в функции или блоке и только там используютс¤)
	// - глобальные
	// -- внешние (объ¤вл¤ютс¤ один раз в местах использовани¤ extern)
	// -- внутренние (их действие ограничего файлом)

	register int r = 10; // переменна¤ используетс¤ часто и ее лучше хранить в регистре (рекомендаци¤)

	volatile int v = 11; // переменна¤ может мен¤тьс¤ произвольно (не только из этого кода), поэтому ее лучше не оптимизировать

	float ft = 12.56;
	int i1 = ft;
	int i2 = (int)ft;

	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", i2);


}

