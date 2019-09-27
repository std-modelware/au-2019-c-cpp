#include <stdio.h>
void main() {
	signed char sc = 'a';
	unsigned char uc = 'g';
	char c = 'w';

	int i = 123;
	long int li = -2147483648;
	short int si = -32767;
	unsigned int ui = 30000;
	unsigned short int usi = 65535;
	unsigned long int uli = 4294967295;

	float f = 3.1415926536;
	double d = 6.1415926536;
	long double ld = 8.988466;

	printf("type          uchar     char      int       lint      sint      uint      usint     ulint     float     double    ld\n");
	printf("schar    %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		sc, (unsigned char)sc, (int)sc, (long int)sc, (short int)sc, (unsigned int)sc, (unsigned short int)sc, (unsigned long int)sc,
		(float)sc, (double)sc, (long double)sc);
	printf("uchar    %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)uc, (unsigned char)uc, (int)uc, (long int)uc, (short int)uc, (unsigned int)uc, (unsigned short int)uc, (unsigned long int)uc,
		(float)uc, (double)uc, (long double)uc);
	printf("char     %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)c, (unsigned char)c, (int)c, (long int)c, (short int)c, (unsigned int)c, (unsigned short int)c, (unsigned long int)c,
		(float)c, (double)c, (long double)c);
	printf("int      %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)i, (unsigned char)i, (int)i, (long int)i, (short int)i, (unsigned int)i, (unsigned short int)i, (unsigned long int)i,
		(float)i, (double)i, (long double)i);
	printf("lint     %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)li, (unsigned char)li, (int)li, (long int)li, (short int)li, (unsigned int)li, (unsigned short int)li, (unsigned long int)li,
		(float)li, (double)li, (long double)li);
	printf("sint     %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)si, (unsigned char)si, (int)si, (long int)si, (short int)si, (unsigned int)si, (unsigned short int)si, (unsigned long int)si,
		(float)si, (double)si, (long double)si);
	printf("uint     %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)ui, (unsigned char)ui, (int)ui, (long int)ui, (short int)ui, (unsigned int)ui, (unsigned short int)ui, (unsigned long int)ui,
		(float)ui, (double)ui, (long double)ui);
	printf("usint    %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)usi, (unsigned char)usi, (int)usi, (long int)usi, (short int)usi, (unsigned int)usi, (unsigned short int)usi, (unsigned long int)usi,
		(float)usi, (double)usi, (long double)usi);
	printf("ulint    %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(unsigned char)uli, (unsigned char)uli, (int)uli, (long int)uli, (short int)uli, (unsigned int)uli, (unsigned short int)uli, (unsigned long int)uli,
		(float)uli, (double)uli, (long double)uli);
	printf("float    %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(char)f, (unsigned char)f, (int)f, (long int)f, (short int)f, (unsigned int)f, (unsigned short int)f, (unsigned long int)f,
		(float)f, (double)f, (long double)f);
	printf("double   %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(char)d, (unsigned char)d, (int)d, (long int)d, (short int)d, (unsigned int)d, (unsigned short int)d, (unsigned long int)d,
		(float)d, (double)d, (long double)d);
	printf("ldouble  %10c%10c%10d%10ld%10d%10u%10u%10lu%10f%10f%10Le\n",
		(char)ld, (unsigned char)ld, (int)ld, (long int)ld, (short int)ld, (unsigned int)ld, (unsigned short int)ld, (unsigned long int)ld,
		(float)ld, (double)ld, (long double)ld);

}