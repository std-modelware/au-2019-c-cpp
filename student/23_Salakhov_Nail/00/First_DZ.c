#include <stdio.h>
main(){
	char z = 'X';
	int a = -1111;
	float b = 1.1;
	double c = 11.1111111111;
	printf("z = %c\na = %d\nb = %f\nc = %e \n", z, a, b, c);
	printf("char to int z = %d\n", z);
	printf("char to unsigned int z = %u\n", z);
	printf("char to float z = %f\n", z);
	printf("char to double z = %lf\n", z);
	printf("int to char a = %c\n", a);
	printf("int to float a = %f\n", a);
	printf("int to double a = %lf\n", a);
	printf("int to unsigned int a = %u\n", a);
	printf("float to int b = %d\n", b);
	printf("float to unsigned int b = %u\n", b);
	printf("float to char b = %c\n", b);
	printf("float to double b = %lf\n", b);
	printf("double to int c = %d\n", c);
	printf("double to unsigned int c = %u\n", c);
	printf("double to float c = %f\n", c);
	printf("double to char c = %c\n", c);

}

