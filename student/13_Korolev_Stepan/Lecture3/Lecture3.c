//Очень долго старался, Королев Степан

#include <math.h>
#include <stdio.h>
#include <CException.h>
#define TarInitError 11
#define RectInitError 12

struct Point {
	long int x, y; //координаты на плоскости
};

struct Straight {
	double k, b; //коэффициент и смещение
};

struct LineSegment {
	struct Point A, B;
	double distance;
};

struct Ray {
	struct Point p; //начало луча
	double k; //коэффициент прямой
	int sign; //направление относительно оси X, вектор луча (необходимо при k = 0)
};

struct Triangular {
	struct LineSegment a, b, c;
};

struct Rectangular {
	struct LineSegment a, b;
};

struct Circle {
	struct Point O;
	double r;
};

int IsPointEqual(struct Point pt1, struct Point pt2) {
	return (pt1.x == pt2.x && pt1.y == pt2.y ? 1 : 0);
}

int IsRayBeginningsEqual(struct Ray r1, struct Ray r2) {
	return (r1.p.x == r2.p.x && r1.p.y == r2.p.y ? 1 : 0);
}

int IsPointInStraight(struct Point pt, struct Straight st) {
	return (pt.y == (st.k * pt.x + st.b) ? 1 : 0);
}

int IsStraightCrossing(struct Straight st1, struct Straight st2) {
	return (st1.k == st2.k && st1.b != st2.b ? 0 : 1);
}

double GetPointDistance(struct Point pt1, struct Point pt2) {
	return (sqrt(pow(((double)pt2.x - (double)pt1.x), 2) + pow((double)pt2.y - (double)pt1.y, 2)));
}

struct LineSegment CreateLineSegment(struct Point pt1, struct Point pt2) {
	struct LineSegment ls;
	ls.A = pt1;
	ls.B = pt2;
	ls.distance = GetPointDistance(pt1, pt2);
	return ls;
}

struct Straight CreateStraight(struct LineSegment ls) {
	struct Straight st;
	st.k = (((double)ls.A.x - (double)ls.B.x) != 0 ? ((double)ls.A.y - (double)ls.B.y) / ((double)ls.A.x - (double)ls.B.x) : 0);
	st.b = ((double)ls.A.x - (double)ls.B.x != 0 ? ((double)ls.A.x * (double)ls.B.y - (double)ls.B.x * (double)ls.A.y) / ((double)ls.A.x - (double)ls.B.x) : 0);
	return st;
}

struct Triangular CreateTriangular(struct LineSegment ls1, struct LineSegment ls2, struct LineSegment ls3) { //ls3 - гипотенуза
	CEXCEPTION_T e;
	struct Straight st1 = CreateStraight(ls1);
	struct Straight st2 = CreateStraight(ls2);
	struct Straight st3 = CreateStraight(ls3);
	Try {
		if (ls1.distance + ls2.distance < ls3.distance || ls2.distance + ls3.distance < ls1.distance || ls3.distance + ls1.distance < ls2.distance || IsStraightCrossing(st1, st2) == 0 || IsStraightCrossing(st2, st3) == 0 || IsStraightCrossing(st3, st1) == 0 || (IsPointInStraight(ls2.A, st1) == 1 && IsPointInStraight(ls2.B, st1) == 1) || (IsPointInStraight(ls3.A, st1) == 1 && IsPointInStraight(ls3.B, st1) == 1) || (IsPointInStraight(ls1.A, st2) == 1 && IsPointInStraight(ls1.B, st2) == 1) || (IsPointInStraight(ls3.A, st2) == 1 && IsPointInStraight(ls3.B, st2) == 1) || (IsPointInStraight(ls2.A, st3) == 1 && IsPointInStraight(ls2.B, st3) == 1) || (IsPointInStraight(ls1.A, st3) == 1 && IsPointInStraight(ls1.B, st3) == 1) || (IsPointInStraight(ls2.A, st1) == 0 && IsPointInStraight(ls2.B, st1) == 0) || (IsPointInStraight(ls3.A, st1) == 0 && IsPointInStraight(ls3.B, st1) == 0) || (IsPointInStraight(ls1.A, st2) == 0 && IsPointInStraight(ls1.B, st2) == 0) || (IsPointInStraight(ls3.A, st2) == 0 && IsPointInStraight(ls3.B, st2) == 0) || (IsPointInStraight(ls2.A, st3) == 0 && IsPointInStraight(ls2.B, st3) == 0) || (IsPointInStraight(ls1.A, st3) == 0 && IsPointInStraight(ls1.B, st3) == 0)) { //проверка на существование
			Throw(TarInitError);
		}
	}
	Catch(e) {
		switch (e) {
			case TarInitError:
				printf("Unable to create tar with following line segments:\nls1: %f\nls2: %f\nls3: %f\n", ls1.distance, ls2.distance, ls3.distance);
				break;
			default:
				printf("Unknown error: %d\n", e);
				break;
			}
	}
	 
