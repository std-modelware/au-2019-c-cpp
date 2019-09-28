#include <stdio.h>
int main() {

	printf("TYPES CONVERSION \n\n");

	printf("CHAR \n");
	char ch = '9';
	printf("ch = %c\n",ch);
	printf("char to int  = %d\n", ch);
	printf("char to signed int  = %i\n", ch);
	printf("char to unsigned int  = %u\n", ch);
	printf("char to unsigned short int  = %hu\n", ch);
	printf("char to unsigned long int  = %lu\n", ch);
	printf("char to float  = %.2f\n", ch);
	printf("char to double = %.2f\n\n", ch);

	printf("INT \n");
	int i = -5;
	printf("i = %d \n",i);
	printf("int to signed int  = %i\n", i);
	printf("int to unsigned int  = %u\n", i);
	printf("int to unsigned short int  = %hu\n", i);
	printf("int to unsigned long int  = %lu\n", i);
	printf("int to float  = %.2f\n", i);
	printf("int to double  = %.2f\n", i);
	printf("int to char = %c\n\n", i);

	printf("FLOAT \n");
	float f = -1.1;
	printf("f = %.2f\n", f);
	printf("float to int  = %d\n", f);
	printf("float to signed int  = %i\n", f);
	printf("float to unsigned int  = %u\n", f);
	printf("float to unsigned short int  = %hu\n", f);
	printf("float to unsigned long int  = %lu\n", f);
	printf("float to double  = %.2f\n", f);
	printf("float to char  = %c\n\n", f);

	printf("DOUBLE \n");
	double d = -1.1;
	printf("d = %.2f \n", d);
	printf("double to int  = %d\n", d);
	printf("double to signed int  = %i\n", d);
	printf("double to unsigned int  = %u\n", d);
	printf("double to unsigned short int  = %hu\n", d);
	printf("double to unsigned long int  = %lu\n", d);
	printf("double to float  = %.2f\n", d);
	printf("double to long double = %Lf\n");
	printf("double to char  = %c\n\n", d);

}