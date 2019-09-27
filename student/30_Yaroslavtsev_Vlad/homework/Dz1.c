#include <stdio.h>
void main() {
	
	int i = 91;
	long int lng_i = 7483648;
	short int shrt_i = -32767;
	unsigned int unsgnd_i = 123;
	unsigned short int unsgnd_shrt_i = 65535;
	unsigned long int unsgnd_lng_i = 29000295;
	
	signed char sgnd_chr = 'a';
	unsigned char unsgnd_chr = 'b';
	char chr = 'c';

	float flt = 1.1754943;
	double dbl = 2.2250738585072014;
	long double lng_dbl = 3.402823466;

	
	printf("signed char -> unsigned char   %6c\n", (unsigned char)sgnd_chr);
	printf("signed char -> char   %15c\n", (char)sgnd_chr);
	printf("signed char -> int   %17d\n", (int)sgnd_chr);
	printf("signed char -> long int   %12ld\n", (long int)sgnd_chr);
	printf("signed char -> short int   %11hi\n", (short int)sgnd_chr);
	printf("signed char -> unsigned int   %8u\n", (unsigned int)sgnd_chr);
	printf("signed char -> unsigned short int   %2hu\n", (unsigned short int)sgnd_chr);
	printf("signed char -> unsigned long int   %3lu\n", (unsigned long int)sgnd_chr);
	printf("signed char -> float   %22f\n", (float)sgnd_chr);
	printf("signed char -> double   %21f\n", (double)sgnd_chr);
	printf("signed char -> long double   %19Le\n\n\n", (long double)sgnd_chr);

	printf("unsigned char -> signed char   %8c\n", (signed char)unsgnd_chr);
	printf("unsigned char -> char   %15c\n", (char)unsgnd_chr);
	printf("unsigned char -> int   %17d\n", (int)unsgnd_chr);
	printf("unsigned char -> long int   %12ld\n", (long int)unsgnd_chr);
	printf("unsigned char -> short int   %11hi\n", (short int)unsgnd_chr);
	printf("unsigned char -> unsigned int   %8u\n", (unsigned int)unsgnd_chr);
	printf("unsigned char -> unsigned short int   %2hu\n", (unsigned short int)unsgnd_chr);
	printf("unsigned char -> unsigned long int   %3lu\n", (unsigned long int)unsgnd_chr);
	printf("unsigned char -> float   %22f\n", (float)unsgnd_chr);
	printf("unsigned char -> double   %21f\n", (double)unsgnd_chr);
	printf("unsigned char -> long double   %19Le\n\n\n", (long double)unsgnd_chr);
	
	printf("char -> signed char   %8c\n", (signed char)chr);
	printf("char -> unsigned char   %6c\n", (unsigned char)chr);
	printf("char -> int   %17d\n", (int)chr);
	printf("char -> long int   %12ld\n", (long int)chr);
	printf("char -> short int   %11hi\n", (short int)chr);
	printf("char -> unsigned int   %8u\n", (unsigned int)chr);
	printf("char -> unsigned short int   %2hu\n", (unsigned short int)chr);
	printf("char -> unsigned long int   %3lu\n", (unsigned long int)chr);
	printf("char -> float   %22f\n", (float)chr);
	printf("char -> double   %21f\n", (double)chr);
	printf("char -> long double   %19Le\n\n\n", (long double)chr);
	
	printf("int -> signed char   %8c\n", (signed char)i);
	printf("int -> unsigned char   %6c\n", (unsigned char)i);
	printf("int -> int   %17d\n", (int)i);
	printf("int -> long int   %12ld\n", (long int)i);
	printf("int -> short int   %11hi\n", (short int)i);
	printf("int -> unsigned int   %8u\n", (unsigned int)i);
	printf("int -> unsigned short int   %2hu\n", (unsigned short int)i);
	printf("int -> unsigned long int   %3lu\n", (unsigned long int)i);
	printf("int -> float   %22f\n", (float)i);
	printf("int -> double   %21f\n", (double)i);
	printf("int -> long double   %19Le\n\n\n", (long double)i);
	
	printf("long int -> signed char   %10c\n", (signed char)lng_i);
	printf("long int -> unsigned char   %10c\n", (unsigned char)lng_i);
	printf("long int -> int   %20d\n", (int)lng_i);
	printf("long int -> long int   %15ld\n", (long int)lng_i);
	printf("long int -> short int   %12hi\n", (short int)lng_i);
	printf("long int -> unsigned int   %11u\n", (unsigned int)lng_i);
	printf("long int -> unsigned short int %1hu\n", (unsigned short int)lng_i);
	printf("long int -> unsigned long int  %5lu\n", (unsigned long int)lng_i);
	printf("long int -> float   %25f\n", (float)lng_i);
	printf("long int -> double   %24f\n", (double)lng_i);
	printf("long int -> long double   %17Le\n\n\n", (long double)lng_i);
	
	printf("short int -> signed char   %8c\n", (signed char)shrt_i);
	printf("short int -> unsigned char   %6c\n", (unsigned char)shrt_i);
	printf("short int -> int     %19d\n", (int)shrt_i);
	printf("short int -> long int     %14ld\n", (long int)shrt_i);
	printf("short int -> short int     %13hi\n", (short int)shrt_i);
	printf("short int -> unsigned int   %16u\n", (unsigned int)shrt_i);
	printf("short int -> unsigned short int   %5hu\n", (unsigned short int)shrt_i);
	printf("short int -> unsigned long int    %6lu\n", (unsigned long int)shrt_i);
	printf("short int -> float     %24f\n", (float)shrt_i);
	printf("short int -> double     %23f\n", (double)shrt_i);
	printf("short int -> long double    %19Le\n\n\n", (long double)shrt_i);

	printf("unsigned int -> signed char    %6c\n", (signed char)unsgnd_i);
	printf("unsigned int -> unsigned char  %6c\n", (unsigned char)unsgnd_i);
	printf("unsigned int -> int   %17d\n", (int)unsgnd_i);
	printf("unsigned int -> long int   %12ld\n", (long int)unsgnd_i);
	printf("unsigned int -> short int   %11hi\n", (short int)unsgnd_i);
	printf("unsigned int -> unsigned int   %8u\n", (unsigned int)unsgnd_i);
	printf("unsigned int -> unsigned short int  %2hu\n", (unsigned short int)unsgnd_i);
	printf("unsigned int -> unsigned long int   %3lu\n", (unsigned long int)unsgnd_i);
	printf("unsigned int -> float   %22f\n", (float)unsgnd_i);
	printf("unsigned int -> double   %21f\n", (double)unsgnd_i);
	printf("unsigned int -> long double  %19Le\n\n\n", (long double)unsgnd_i);

	printf("unsigned short int -> signed char   %6c\n", (signed char)unsgnd_shrt_i);
	printf("unsigned short int -> unsigned char   %16c\n", (unsigned char)unsgnd_shrt_i);
	printf("unsigned short int -> int   %19d\n", (int)unsgnd_shrt_i);
	printf("unsigned short int -> long int   %14ld\n", (long int)unsgnd_shrt_i);
	printf("unsigned short int -> short int   %10hi\n", (short int)unsgnd_shrt_i);
	printf("unsigned short int -> unsigned int   %10u\n", (unsigned int)unsgnd_shrt_i);
	printf("unsigned short int -> unsigned short int  %2hu\n", (unsigned short int)unsgnd_shrt_i);
	printf("unsigned short int -> unsigned long int   %3lu\n", (unsigned long int)unsgnd_shrt_i);
	printf("unsigned short int -> float   %24f\n", (float)unsgnd_shrt_i);
	printf("unsigned short int -> double   %23f\n", (double)unsgnd_shrt_i);
	printf("unsigned short int -> long double   %18Le\n\n\n", (long double)unsgnd_shrt_i);

	printf("unsigned long int -> signed char   %8c\n", (signed char)unsgnd_lng_i);
	printf("unsigned long int -> unsigned char   %6c\n", (unsigned char)unsgnd_lng_i);
	printf("unsigned long int -> int   %23d\n", (int)unsgnd_lng_i);
	printf("unsigned long int -> long int   %18ld\n", (long int)unsgnd_lng_i);
	printf("unsigned long int -> short int   %15hi\n", (short int)unsgnd_lng_i);
	printf("unsigned long int -> unsigned int   %14u\n", (unsigned int)unsgnd_lng_i);
	printf("unsigned long int -> unsigned short int   %4hu\n", (unsigned short int)unsgnd_lng_i);
	printf("unsigned long int -> unsigned long int   %9lu\n", (unsigned long int)unsgnd_lng_i);
	printf("unsigned long int -> float   %28f\n", (float)unsgnd_lng_i);
	printf("unsigned long int -> double   %27f\n", (double)unsgnd_lng_i);
	printf("unsigned long int -> long double   %19Le\n\n\n", (long double)unsgnd_lng_i);

	printf("float -> signed char   %9c\n", (signed char)flt);
	printf("float -> unsigned char   %7c\n", (unsigned char)flt);
	printf("float -> int   %17d\n", (int)flt);
	printf("float -> long int   %12ld\n", (long int)flt);
	printf("float -> short int   %11hi\n", (short int)flt);
	printf("float -> unsigned int   %8u\n", (unsigned int)flt);
	printf("float -> unsigned short int   %2hu\n", (unsigned short int)flt);
	printf("float -> unsigned long int   %3lu\n", (unsigned long int)flt);
	printf("float -> float   %22f\n", (float)flt);
	printf("float -> double   %21f\n", (double)flt);
	printf("float -> long double   %20Le\n\n\n", (long double)flt);
	
	printf("double -> signed char   %9c\n", (signed char)dbl);
	printf("double -> unsigned char   %7c\n", (unsigned char)dbl);
	printf("double -> int   %17d\n", (int)dbl);
	printf("double -> long int   %12ld\n", (long int)dbl);
	printf("double -> short int   %11hi\n", (short int)dbl);
	printf("double -> unsigned int   %8u\n", (unsigned int)dbl);
	printf("double -> unsigned short int   %2hu\n", (unsigned short int)dbl);
	printf("double -> unsigned long int   %3lu\n", (unsigned long int)dbl);
	printf("double -> float   %22f\n", (float)dbl);
	printf("double -> double   %21f\n", (double)dbl);
	printf("double -> long double   %20Le\n\n\n", (long double)dbl);
	
	printf("long double -> signed char   %10c\n", (signed char)lng_dbl);
	printf("long double  -> unsigned char   %7c\n", (unsigned char)lng_dbl);
	printf("long double  -> int   %17d\n", (int)lng_dbl);
	printf("long double  -> long int   %12ld\n", (long int)lng_dbl);
	printf("long double  -> short int   %11hi\n", (short int)lng_dbl);
	printf("long double  -> unsigned int   %8u\n", (unsigned int)lng_dbl);
	printf("long double  -> unsigned short int   %2hu\n", (unsigned short int)lng_dbl);
	printf("long double  -> unsigned long int   %3lu\n", (unsigned long int)lng_dbl);
	printf("long double  -> float   %22f\n", (float)lng_dbl);
	printf("long double  -> double   %21f\n", (double)lng_dbl);
	printf("long double  -> long double   %20Le\n\n\n", (long double)lng_dbl);
			
}