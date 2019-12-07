#include <stdio.h>

char c = 'a';
int i = 123456;
float f = 3.1415926535;
double d = 3.1415926535;
int main()
{

	printf("bef\\after: %6s\t%8s\t%10s\t%11s", "char", "int", "float", "double\n");
	char char1 = (char)c;
	int int1 = (int)c;
	float float1 = (float)c;
	double double1 = (double)c;
	printf("char:\t%8d\t%8d\t%10.2f\t%10.2f\n", char1, int1, float1, double1);
	char char2 = (char)i;
	int int2 = (int)i;
	float float2 = (float)i;
	double double2 = (double)i;
	printf("int:\t%8d\t%8d\t%10.2f\t%10.2f\n", char2, int2, float2, double2);
	char char3 = (char)f;
	int int3 = (int)f;
	float float3 = (float)f;
	double double3 = (double)f;
	printf("float:\t%8d\t%8d\t%10.2f\t%10.2f\n", char3, int3, float3, double3);
	char char4 = (char)d;
	int int4 = (int)d;
	float float4 = (float)d;
	double double4 = (double)d;
	printf("double:\t%8d\t%8d\t%10.2f\t%10.2f\n", char4, int4, float4, double4);
}