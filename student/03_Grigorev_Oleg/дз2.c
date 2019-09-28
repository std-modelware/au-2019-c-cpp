#include <stdio.h>

void main() {

	int a = -15;
	int b = -7;

	if (a > 0)
	{
		if (b > 0)
		{
			while (a >= b)
			{
				a -= b;
			}
		}
		else if (b < 0)
		{
			while (a >= -b)
			{
				a += b;
			}
			a = -a;
		}
	}
	else if (a < 0)
	{
		if (b > 0)
		{
			while (a <= -b)
			{
				a += b;
			}
		}
		else if (b < 0)
		{
			while (a <= b)
			{
				a -= b;
			}
			a = -a;
		}
	}

	printf("%d\n", a);

}