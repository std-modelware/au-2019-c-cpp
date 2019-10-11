#include <stdio.h>
#include <math.h>



struct Strpoint {
	float x;
	float y;
} v1, f1,w1;
struct Strline {
	struct Strpoint s1, s2;
} v2, f2;
struct Strline2 {
	float k;
	float b;
} v3,f3,w3;
struct Striangle {
	struct Strpoint p1, p2, p3;
} v4, f4;
struct Strfigure {
	struct Strpoint p1, p2,p3;
} v5, f5;
struct Strcircle {
	struct Strpoint p1;
	float R;
} v6, f6;

/////////////////////
int funcpoint(Strpoint v1, Strpoint f1) {
	if ((v1.x == f1.x) && (v1.y == f1.y)) {
		return 1;
	}
	else {
		return 0;
	}
}

int funcline(Strline v2, Strline f2) {
	if ((v2.s1.x == f2.s2.x) && (v2.s1.y == f2.s2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}

int funcline2(Strline2 v3, Strpoint w1) {
	if (w1.y ==(v3.k*w1.x+v3.b)) {
		return 1;
	}
	else {
		return 0;
	}
}

int funccross(Strline2 v3, Strline2 f3) {
	if ((v3.k != f3.k) && (v3.b != f3.b)) {
		return 1;
	}
	else {
		return 0;
	}
}

int funcright(Striangle v4) {
	float d = (pow((v4.p1.x - v4.p2.x),2) + pow((v4.p1.y - v4.p2.y),2));
	float d1 = (pow((v4.p1.x - v4.p3.x),2) + pow((v4.p1.y - v4.p3.y),2));
	float d2 = (pow((v4.p3.x - v4.p2.x),2) + pow((v4.p3.y - v4.p2.y),2));
	if ((d == d1+d2) || (d1 == d + d2)|| (d2 == d1 + d)) {
		return 1;
	}
	else {
		return 0;
	}
}

int funcsquare(Strfigure v5) {
	float d = sqrt(pow((v5.p1.x - v5.p2.x),2) + pow((v5.p1.y - v5.p2.y),2));
	float d1 = sqrt(pow((v5.p1.x - v5.p3.x),2) + pow((v5.p1.y - v5.p3.y),2));
	float d2 = sqrt(pow((v5.p2.x - v5.p3.x),2) + pow((v5.p2.y - v5.p3.y),2));
	if (((d>d1)&&(d1==d2))||((d1 > d2) && (d == d2))|| ((d2 > d1) && (d1 = d))){
		return 1;
	}
	else {
		return 0;
	}
}

int funclast(Strline2 w3, Strcircle v6) {
	if (v6.p1.y == (w3.k*v6.p1.x + w3.b)) {
		return 1;
	}
	else {
		return 0;
	}
}



	void main() {
		v1.x = 9;
		v1.y = 4;
		f1.x = 7;
		f1.y = 4;

		int answer1 = funcpoint(v1, f1);
		printf("%d\n", answer1);
		//////////////////////
		v2.s1.x = 7;
		v2.s1.y = 4;
		f2.s2.x = 7;
		f2.s2.y = 4;

		int answer2 = funcline(v2, f2);
		printf("%d\n", answer2);
		//////////////////////////
		v3.k = 1;
		v3.b = 0;
		w1.x = 1;
		w1.y = 1;

		int answer3 = funcline2(v3, w1);
		printf("%d\n", answer3);
		/////////////////////////////
		v3.k = 1;
		v3.b = 1;
		f3.k = 0;
		f3.b = 0;

		int answer4 = funccross(v3,f3);
		printf("%d\n", answer4);
		/////////////////////////////
		v4.p1.x = 1;
		v4.p1.y = 0;
		v4.p2.x = 0;
		v4.p2.y = 0;
		v4.p3.x = 0;
		v4.p3.y = 1;

		int answer5 = funcright(v4);
		printf("%d\n", answer5);
		///////////////////////////
		v5.p1.x = 0;
		v5.p1.y = 0;
		v5.p2.x = 1;
		v5.p2.y = 0;
		v5.p3.x = 0;
		v5.p3.y = 1;
		int answer6 = funcsquare(v5);
		printf("%d\n", answer6);
		////////////////////////////
		w3.k = 1;
		w3.b = 0;
		v6.p1.x = 0;
		v6.p1.y = 0;

		int answer7 = funclast(w3,v6);
		printf("%d\n", answer7);
	}