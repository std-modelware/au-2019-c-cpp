#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


//точка
struct point
{

	int x; // координата x
	int y; // координата y
	void read() {
		printf("\n x: ");
		scanf("%d", &x);
		printf(" y: ");
		scanf("%d", &y);
		printf("\n");
	}

	point(int a, int b)
	{
		x = a;
		y = b;
	}

	point()
	{
		point(0, 0);
	}
	
	int lenght()
	{
		return x * x + y * y;
	}

	bool operator==(point p)
	{
		return (x == p.x) && (y == p.y);
	}

	void operator=(point p)
	{
		x = p.x;
		y = p.y;
	}

	point operator-(point p)
	{
		point t;
		t.x = p.x - x;
		t.y = p.y - y;
		return t;
	}

	int operator*(point p)
	{
		return x * p.x + y * p.y;
	}

	double angle(point p)
	{
		return ((*this) * p) / sqrt(this->lenght() * p.lenght());
	}

};




//луч
struct ray
{
	point B; // начало луча
	int x; // изменение по x
	int y; // изменение по y
	void read() {
		point e;
		printf("read B\n");
		B.read();
		e.x = B.x;
		e.y = B.y;
		while (B==e) { printf("read E\n"); e.read(); }
		x = B.x - e.x;
		y = B.y - e.y;
	}
	/*void write(point A, point C) {
		if (!(P_P(A, C))) {
			B = A;
			x = B.x - C.x;
			y = B.y - C.y;
		}
	}*/
	bool Rb_Rb(ray Y)
	{
		return(B == Y.B);
	}
};


//прямая
struct straight
{
	// ax + by + c = 0 
	 int a;
	 int b;
	 int c;

private:

	 straight(int x, int y, int z)
	 {
		 a = x;
		 b = y;
		 c = z;
	 }

public:
	straight()
	{
		straight(0, 0, 0);
	
	}
	void str(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;
	}

	/*
	 void read() {
		 int x = 0;
		 int y = 0;
		 int z = 0;
		 while ((x == 0) && (y == 0)) { printf("write a, b, c:\n"); scanf("%d %d %d", &x, &y, &z); }
		 straight(x, y, z);
	 };*/
	 bool S_P(point B) {
		 return (a * B.x + b * B.y + c == 0);
	 }
	 void create(point A, point B) {
		 point C = A - B;
		 point R;
		 if(!(C == R))
		 a = -C.y;
		 b = C.x;
		 c = -a * A.x - b*A.y;
	 }

	 bool parallelism(straight x)
	 {
		 return (a*x.b== b*x.a);
	 }
};





//триугольник
struct Triangle
{
	point A;
	point B;
	point C;
	void read() {
		printf("read A\n");
		A.read();
		printf("read B\n");
		B.read();
		straight AB;
		AB.create(A, B);
		printf("read C\n");
		C.read();
		while ((AB.S_P(C))) { printf("Error: C in AB \nread C\n"); C.read(); }
	};
	bool Right_Triangle()
	{
		point a, b, c;
		a = B - C;
		b = C - A;
		c = A - B;
		return((a.angle(b)==0)||(a.angle(c)==0) || (c.angle(b)==0 )) ;
	}
	Triangle create(point a, point b, point c)
	{
		Triangle t;
		t.A = a;
		t.B = b;
		t.C = c;
		straight AB;
		AB.create(a, b);

		if (AB.S_P(c)) return t;
	}
	void operator=(Triangle p)
	{
		A = p.A;
		B = p.B;
		C = p.C;
	}


};
/*
bool TpointR(Tpoint ABC) {
	int AB = ABC.A.x - ABC.B.x)
}*/


//прямоугольник
struct rectangle
{
	point A;
	point B;
	point C;
	point D;
	void read()
	{
		A.read();
		B.read();
		C.read();
		D.read();
		point AB, BC, CD, DA;
		AB = A - B;
		BC = B - C;
		CD = C - D;
		DA = D - A;
		while (!((AB.angle(BC)==0) && (BC.angle(CD)==0) && (CD.angle(DA)==0) && (DA.angle(AB)==0)))
		{
			printf("error! \n");
			A.read();
			B.read();
			C.read();
			D.read();
			AB = A - B;
			BC = B - C;
			CD = C - D;
			DA = D - A;
			
		}

	}
	bool square()
	{
		point AB = A - B;
		point BC = B - C;
		return (AB.lenght() == BC.lenght());
	}

};

//окружность
struct Okr
{
	point O;
	int R;
	void read() {
		printf("read O\n");
		O.read();
		printf("read R: ");
		scanf("%d", &R);
	}
	bool S_O(straight S) {
		return (S.S_P(O));
	}
};



 




int main()
{
	point A;
	point B;
	A.read();
	B.read();
	if (A == B) printf("A = B\n"); else printf("A != B\n");
	
	point C;
	straight x;
	x.str(0, 1, -2);
	//x.read();
	C.read();
	bool b = x.S_P(C);
	if (b) printf("C in x\n"); 
	else printf("C don't in x\n");

	ray T, R;
	T.read();
	R.read();
	if (T.Rb_Rb(R))  printf("true\n"); else printf("false\n");

	straight y;
	//y.read();
	y.str(1, 0, -5);
	if(!(x.parallelism(y))) printf("true\n"); else printf("false\n");

	Okr o;
	//y.read();
	o.read();
	if (o.S_O(y))  printf("true\n"); else printf("false\n");

	Triangle abc;
	abc.read();
	if (abc.Right_Triangle())  printf("true\n"); else printf("false\n");
	
	rectangle abcd;
	abcd.read();


	if (abcd.square())  printf("true\n");
	else printf("false\n");

	return 0;
}
/*
//точка
struct point
{
	int x; // координата x
	int y; // координата y
	void set_x() {
		scanf("%d", x);
	}
	void set_y() {
		scanf("%d", y);
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void read() {
		printf("\nВвудите координату x: ");
		set_x();
		printf("\nВвудите координату y: ");
		set_y();
		printf("\n");
	}
};


bool P_P(point X, point Y)
{
	return((X.get_x() == Y.get_x()) && (X.get_y() == Y.get_y()));
}
*/