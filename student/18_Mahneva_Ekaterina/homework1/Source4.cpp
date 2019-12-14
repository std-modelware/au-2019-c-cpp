#include <stdio.h>

void main() {
	int i = 88;
	char c;
	float f;
	double d;
	unsigned int u;

	c = (char)i;
	f = (float)i;
	d = (double)i;
	u = (unsigned int)i;
	printf("c=%c\n",c);
	printf("f=%f\n",f);
	printf("d=%d\n",d);
	printf("u=%u\n",u);

	//------------------
	c = 'y';
	i = (int)c;
	f = (float)c;
	d = (double)c;
	u = (unsigned int)c;
	printf("i=%i\n", i);
	printf("f=%f\n", f);
	printf("d=%d\n", d);
	printf("u=%u\n", u);

	//-------------------
	f = 5.2;
	c = (char)f;
	i = (int)f;
	d = (double)f;
	u = (unsigned int)f;
	printf("c=%c\n", c);
	printf("i=%i\n", i);
	printf("d=%d\n", d);
	printf("u=%u\n", u);

	//-------------------
	d = 5161156.1658194;
	c = (char)d;
	i = (int)d;
	f = (float)d;
	u = (unsigned int)d;
	printf("c=%c\n", c);
	printf("i=%i\n", i);
	printf("f=%f\n", f);
	printf("u=%u\n", u);

	}