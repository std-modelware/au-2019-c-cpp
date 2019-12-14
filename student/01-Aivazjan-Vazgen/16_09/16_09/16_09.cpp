#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum type {CHAR, INT, FLOAT, DOUBLE};

//Чтение типа char +
char CharRead() {
	char c;
	scanf("%c", &c);
	return c;
}

//Чтение типа int +
int IntRead() {
	int i;
	scanf("%d", &i);
	return i;
}

//Чтение типа float +
float FloatRead() {
	float f;
	scanf("%f", &f);
	return f;
}

//Чтение типа double +
double DoubleRead() {
	double d;
	scanf("%lf", &d);
	return d;
}

//Проверка символа
bool chek(type c){
	return ((c == CHAR) || (c == INT) || (c == FLOAT) || (c == DOUBLE));
}

//Перевод char в type
type TypeRead(char c) {
	switch (c) {
	case 'i': return INT;
	case 'c': return CHAR;
	case 'f': return FLOAT;
	case 'd': return DOUBLE;
	}
}


// Чтение типа type
type TypeRead() {
	char Type = CharRead();
	while ( !( chek(TypeRead(Type)) ) ) Type = CharRead();
	type T = TypeRead(Type);
	return T;
}

// Переводы в int

//Перевод char в int
int IntCast(char c) {
	int i = (int)c;
	return i;
}

//Перевод float в int
int IntCast(float f) {
	int i = (int)f;
	return i;
}

//Перевод double в int
int IntCast(double d) {
	int i = (int)d;
	return i;
}

// Переводы в char

//Перевод int в char
char CharCast(int i) {
	char c = (char)i;
	return c;
}

//Перевод float в char
char CharCast(float f) {
	char c = (char)f;
	return c;
}

//Перевод double в char
char CharCast(double d) {
	char c = (char)d;
	return c;
}

// Переводы в float

//Перевод int в float
float FloatCast(int i) {
	float f = (float)i;
	return f;
}

//Перевод char в float
float FloatCast(char c) {
	float f = (float)c;
	return f;
}

//Перевод double в float
float FloatCast(double d) {
	float f = (float)d;
	return f;
}

// Переводы в double

//Перевод int в double
double DoubleCast(int i) {
	double d = (double)i;
	return d;
}

//Перевод char в double
double DoubleCast(char c) {
	double d = (double)c;
	return d;
}

//Перевод float в double
double DoubleCast(float f) {
	double d = (double)f;
	return d;
}



void TypeCast() {
	int i; char c; float f; double d;
	type type = TypeRead();
	switch (type) {
	case CHAR: 
		c = CharRead();
		type = TypeRead();
		switch (type) {
		case INT:
			i = IntCast(c);
			printf("%d", i);
			break;
		case FLOAT:
			f = FloatCast(c);
			printf("%f", f);
			break;
		case DOUBLE:
			d = DoubleCast(c);
			printf("%e", d);
			break;
		}
		break;
	case INT:
		i = IntRead();
		type = TypeRead();
		switch (type) {
		case CHAR:
			c = CharCast(i);
			printf("%c", c);
			break;
		case FLOAT:
			f = FloatCast(i);
			printf("%f", f);
			break;
		case DOUBLE:
			d = DoubleCast(i);
			printf("%e", d);
			break;
		}
		break;
	case FLOAT:
		f = FloatRead();
		type = TypeRead();
		switch (type) {
		case CHAR:
			c = CharCast(f);
			printf("%c", c);
			break;
		case INT:
			i = IntCast(f);
			printf("%d", i);
			break;
		case DOUBLE:
			d = DoubleCast(f);
			printf("%e", d);
			break;
		}
		break;
	case DOUBLE:
		d = DoubleRead();
		type = TypeRead();
		switch (type) {
			c = CharCast(d);
			printf("%c", c);
			break;
		case INT:
			i = IntCast(d);
			printf("%d", i);
			break;
		case FLOAT:
			f = FloatCast(d);
			printf("%f", f);
			break;
		}
		break;
	}

}

int main(){
	/*while (true) {
		double f = DoubleRead();
		//TypeCast();
		printf("%e\n", f);
	}*/
	 float sc = - 5.5;
	 int uc = 65000;
	 int Ruc;
	float Rsc;

	Ruc =  int(sc);
	sc = float(Ruc);
	printf("%d", sc);
	return 0;
}