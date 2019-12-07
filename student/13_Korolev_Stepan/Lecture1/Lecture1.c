#include <stdio.h>

int main()
{
	/*	Тип					Длина в битах		Диапазон
		char 				8 					от -128 до 127
		unsigned char 		8 					от 0 до 255
		signed char 		8 					от -128 до 127
		int 				16 					от -32768 до 32767
		unsigned int 		16 					от 0 до 65535
		signed int 			16 					от -32768 до 32767
		short int 			16 					от -32768 до 32767
		unsigned short int 	16 					от 0 до 65535
		signed short int 	16 					от -32768 до 32767
		long int 			32 					от -2147483648 до 2147483647
		unsigned long int 	32 					от 0 до 4294967295
		signed long int. 	32 					от -2147483648 до 2147483647
		float 				32 					от 3.4е-38 до 3.4е+38
		double				64 					от 1.7е-308 до 1.7e+308
		long double 		80 					от 3.4е-4932 до 1.1e+4932 */

	const char					mychar			   = -16;
	const unsigned char			myunsignedchar	   = 15;
	const int					myint			   = -16;
	const unsigned int			myunsignedint	   = 17;
	const short int				myshortint		   = -1642;
	const unsigned short int	myunsignedshortint = 146;
	const long int				mylongint		   = -1444421426;
	const unsigned long int		myunsignedlongint  = 14244424426;
	const float					myfloat			   = -16.72;
	const double				mydouble		   = -16.42993293999999999999999999999994124214214214412;
	const long double			mylongdouble	   = -16.42993232999993239999999999412421421421441241421412421421;

	printf("char:\t\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", mychar, (unsigned char)mychar, (int)mychar, (unsigned int)mychar, (short int)mychar, (unsigned short int)mychar, (long int)mychar, (unsigned long int)mychar, (float)mychar, (double)mychar, (long double)mychar);

	printf("unsigned char:\t\t %d\nto char:\t\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myunsignedchar, (char)myunsignedchar, (int)myunsignedchar, (unsigned int)myunsignedchar, (short int)myunsignedchar, (unsigned short int)myunsignedchar, (long int)myunsignedchar, (unsigned long int)myunsignedchar, (float)myunsignedchar, (double)myunsignedchar, (long double)myunsignedchar);

	printf("int:\t\t\t %d\nto char:\t\t %d\nto unsigned char:\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myint, (char)myint, (unsigned char)myint, (unsigned int)myint, (short int)myint, (unsigned short int)myint, (long int)myint, (unsigned long int)myint, (float)myint, (double)myint, (long double)myint);

	printf("unsigned int:\t\t %u\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto short int:\t\t %hd\nto unsigned short:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myunsignedint, (char)myunsignedint, (unsigned char)myunsignedint, (int)myunsignedint, (short int)myunsignedint, (unsigned short int)myunsignedint, (long int)myunsignedint, (unsigned long int)myunsignedint, (float)myunsignedint, (double)myunsignedint, (long double)myunsignedint);

	printf("short int:\t\t %hd\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto unsigned short:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myshortint, (char)myshortint, (unsigned char)myshortint, (int)myshortint, (unsigned int)myshortint, (unsigned short int)myshortint, (long int)myshortint, (unsigned long int)myshortint, (float)myshortint, (double)myshortint, (long double)myshortint);

	printf("unsigned short int:\t %hu\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myunsignedshortint, (char)myunsignedshortint, (unsigned char)myunsignedshortint, (int)myunsignedshortint, (unsigned int)myunsignedshortint, (short int)myunsignedshortint, (long int)myunsignedshortint, (unsigned long int)myunsignedshortint, (float)myunsignedshortint, (double)myunsignedshortint, (long double)myunsignedshortint);

	printf("long int:\t\t %ld\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short int:\t %hu\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", mylongint, (char)mylongint, (unsigned char)mylongint, (int)mylongint, (unsigned int)mylongint, (short int)mylongint, (unsigned short int)mylongint, (unsigned long int)mylongint, (float)mylongint, (double)mylongint, (long double)mylongint);

	printf("unsigned long int:\t %lu\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short int:\t %hu\nto long int:\t\t %ld\nto float:\t\t %e\nto double:\t\t %e\nto long double:\t\t %e\n\n", myunsignedshortint, (char)myunsignedshortint, (unsigned char)myunsignedshortint, (int)myunsignedshortint, (unsigned int)myunsignedshortint, (short int)myunsignedshortint, (unsigned short int)myunsignedshortint, (long int)myunsignedshortint, (float)myunsignedshortint, (double)myunsignedshortint, (long double)myunsignedshortint);

	printf("float:\t\t\t %e\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short int:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto double:\t\t %e\nto long double:\t\t %e\n\n", myfloat, (char)myfloat, (unsigned char)myfloat, (int)myfloat, (unsigned int)myfloat, (short int)myfloat, (unsigned short int)myfloat, (long int)myfloat, (unsigned long int)myfloat, (double)myfloat, (long double)myfloat);

	printf("double:\t\t\t %e\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short int:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto long double:\t\t %e\n\n", mydouble, (char)mydouble, (unsigned char)mydouble, (int)mydouble, (unsigned int)mydouble, (short int)mydouble, (unsigned short int)mydouble, (long int)mydouble, (unsigned long int)mydouble, (float)mydouble, (long double)mydouble);

	printf("long double:\t\t %e\nto char:\t\t %d\nto unsigned char:\t %d\nto int:\t\t\t %d\nto unsigned int:\t %u\nto short int:\t\t %hd\nto unsigned short int:\t %hu\nto long int:\t\t %ld\nto unsigned long int:\t %lu\nto float:\t\t %e\nto double:\t\t %e", mylongdouble, (char)mylongdouble, (unsigned char)mylongdouble, (int)mylongdouble, (unsigned int)mylongdouble, (short int)mylongdouble, (unsigned short int)mylongdouble, (long int)mylongdouble, (unsigned long int)mylongdouble, (float)mylongdouble, (double)mylongdouble);
}