#include <stdio.h>;
void main()
{
	char chnum = 'H';
	signed char schnum = 'D';
	int num = -150;
	unsigned int unnum = 200;
	short shnum = 20;
	long lnum = 1029384756;
	float fnum = 3.657;
	double dnum = 5.07501679;

	printf("char to signed char = %c\n char to int = %i\n char to unsigned int = %u\n char to short = %hi\n", chnum, chnum, chnum, chnum);
	printf("char to long = %f\n char to double = %f\n\n", chnum, chnum);

	printf("int to char = %c\n int to signed char = %c\n int to unsigned int = %u\n int to short = %hi\n", num, num, num, num);
	printf("int to long = %li\n int to float = %f\n int to double = %f\n\n", num, num, num);

	printf("unsigned int to char = %c\n unsigned int to signed char = %c\n unsigned int to int = %i\n unsigned int to short = %hi\n", unnum, unnum, unnum, unnum);
	printf("unsigned int to long = %li\n unsigned int to float = %f\n unsigned int to double = %f\n\n", unnum, unnum, unnum);

	printf("short to char = %c\n, short to signed char = %c\n short to int = %i\n short to unsigned int = %u\n", shnum, shnum, shnum, shnum);
	printf("short to float = %f\n short to double = %f\n\n", shnum, shnum);

	printf("long to char = %c\n long to signed char = %c\n, long to int = %i\n long to unsigned int = %u\n, long to short = %hi\n", lnum, lnum, lnum, lnum);
	printf("long to float = %f\n long to double = %f\n\n", lnum, lnum);

	printf("float to char = %c\n float to signed char = %c\n float to int = %i\n float to  unsigned int = %u\n float to short = %hi\n", fnum, fnum, fnum, fnum);
	printf("float to long = %li\n float to double = %f\n\n", fnum, fnum);

	printf("double to char = %c\n double to signed char = %c\n double to int = %i\n double to unsigned int = %u\n double to short = %hi\n", dnum, dnum, dnum, dnum);
	printf("double to long = %li\n double to float = %f\n\n", dnum, dnum);

}