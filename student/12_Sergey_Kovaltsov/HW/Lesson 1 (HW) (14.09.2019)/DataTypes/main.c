#include <stdio.h>
int main() {
	char word = 'a';                     // (-128; 127)
	signed char siword = 'b';            // (-128; 127)
	unsigned char unword = 'c';          // (0; 255)
	int num = 12345;                     // (-32768; 32767)
	signed int sinum = -12345;           // (-32768; 32767)
	unsigned int unnum = 24691;          // (0; 65535)
	short int snum = 54312;              // (-32768; 32767)
	signed short int sisnum = -78594;    // (-32768; 32767)
	unsigned short int unsnum = 34768;   // (0; 65535)
	long int lnum = 12331;               // (-2147483648; 2147483647)
	signed long int silnum = -12428;     // (-2147483648; 2147483647)
	unsigned long int unlnum = 42949;    // (0; 4294967295)
	float fl = 3.42313;                  // (3.4E-38; 3.4E+38)
	double doub = 1.382576;              // (1.7E-308; 1.7E+308)
	long double ldoub = 1.752351;        // Число большего (1.7E-308; 1.7E+308) размера компилятор отказался принимать, несмотря на спецификатор long 

	printf("%c\n", word);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	char a = '1';
	signed char b = "2";
	unsigned char c = "3";
	int d = 4;
	signed int e = 5;
	unsigned int f = 6;
	short int g = 7;
	signed short int h = 8;
	unsigned short int i = 9;
	long int j = 10;
	signed long int k = 11;
	unsigned long int l = 12;
	float m = 13;
	double n = 14;
	long double o = 15;
	
	char y, p = 'r';
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	printf("             Char     SiChar    UnSiChar   Int     SiInt   UnSiInt    SInt    SiSInt    UnSInt    LInt    SiLInt    UnLInt   float          double             ldouble\n");
	printf(" Char         --      %c         %c          %d      %d      %d         %d      %d        %d        %d      %d        %d       %f      %e       %e\n",
		b = (signed char)word, c = (unsigned char)word, d = (int)word, e = (signed int)word, f = (unsigned int)word, g = (short int)word, h = (signed short int)word, 
		i = (unsigned short int)word, j = (long int)word, k = (signed long int)word, l = (unsigned long int)word, m = (float)word, n = (double)word, o = (long double)word);
	printf(" SiChar       %c       --        %c          %d      %d      %d         %d      %d        %d        %d      %d        %d       %f      %e       %e\n",
		a = (char)siword, c = (unsigned char)siword, d = (int)siword, e = (signed int)siword, f = (unsigned int)siword, g = (short int)siword, h = (signed short int)siword,
		i = (unsigned short int)siword, j = (long int)siword, k = (signed long int)siword, l = (unsigned long int)siword, m = (float)siword, n = (double)siword, o = (long double)siword);
	printf(" UnSiChar     %c       %c         --         %d      %d      %d         %d      %d        %d        %d      %d        %d       %f      %e       %e\n",
		a = (signed char)unword, b = (signed char)unword, d = (int)unword, e = (signed int)unword, f = (unsigned int)unword, g = (short int)unword, h = (signed short int)unword,
		i = (unsigned short int)unword, j = (long int)unword, k = (signed long int)unword, l = (unsigned long int)unword, m = (float)unword, n = (double)unword, o = (long double)unword);
	printf(" Int          %c       %c         %c          --      %d   %d      %d   %d     %d     %d   %d     %d    %f   %e       %e\n",
		a = (char)num, b = (signed char)num, c = (unsigned char)num, e = (signed int)num, f = (unsigned int)num, g = (short int)num, h = (signed short int)num,
		i = (unsigned short int)num, j = (long int)num, k = (signed long int)num, l = (unsigned long int)num, m = (float)num, n = (double)num, o = (long double)num);
	printf(" SiInt        %c       %c         %c          %d  --      %d    %d   %d    %d     %d  %d    %d   %f  %e      %e\n",
		a = (char)sinum, b = (signed char)sinum, c = (unsigned char)sinum, d= ( int)sinum, f = (unsigned int)sinum, g = (short int)sinum, h = (signed short int)sinum,
		i = (unsigned short int)sinum, j = (long int)sinum, k = (signed long int)sinum, l = (unsigned long int)sinum, m = (float)sinum, n = (double)sinum, o = (long double)sinum);
	printf(" UnSiInt      %c       %c         %c          %d   %d   --         %d   %d     %d     %d   %d     %d    %f   %e       %e\n",
		a = (char)unnum, b = (signed char)unnum, c = (unsigned char)unnum, d = (int)unnum, e = (signed int)unnum, g = (short int)unnum, h = (signed short int)unnum,
		i = (unsigned short int)unnum, j = (long int)unnum, k = (signed long int)unnum, l = (unsigned long int)unnum, m = (float)unnum, n = (double)unnum, o = (long double)unnum);
	printf(" SInt         %c       %c         %c          %d  %d  %d     --      %d    %d     %d  %d    %d   %f  %e      %e\n",
		a = (char)snum, b = (signed char)snum, c = (unsigned char)snum, d = (int)snum, e = (signed int)snum, f = (unsigned int)snum, h = (signed short int)snum,
		i = (unsigned short int)snum, j = (long int)snum, k = (signed long int)snum, l = (unsigned long int)snum, m = (float)snum, n = (double)snum, o = (long double)snum);
	printf(" SiSInt       %c       %c         %c          %d  %d  %d     %d  --        %d     %d  %d    %d   %f  %e      %e\n",
		a = (char)sisnum, b = (signed char)sisnum, c = (unsigned char)sisnum, d = (int)sisnum, e = (signed int)sisnum, f = (unsigned int)sisnum, g = (short int)sisnum,
		i = (unsigned short int)sisnum, j = (long int)sisnum, k = (signed long int)sisnum, l = (unsigned long int)sisnum, m = (float)sisnum, n = (double)sisnum, o = (long double)sisnum);
	printf(" UnSInt       %c       %c         %c          %d   %d   %d      %d  %d    --        %d   %d     %d    %f   %e       %e\n",
		a = (char)unsnum, b = (signed char)unsnum, c = (unsigned char)unsnum, d = (int)unsnum, e = (signed int)unsnum, f = (unsigned int)unsnum, g = (short int)unsnum,
		h = (signed short int)unsnum, j = (long int)unsnum, k = (signed long int)unsnum, l = (unsigned long int)unsnum, m = (float)unsnum, n = (double)unsnum, o = (long double)unsnum);
	printf(" LInt         %c       %c         %c          %d   %d   %d      %d   %d     %d     --      %d     %d    %f   %e       %e\n",
		a = (char)lnum, b = (signed char)lnum, c = (unsigned char)lnum, d = (int)lnum, e = (signed int)lnum, f = (unsigned int)lnum, g = (short int)lnum,
		h = (signed short int)lnum, i = (unsigned short int)lnum, k = (signed long int)lnum, l = (unsigned long int)lnum, m = (float)lnum, n = (double)lnum, o = (long double)lnum);
	printf(" SiLInt       %c       %c         %c          %d  %d  %d     %d  %d    %d     %d  --        %d   %f  %e      %e\n",
		a = (char)silnum, b = (signed char)silnum, c = (unsigned char)silnum, d = (int)silnum, e = (signed int)silnum, f = (unsigned int)silnum, g = (short int)silnum,
		h = (signed short int)silnum, i = (unsigned short int)silnum, j = (long int)silnum, l = (unsigned long int)silnum, m = (float)silnum, n = (double)silnum, o = (long double)silnum);
	printf(" UnLInt       %c       %c         %c          %d   %d   %d      %d  %d    %d     %d   %d     --       %f   %e       %e\n",
		a = (char)unlnum, b = (signed char)unlnum, c = (unsigned char)unlnum, d = (int)unlnum, e = (signed int)unlnum, f = (unsigned int)unlnum, g = (short int)unlnum,
		h = (signed short int)unlnum, i = (unsigned short int)unlnum, j = (long int)unlnum, k = (signed long int)unlnum, m = (float)unlnum, n = (double)unlnum, o = (long double)unlnum);
	printf(" float        %c       %c         %c          %d       %d       %d          %d       %d         %d         %d       %d         %d        --             %e       %e\n",
		a = (char)fl, b = (signed char)fl, c = (unsigned char)fl, d = (int)fl, e = (signed int)fl, f = (unsigned int)fl, g = (short int)fl,
		h = (signed short int)fl, i = (unsigned short int)fl, j = (long int)fl, k = (signed long int)fl, l = (unsigned long int)fl, n = (double)fl, o = (long double)fl);
	printf(" double       %c       %c         %c          %d       %d       %d          %d       %d         %d         %d       %d         %d        %e   --                 %e\n",
		a = (char)doub, b = (signed char)doub, c = (unsigned char)doub, d = (int)doub, e = (signed int)doub, f = (unsigned int)doub, g = (short int)doub,
		h = (signed short int)doub, i = (unsigned short int)doub, j = (long int)doub, k = (signed long int)doub, l = (unsigned long int)doub, n = (double)doub, o = (long double)doub);
	printf(" ldouble      %c       %c         %c          %d       %d       %d          %d       %d         %d         %d       %d         %d        %e   %e       --\n",
		a = (char)ldoub, b = (signed char)ldoub, c = (unsigned char)ldoub, d = (int)ldoub, e = (signed int)ldoub, f = (unsigned int)ldoub, g = (short int)ldoub,
		h = (signed short int)ldoub, i = (unsigned short int)ldoub, j = (long int)ldoub, k = (signed long int)ldoub, l = (unsigned long int)ldoub, m = (float)ldoub, n = (double)ldoub);
	


	
}
