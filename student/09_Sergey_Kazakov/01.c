#include <stdio.h>

int main() {

	char c = -120;
	unsigned char uc = 250;

	int i = -10000;
	unsigned int ui = 200000;
	short int si = -10;
	long int li = -10000000000;

	double d = -3.1415;
	long double ld = -1000000.5;

	float f = -1.618;

	printf("char: %d\n", c);
	printf("char to unsigned char: %u\n", (unsigned char)c);
	printf("char to int: %d\n", (int)c);
	printf("char to short int: %d\n", (short int)c);
	printf("char to long int: %l\n", (long int)c);
	printf("char to double: %f\n", (double)c);
	printf("char to long double: %lf\n", (long double)c);
	printf("char to float: %f\n\n", (float)c);

	printf("unsigned char: %d\n", uc);
	printf("unsigned char to char: %u\n", (char)uc);
	printf("unsigned char to int: %d\n", (int)uc);
	printf("unsigned char to short int: %d\n", (short int)uc);
	printf("unsigned char to long int: %l\n", (long int)uc);
	printf("unsigned char to double: %f\n", (double)uc);
	printf("unsigned char to long double: %lf\n", (long double)uc);
	printf("unsigned char to float: %f\n\n", (float)uc);

	printf("int: %d\n", i);
	printf("int to char: %d\n", (char)i);
	printf("int to unsigned char: %u\n", (unsigned char)i);
	printf("int to short int: %d\n", (short int)i);
	printf("int to long int: %l\n", (long int)i);
	printf("int to double: %f\n", (double)i);
	printf("int to long double: %lf\n", (long double)i);
	printf("int to float: %f\n\n", (float)i);

	printf("short int: %d\n", si);
	printf("short int to char: %d\n", (char)si);
	printf("short int to unsigned char: %u\n", (unsigned char)si);
	printf("short int to int: %d\n", (int)si);
	printf("short int to long int: %l\n", (long int)si);
	printf("short int to double: %f\n", (double)si);
	printf("short int to long double: %lf\n", (long double)si);
	printf("short int to float: %f\n\n", (float)si);

	printf("long int: %l\n", li);
	printf("long int to char: %d\n", (char)li);
	printf("long int to unsigned char: %u\n", (unsigned char)li);
	printf("long int to short int: %l\n", (short int)li);
	printf("long int to int: %d\n", (int)li);
	printf("long int to double: %f\n", (double)li);
	printf("long int to long double: %lf\n", (long double)li);
	printf("long int to float: %f\n\n", (float)li);

	printf("double: %f\n", d);
	printf("double to char: %d\n", (char)d);
	printf("double to unsigned char: %u\n", (unsigned char)d);
	printf("double to short int: %l\n", (short int)d);
	printf("double to int: %d\n", (int)d);
	printf("double to long int: %d\n", (long int)d);
	printf("double to long double: %lf\n", (long double)d);
	printf("double to float: %f\n\n", (float)d);

	printf("long double: %lf\n", ld);
	printf("long double to char: %d\n", (char)ld);
	printf("long double to unsigned char: %u\n", (unsigned char)ld);
	printf("long double to short int: %l\n", (short int)ld);
	printf("long double to int: %d\n", (int)ld);
	printf("long double to long int: %d\n", (long int)ld);
	printf("long double to double: %f\n", (double)ld);
	printf("long double to float: %f\n\n", (float)ld);

	printf("float: %f\n", f);
	printf("float to char: %d\n", (char)f);
	printf("float to unsigned char: %u\n", (unsigned char)f);
	printf("float to short int: %l\n", (short int)f);
	printf("float to int: %d\n", (int)f);
	printf("float to long int: %d\n", (long int)f);
	printf("float to double: %f\n", (double)f);
	printf("float to long double: %lf\n\n", (long double)f);

	return 0;
}