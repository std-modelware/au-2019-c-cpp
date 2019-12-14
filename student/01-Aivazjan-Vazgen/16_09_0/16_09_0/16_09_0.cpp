#include <iostream>

int main()
{
    int i;
	char c;
	float f;
	double d;
	bool b;

	unsigned int ui;
	unsigned char uc;

	long float lf;
	long double ld;
	long int li;
	
	short int si;

	unsigned long int uli;
	unsigned short int usi;
	int k, j;
	bool r;
	scanf("%d", &k);
	switch (k) {
	case 0: 
	{
		scanf("%d", &i);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = i == int(int(i));
		case 1: r = i == int(char(i));
		case 2: r = i == int(float(i));
		case 3: r = i == int(double(i));
		case 4: r = i == int(bool(i));

		case 5: r = i == int(unsigned int(i));
		case 6: r = i == int(unsigned char(i));

		case 7: r = i == int(long float(i));
		case 8: r = i == int(long double(i));
		case 9: r = i == int(long int(i));

		case 10: r = i == int(short int(i));

		case 11: r = i == int(unsigned long int(i));
		case 12: r = i == int(unsigned short int(i));
		}
	}

	case 1:
	{
		scanf("%c", &c);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = c == char(int(c));
		case 1: r = c == char(char(c));
		case 2: r = c == char(float(c));
		case 3: r = c == char(double(c));
		case 4: r = c == char(bool(c));

		case 5: r = c == char(unsigned int(c));
		case 6: r = c == char(unsigned char(c));

		case 7: r = c == char(long float(c));
		case 8: r = c == char(long double(c));
		case 9: r = c == char(long int(c));

		case 10: r = c == char(short int(c));

		case 11: r = c == char(unsigned long int(c));
		case 12: r = c == char(unsigned short int(c));
		}
	}

	case 2:
	{
		scanf("%f", &f);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = f == float(int(f));
		case 1: r = f == float(char(f));
		case 2: r = f == float(float(f));
		case 3: r = f == float(double(f));
		case 4: r = f == float(bool(f));

		case 5: r = f == float(unsigned int(f));
		case 6: r = f == float(unsigned char(f));

		case 7: r = f == float(long float(f));
		case 8: r = f == float(long double(f));
		case 9: r = f == float(long int(f));

		case 10: r = f == float(short int(f));

		case 11: r = f == float(unsigned long int(f));
		case 12: r = f == float(unsigned short int(f));
		}
	}


	case 3:
	{
		scanf("%lf", &d);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = d == double(int(d));
		case 1: r = d == double(char(d));
		case 2: r = d == double(float(d));
		case 3: r = d == double(double(d));
		case 4: r = d == double(bool(d));

		case 5: r = d == double(unsigned int(d));
		case 6: r = d == double(unsigned char(d));

		case 7: r = d == double(long float(d));
		case 8: r = d == double(long double(d));
		case 9: r = d == double(long int(d));

		case 10: r = d == double(short int(d));

		case 11: r = d == double(unsigned long int(d));
		case 12: r = d == double(unsigned short int(d));
		}
	}


	case 4:
	{
		scanf("%b", &b);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = b == bool(int(b));
		case 1: r = b == bool(char(b));
		case 2: r = b == bool(float(b));
		case 3: r = b == bool(double(b));
		case 4: r = b == bool(bool(b));

		case 5: r = b == bool(unsigned int(b));
		case 6: r = b == bool(unsigned char(b));

		case 7: r = b == bool(long float(b));
		case 8: r = b == bool(long double(b));
		case 9: r = b == bool(long int(b));

		case 10: r = b == bool(short int(b));

		case 11: r = b == bool(unsigned long int(b));
		case 12: r = b == bool(unsigned short int(b));
		}
	}


	case 5:
	{
		scanf("%u", &ui);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = ui == unsigned int(int(ui));
		case 1: r = ui == unsigned int(char(ui));
		case 2: r = ui == unsigned int(float(ui));
		case 3: r = ui == unsigned int(double(ui));
		case 4: r = ui == unsigned int(bool(ui));

		case 5: r = ui == unsigned int(unsigned int(ui));
		case 6: r = ui == unsigned int(unsigned char(ui));

		case 7: r = ui == unsigned int(long float(ui));
		case 8: r = ui == unsigned int(long double(ui));
		case 9: r = ui == unsigned int(long int(ui));

		case 10: r = ui == unsigned int(short int(ui));

		case 11: r = ui == unsigned int(unsigned long int(ui));
		case 12: r = ui == unsigned int(unsigned short int(ui));
		}
	}


	case 6:
	{
		scanf("%c", &uc);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = uc == unsigned char(int(uc));
		case 1: r = uc == unsigned char(char(uc));
		case 2: r = uc == unsigned char(float(uc));
		case 3: r = uc == unsigned char(double(uc));
		case 4: r = uc == unsigned char(bool(uc));

		case 5: r = uc == unsigned char(unsigned int(uc));
		case 6: r = uc == unsigned char(unsigned char(uc));

		case 7: r = uc == unsigned char(long float(uc));
		case 8: r = uc == unsigned char(long double(uc));
		case 9: r = uc == unsigned char(long int(uc));

		case 10: r = uc == unsigned char(short int(uc));

		case 11: r = uc == unsigned char(unsigned long int(uc));
		case 12: r = uc == unsigned char(unsigned short int(uc));
		}
	}



	case 7:
	{
		scanf("%lf", &lf);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = lf == long float(int(lf));
		case 1: r = lf == long float(char(lf));
		case 2: r = lf == long float(float(lf));
		case 3: r = lf == long float(double(lf));
		case 4: r = lf == long float(bool(lf));

		case 5: r = lf == long float(unsigned int(lf));
		case 6: r = lf == long float(unsigned char(lf));

		case 7: r = lf == long float(long float(lf));
		case 8: r = lf == long float(long double(lf));
		case 9: r = lf == long float(long int(lf));

		case 10: r = lf == long float(short int(lf));

		case 11: r = lf == long float(unsigned long int(lf));
		case 12: r = lf == long float(unsigned short int(lf));
		}
	}


	case 8:
	{
		scanf("%lf", &ld);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = ld == long double(int(ld));
		case 1: r = ld == long double(char(ld));
		case 2: r = ld == long double(float(ld));
		case 3: r = ld == long double(double(ld));
		case 4: r = ld == long double(bool(ld));

		case 5: r = ld == long double(unsigned int(ld));
		case 6: r = ld == long double(unsigned char(ld));

		case 7: r = ld == long double(long float(ld));
		case 8: r = ld == long double(long double(ld));
		case 9: r = ld == long double(long int(ld));

		case 10: r = ld == long double(short int(ld));

		case 11: r = ld == long double(unsigned long int(ld));
		case 12: r = ld == long double(unsigned short int(ld));
		}
	}



	case 9:
	{
		scanf("%ld", &li);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = li == long int(int(li));
		case 1: r = li == long int(char(li));
		case 2: r = li == long int(float(li));
		case 3: r = li == long int(double(li));
		case 4: r = li == long int(bool(li));

		case 5: r = li == long int(unsigned int(li));
		case 6: r = li == long int(unsigned char(li));

		case 7: r = li == long int(long float(li));
		case 8: r = li == long int(long double(li));
		case 9: r = li == long  int(long int(li));

		case 10: r = li == long int(short int(li));

		case 11: r = li == long int(unsigned long int(li));
		case 12: r = li == long int(unsigned short int(li));
		}
	}


	case 10:
	{
		scanf("%d", &si);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = si == short int(int(si));
		case 1: r = si == short int(char(si));
		case 2: r = si == short int(float(si));
		case 3: r = si == short int(double(si));
		case 4: r = si == short int(bool(si));

		case 5: r = si == short int(unsigned int(si));
		case 6: r = si == short int(unsigned char(si));

		case 7: r = si == short int(long float(si));
		case 8: r = si == short int(long double(si));
		case 9: r = si == short int(long int(si));

		case 10: r = si == short int(short int(si));

		case 11: r = si == short int(unsigned long int(si));
		case 12: r = si == short int(unsigned short int(si));
		}
	}


	case 11:
	{
		scanf("%u", &uli);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = uli == unsigned long int(int(uli));
		case 1: r = uli == unsigned long int(char(uli));
		case 2: r = uli == unsigned long  int(float(uli));
		case 3: r = uli == unsigned long  int(double(uli));
		case 4: r = uli == unsigned long  int(bool(uli));

		case 5: r = uli == unsigned long  int(unsigned int(uli));
		case 6: r = uli == unsigned long  int(unsigned char(uli));

		case 7: r = uli == unsigned long int(long float(uli));
		case 8: r = uli == unsigned long  int(long double(uli));
		case 9: r = uli == unsigned long  int(long int(uli));

		case 10: r = uli == unsigned long  int(short int(uli));

		case 11: r = uli == unsigned long  int(unsigned long int(uli));
		case 12: r = uli == unsigned long  int(unsigned short int(uli));
		}
	}

	case 12:
	{
		scanf("%u", &usi);
		scanf("%d", &j);
		switch (j)
		{
		case 0: r = usi == unsigned short int(int(usi));
		case 1: r = usi == unsigned short int(char(usi));
		case 2: r = usi == unsigned short  int(float(usi));
		case 3: r = usi == unsigned short  int(double(usi));
		case 4: r = usi == unsigned short  int(bool(usi));

		case 5: r = usi == unsigned short  int(unsigned int(usi));
		case 6: r = usi == unsigned short  int(unsigned char(usi));

		case 7: r = usi == unsigned short int(long float(usi));
		case 8: r = usi == unsigned short  int(long double(usi));
		case 9: r = usi == unsigned short  int(long int(usi));

		case 10: r = usi == unsigned short  int(short int(usi));

		case 11: r = usi == unsigned short  int(unsigned long int(usi));
		case 12: r = usi == unsigned short  int(unsigned short int(usi));
		}
	}


	}
	/*printf("i = %d(%d)\n", i, sizeof(i));
	c = (char)i;
	printf("c = %c(%d)\n", c, sizeof(c));
	f = (float)i;
	printf("f = %f(%d)\n", f, sizeof(f));
	d = (double)i;
	printf("d = %e(%d)\n", d, sizeof(d));
	
	printf("\n");

	c = 'a';
	printf("c = %c(%d)\n", c, sizeof(c));
	i = (int)c;
	printf("i = %d(%d)\n", i, sizeof(i));
	f = (float)c;
	printf("f = %f(%d)\n", f, sizeof(f));
	d = (double)c;
	printf("d = %e(%d)\n", d, sizeof(d));

	printf("\n");

	f = 70.5;
	printf("f = %f(%d)\n", f, sizeof(f));
	i = (int)f;
	printf("i = %d(%d)\n", i, sizeof(i));
	c = (char)f;
	printf("c = %c(%d)\n", c, sizeof(c));
	d = (double)f;
	printf("d = %e(%d)\n", d, sizeof(d));

	printf("\n");

	d = 70.55;
	printf("d = %e(%d)\n", d, sizeof(d));
	i = (int)d;
	printf("i = %d(%d)\n", i, sizeof(i));
	c = (char)d;
	printf("c = %c(%d)\n", c, sizeof(c));
	f = (float)d;
	printf("f = %f(%d)\n", f, sizeof(f));*/

	//printf("   | int | char | float | double| ");
	printf("%d", b);
	return 0;
}