	if (ls1.distance > ls2.distance && ls1.distance > ls3.distance) {
		struct LineSegment tmp = ls1;
		ls1 = ls3;
		ls3 = tmp;
	}
	else if (ls2.distance > ls1.distance&& ls2.distance > ls3.distance) {
		struct LineSegment tmp = ls2;
		ls2 = ls3;
		ls3 = tmp;
	}
	struct Triangular tar = { ls1, ls2, ls3 };
	return tar;
}

int IsTriangularRight(struct Triangular tar) {
	return (pow(tar.c.distance, 2) == (pow(tar.a.distance, 2) + pow(tar.b.distance, 2)) ? 1 : 0);
}

struct Rectangular CreateRectangular(struct LineSegment ls1, struct LineSegment ls2) {
	CEXCEPTION_T e;
	struct Straight st1 = CreateStraight(ls1);
	struct Straight st2 = CreateStraight(ls2);
	int cond = (st1.k * st2.k == -1 || st1.k * st2.k == 0 ? -1 : st1.k * st2.k); //проверка на прямой угол
	Try {
		if (IsStraightCrossing(st1, st2) == 0 || (IsPointInStraight(ls2.A, st1) == 1 && IsPointInStraight(ls2.B, st1) == 1) || (IsPointInStraight(ls2.A, st1) == 0 && IsPointInStraight(ls2.B, st1) == 0) || cond != -1) { //проверка на существование
			Throw(RectInitError);
		}
		else {
			
		}
	}
	Catch(e) {
		switch(e) {
		case RectInitError:
			printf("Unable to create rect with following line segments:\nls1: %f\nls2: %f\n", ls1.distance, ls2.distance);
			break;
		default:
			printf("Unknown error: %d\n", e);
			break;
		}
	}
	struct Rectangular rect = {ls1, ls2};
	return rect;
}

int RectangularIsSquare(struct Rectangular rect) {
	return (rect.a.distance > 0 && rect.a.distance == rect.b.distance ? 1 : 0);
}

int IsStraightCrossingCircleInCenter(struct Circle c, struct Straight st) {
	return IsPointInStraight(c.O, st);
}

int main()
{
	struct Point pt1 = { 4, 8 };
	struct Point pt2 = { 4, 8 };
	struct Point pt3 = { 5, 8 };
	printf("pt1 is equal to pt2: %d\npt1 is equal to pt3: %d\n", IsPointEqual(pt1, pt2), IsPointEqual(pt1, pt3));
	struct Ray r1 = { pt1, 2 };
	struct Ray r2 = { pt2, 3 };
	struct Ray r3 = { pt3, 4 };
	printf("r1 is beginning equal to r2: %d\nr1 is beginning equal to r3: %d\n", IsRayBeginningsEqual(r1, r2), IsRayBeginningsEqual(r1, r3));
	struct Straight st1 = { 2, -2 };
	printf("r1 is in straight st1: %d\nr3 is in straight st1: %d\n", IsPointInStraight(pt1, st1), IsPointInStraight(pt3, st1));
	struct Straight st2 = { 2, 0 };
	struct Straight st3 = { 2, -2 };
	struct Straight st4 = { -2, -2 };
	printf("st1 is crossing st2: %d\nst1 is crossing st3: %d\nst1 is crossing st4: %d\n", IsStraightCrossing(st1, st2), IsStraightCrossing(st1, st3), IsStraightCrossing(st1, st4));
	struct Point A = { 2, 5 };
	struct Point B = { 4, -3 };
	struct Point C = { -1, 2 };
	struct LineSegment a = CreateLineSegment(B, C);
	struct LineSegment b = CreateLineSegment(C, A);
	struct LineSegment c = CreateLineSegment(A, B);
	struct Triangular tar = CreateTriangular(a, b, c);
	struct Triangular _tar = CreateTriangular(CreateLineSegment(A, pt3), CreateLineSegment(pt3, C), CreateLineSegment(C, A)); //нельзя построить этот треугольник
	printf("tar is right: %d\n_tar is right: %d\n", IsTriangularRight(tar), IsTriangularRight(_tar));
	struct Rectangular rect = CreateRectangular(a, b);
	struct Rectangular _rect = CreateRectangular(CreateLineSegment(pt1, pt2), CreateLineSegment(pt2, pt1));
	A.x = -2;
	A.y = -1;
	B.x = -2;
	B.y = -4;
	C.x = 1;
	C.y = -4;
	struct Rectangular _square = CreateRectangular(CreateLineSegment(A, B), CreateLineSegment(B, C));
	printf("rect is square: %d\n_rect is square: %d\n_square is square: %d\n", RectangularIsSquare(rect), RectangularIsSquare(_rect), RectangularIsSquare(_square));
	struct Circle cc = { B, 5 };
	struct Circle _cc = { C, 3 };
	st1.k = 1;
	printf("cc is crossed by st1: %d\n_cc is crossed by st1: %d\n", IsStraightCrossingCircleInCenter(cc, st1), IsStraightCrossingCircleInCenter(_cc, st2));

	return 0;
}