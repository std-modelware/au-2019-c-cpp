#include <stdio.h>
#include <iostream>

using namespace std;

void main() {

	int a = 123456;
	float b = 3.14159265;
	char c = 'a';
	double d = 3.14159265;

	unsigned int au = 123456;
	unsigned char cu = 'a';

	short int as = 123456;

	long int al = 123456;
	long float bl = 3.14159265;
	long double dl = 3.14159265;

	/*
	cout << "Type int here:";
	cin >> a;
	cout << "Type float here:";
	cin >> b;
	cout << "Type char here:";
	cin >> c;
	cout << "Type double here:";
	cin >> d;

	cout << "Type unsigned int here:";
	cin >> au;
	cout << "Type unsigned char here:";
	cin >> cu;

	cout << "Type short int here:";
	cin >> as;

	cout << "Type long int here:";
	cin >> al;
	cout << "Type long float here:";
	cin >> bl;
	cout << "Type long double here:";
	cin >> dl; */

	cout << "Type" << "|" << "Int" << "|" << "Float" << "|" << "Char" << "|" << "Double" << "|" << "Unsigned int" << "|" << "Unsigned char" << "|" << "Short int" << "|" << "Long int" << "|" << "Long float" << "|" << "Long double" << endl;
	cout << "Your values" << "|" << a << "|" << b << "|" << c << "|" << d << "|" << au << "|" << cu << "|" << as << "|" << al << "|" << bl << "|" << dl << endl;
	cout << "Int" << "|" << (int)a << "|" << (int)b << "|" << (int)c << "|" << (int)d << "|" << (int)au << "|" << (int)cu << "|" << (int)as << "|" << (int)al << "|" << (int)bl << "|" << (int)dl << endl;
	cout << "Float" << "|" << (float)a << "|" << (float)b << "|" << (float)c << "|" << (float)d << "|" << (float)au << "|" << (float)cu << "|" << (float)as << "|" << (float)al << "|" << (float)bl << "|" << (float)dl << endl;
	cout << "Char" << "|" << (char)a << "|" << (char)b << "|" << (char)c << "|" << (char)d << "|" << (char)au << "|" << (char)cu << "|" << (char)as << "|" << (char)al << "|" << (char)bl << "|" << (char)dl << endl;
	cout << "Double" << "|" << (double)a << "|" << (double)b << "|" << (double)c << "|" << (double)d << "|" << (double)au << "|" << (double)cu << "|" << (double)as << "|" << (double)al << "|" << (double)bl << "|" << (double)dl << endl;
	cout << "Unsigned int" << "|" << (unsigned int)a << "|" << (unsigned int)b << "|" << (unsigned int)c << "|" << (unsigned int)d << "|" << (unsigned int)au << "|" << (unsigned int)cu << "|" << (unsigned int)as << "|" << (unsigned int)al << "|" << (unsigned int)bl << "|" << (unsigned int)dl << endl;
	cout << "Unsigned char" << "|" << (unsigned char)a << "|" << (unsigned char)b << "|" << (unsigned char)c << "|" << (unsigned char)d << "|" << (unsigned char)au << "|" << (unsigned char)cu << "|" << (unsigned char)as << "|" << (unsigned char)al << "|" << (unsigned char)bl << "|" << (unsigned char)dl << endl;
	cout << "Short int" << "|" << (short int)a << "|" << (short int)b << "|" << (short int)c << "|" << (short int)d << "|" << (short int)au << "|" << (short int)cu << "|" << (short int)as << "|" << (short int)al << "|" << (short int)bl << "|" << (short int)dl << endl;
	cout << "Long int" << "|" << (long int)a << "|" << (long int)b << "|" << (long int)c << "|" << (long int)d << "|" << (long int)au << "|" << (long int)cu << "|" << (long int)as << "|" << (long int)al << "|" << (long int)bl << "|" << (long int)dl << endl;
	cout << "Long float" << "|" << (long float)a << "|" << (long float)b << "|" << (long float)c << "|" << (long float)d << "|" << (long float)au << "|" << (long float)cu << "|" << (long float)as << "|" << (long float)al << "|" << (long float)bl << "|" << (long float)dl << endl;
	cout << "Long double" << "|" << (long double)a << "|" << (long double)b << "|" << (long double)c << "|" << (long double)d << "|" << (long double)au << "|" << (long double)cu << "|" << (long double)as << "|" << (long double)al << "|" << (long double)bl << "|" << (long double)dl << endl;

	system("pause");
}