#include <stdio.h>
int main() {
	char c = 'a';
	signed char sc = 'a';
	unsigned char uc = 'a';
	int i = 123456;
	short int shi = 123456;
	signed int si = 123456;
	unsigned int ui = 123456;
	float f = 3.141592;
	double d = 3.141592;
	long double ld = 3.141592;
	printf("%23s %9s %5s\t %5s\t %11s\t %11s\t %11s\t %15s\t %10s\t %10s\t \n", "***Bef\\Aft***     Char:", "Sig Ch:", "Un Ch:", "Int:", "Sh Int:", "Sig Int:", "Un int:", "Flt:", "Dbl:", "L Dbl:");

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Char:", (char) c, (signed char) c, (unsigned char) c, (int) c, (short int) c, (signed int) c, (unsigned int) c, (float) c, (double) c, (long double) c);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Signed Char:", (char)sc, (signed char)sc, (unsigned char)sc, (int)sc, (short int)sc, (signed int)sc, (unsigned int)sc, (float)sc, (double)sc, (long double)sc);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Unsigned Char:", (char)uc, (signed char)uc, (unsigned char)uc, (int)uc, (short int)uc, (signed int)uc, (unsigned int)uc, (float)uc, (double)uc, (long double)uc);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Integer:", (char)i, (signed char)i, (unsigned char)i, (int)i, (short int)i, (signed int)i, (unsigned int)i, (float)i, (double)i, (long double)i);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Short Int:", (char)shi, (signed char)shi, (unsigned char)shi, (int)shi, (short int)shi, (signed int)shi, (unsigned int)shi, (float)shi, (double)shi, (long double)shi);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Signed Int:", (char)si, (signed char)si, (unsigned char)si, (int)si, (short int)si, (signed int)si, (unsigned int)si, (float)si, (double)si, (long double)si);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Unsigned int:", (char)ui, (signed char)ui, (unsigned char)ui, (int)ui, (short int)ui, (signed int)ui, (unsigned int)ui, (float)ui, (double)ui, (long double)ui);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Float:", (char)f, (signed char)f, (unsigned char)f, (int)f, (short int)f, (signed int)f, (unsigned int)f, (float)f, (double)f, (long double)f);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n", "Double:", (char)d, (signed char)d, (unsigned char)d, (int)d, (short int)d, (signed int)d, (unsigned int)d, (float)d, (double)d, (long double)d);

	printf("%15s\t| %3c\t| %3c\t| %3c\t| %10d\t| %10hi\t| %10i\t| %10u\t| %14f\t| %10lf\t| %10Lf\t \n",  "Long Double:", (char)ld, (signed char)ld, (unsigned char)ld, (int)ld, (short int)ld, (signed int)ld, (unsigned int)ld, (float)ld, (double)ld, (long double)ld);

}