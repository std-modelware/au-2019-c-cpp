#include <stdio.h>
#include <limits.h>
char c;
int i;
float f;
double d;
int main()
{	
	printf("Input char = ");
	scanf_s("%c", &c);
	printf("\n");
	printf("           %6s\t%8s\t%10s\t%11s", "char", "int", "float", "double\n");

	char char1 = (char)c;
	int int1 = (int)c;
	float float1 = (float)c;
	double double1 = (double)c;
	printf("char:\t%8d\t%8d\t%10.2f\t%10.2f\n", char1, int1, float1, double1);
	printf("\n");
	printf("Input int = ");
	scanf_s("%d", &i);
	printf("\n");
	printf("           %6s\t%8s\t%10s\t%11s", "char", "int", "float", "double\n");
	
	char char2 = (char)i;
	int int2 = (int)i;
	float float2 = (float)i;
	double double2 = (double)i;
	printf("int:\t%8d\t%8d\t%10.2f\t%10.2f\n", char2, int2, float2, double2);
	printf("\n");
	printf("Input float = ");
	scanf_s("%f", &f);
	printf("\n");
	printf("           %6s\t%8s\t%10s\t%11s", "char", "int", "float", "double\n");

	char char3 = (char)f;
	int int3 = (int)f;
	float float3 = (float)f;
	double double3 = (double)f;
	printf("float:\t%8d\t%8d\t%10.2f\t%10.2f\n", char3, int3, float3, double3);
	
	printf("\n");
	printf("Input double = ");
	scanf_s("%lf", &d);
	printf("\n");
	printf("           %6s\t%8s\t%10s\t%11s", "char", "int", "float", "double\n");

	char char4 = (char)d;
	int int4 = (int)d;
	float float4 = (float)d;
	double double4 = (double)d;
	printf("double:\t%8d\t%8d\t%10.2f\t%10.2lf\n", char4, int4, float4, double4);

}