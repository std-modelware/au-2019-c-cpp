#include <stdio.h>
#include <math.h>

typedef struct point {
	double x;
	double y;
} point;

typedef struct point vector;

typedef struct line {
	vector d;
	point m;
} line;

typedef line ray;

typedef struct traingle {
	point a, b, c;
} traingle;

typedef struct circle {
	point o;
	double r;
} circle;

typedef struct rectangle {
	point c;
	vector v1, v2;
} rectangle;

point makePoint(double x, double y) {
	point res = { x, y };
	return res;
}

int pIsEqual(point a, point b) {
	return a.x == b.x && a.y == b.y;
}

vector pVectorTo(point p1, point p2) {
	vector res;
	res.x = p2.x - p1.x;
	res.y = p2.y - p1.y;
	return res;
}

int vAreCollinear(vector v1, vector v2) {
	if ((v1.x == 0 && v1.y == 0) || (v2.x == 0 && v2.y == 0)) return 1;
	if (v1.y == 0) {
		if (v2.y == 0) return 1;
		return 0;
	}
	if (v2.y == 0) return 0;
	if (v1.x / v1.y == v2.x / v2.y) return 1;
	return 0;
}

double vLength(vector r) {
	return sqrt(r.x * r.x + r.y * r.y);
}

double vScalarMultiplication(vector v1, vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

int vAreOrthogonal(vector a, vector b) {
	if (vScalarMultiplication(a, b) == 0) return 1;
	return 0;
}

int rAreCastedFromOnePoint(ray a, ray b) {
	return pIsEqual(a.m, b.m);
}

int pIsOnLine(point p, line l) {
	vector v = pVectorTo(l.m, p);
	return vAreCollinear(l.d, v);
}

int lAreIntersecting(line a, line b) {
	if (vAreCollinear(a.d, b.d)) return 0;
	return 1;

}
int tIsRight(traingle t) {
	vector v1 = pVectorTo(t.a, t.b);
	vector v2 = pVectorTo(t.b, t.c);
	vector v3 = pVectorTo(t.c, t.a);
	return vAreOrthogonal(v1, v2) || vAreOrthogonal(v2, v3) || vAreOrthogonal(v3, v1);
}

int rIsSquare(rectangle r) {
	return vLength(r.v1) == vLength(r.v2);
}

int isCircleCenterOnLine(circle c, line l) {
	return pIsOnLine(c.o, l);
}

line lineThroughTwoPoints(point p1, point p2) {
	line res;
	res.m = p1;
	res.d = pVectorTo(p1, p2);
	return res;
}

int main() {
	point p1 = { 0, 4 }, p2 = { 3, 0 }, p3 = { 9, 4.5 }, p4 = { 0, 0 };
	traingle t = { p1, p2, p3 };
	printf("traingle t is right: %d\n", tIsRight(t));

	p1 = makePoint(0, 0);
	p2 = makePoint(3, 0);
	p3 = makePoint(0, 4);
	p4 = makePoint(3, 4);

	rectangle r1 = { p1, pVectorTo(p1, p2), pVectorTo(p1, p3) };
	p3 = makePoint(0, 3);
	rectangle r2 = { p1, pVectorTo(p1, p2), pVectorTo(p1, p3) };
	printf("rectangle r1 is square: %d\n", rIsSquare(r1));
	printf("rectangle r2 is square: %d\n", rIsSquare(r2));

	line l1 = lineThroughTwoPoints(p2, p3);
	line l2 = lineThroughTwoPoints(p1, p4);
	printf("l1 is intersecting t2: %d\n", lAreIntersecting(l1, l2));
	printf("l1 is intersecting l1: %d\n", lAreIntersecting(l1, l1));
	printf("p2 is on l1: %d\n", pIsOnLine(p2, l1));
	printf("p1 is on l1: %d\n", pIsOnLine(p1, l1));

	ray ray1 = { p3, pVectorTo(p3, p4) };
	ray ray2 = { p1, pVectorTo(p1, p4) };
	printf("ray1 and ray2 are casted from one point: %d\n", rAreCastedFromOnePoint(ray1, ray2));
	printf("ray1 and ray1 are casted from one point: %d\n", rAreCastedFromOnePoint(ray1, ray1));

	circle c1 = { {4.5, 6}, 2 };
	circle c2 = { {4, 6}, 2 };
	printf("center of c1 is on l2: %d\n", isCircleCenterOnLine(c1, l2));
	printf("center of c2 is on l2: %d\n", isCircleCenterOnLine(c2, l2));
}