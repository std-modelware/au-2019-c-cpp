#include <math.h>
#include <stdio.h>


struct point {
	int x;
	int y;
};

int IsPointsEqual(struct point first, struct point second) {
	return ((first.x == second.x) & (first.y == second.y));
}

struct ray {
	struct point start;
	float cosA;
};

int IsRaysStartsFromOnePoint(struct ray first, struct ray second) {
	return (IsPointsEqual(first.start, second.start));
}

struct line {
	struct point one;
	struct point two;
};

struct triangle {
	struct point one;
	struct point two;
	struct point three;
};

struct rectangle {
	struct point one;
	struct point two;
};


double LineLenght(struct point fi, struct point sec) {
	return sqrt(pow((sec.x - fi.x), 2) + pow((sec.y - fi.y), 2));
}

double TriangleArea(struct triangle tri) {
	return(((tri.two.x - tri.one.x)*(tri.three.y - tri.one.y) - (tri.three.x - tri.one.x)*(tri.two.y - tri.one.y))/2);
}

int IsPointOnLine(struct line myLine, struct point myPoint) {
	struct triangle pointAndLine;
	pointAndLine.one = myLine.one;
	pointAndLine.two = myLine.two;
	pointAndLine.three = myPoint;
	return !(TriangleArea(pointAndLine));
}

float MaxValue2(float a, float b) {
	return (a > b) ? a : b;
}
float MaxValue3(float a, float b, float c) {
	return (MaxValue2(a, b) > MaxValue2(b, c)) ? MaxValue2(a, b) : MaxValue2(b, c);
}
float MinValue2(float a, float b) {
	return (a < b) ? a : b;
}
float MinValue3(float a, float b, float c) {
	return (MaxValue2(a, b) < MaxValue2(b, c)) ? MaxValue2(a, b) : MaxValue2(b, c);
}
float MiddleValue3(float a, float b, float c) {
	if (a != MinValue3(a, b, c) && a != MaxValue3(a, b, c)) return a;
	if (b != MinValue3(a, b, c) && b != MaxValue3(a, b, c)) return b;
	else return c;
}

float scalarProduct(struct line lin1, struct line lin2) {
	struct point a;
	a.x = lin1.two.x - lin1.one.x;
	a.y = lin1.two.y - lin1.one.y;
	struct point b;
	b.x = lin2.two.x - lin2.one.x;
	b.y = lin2.two.y - lin2.one.y;
    
	return a.x*b.x + a.y*b.y;
}

int IsTriangleRectangular(struct triangle tri) {
	struct line lin1;
	struct line lin2;
	struct line lin3;
	lin1.one = tri.one; lin1.two = tri.two;
	lin2.one = tri.two; lin2.two = tri.three;
	lin3.one = tri.three; lin3.two = tri.one;

	if (scalarProduct(lin1, lin2) == 0) return 1;
	if (scalarProduct(lin2, lin3) == 0) return 1;
	if (scalarProduct(lin3, lin1) == 0) return 1;
	else return 0;
}

int IsRectangleSquare(struct rectangle rec) {
	return (abs(rec.one.x - rec.two.x) == abs(rec.one.y - rec.two.y));
}

struct circle {
	struct point center;
	float radius;
};

int IsCirlceCenterOnLine(struct circle cir, struct line li) {
	return (IsPointOnLine(li, cir.center));
}

int IsLinesIntersects(struct line lin1, struct line lin2) {
	struct point a;
	a.x = lin1.two.x - lin1.one.x;
	a.y = lin1.two.y - lin1.one.y;
	struct point b;
	b.x = lin2.two.x - lin2.one.x;
	b.y = lin2.two.y - lin2.one.y;

	return !(b.x / a.x == b.y / a.y);
}

void main() {

	printf("Tests: \n \n");

	struct point a;
	struct point b;
	struct point c;
	struct point d;
	struct point e;

	a.x = 4;
	a.y = 2;

	b.x = 4;
	b.y = 2;
    
	c.x = 2;
	c.y = 1;

	d.x = 3;
	d.y = 5;

	e.x = 8;
    e.y = 4;
	
	struct line lin1;
	lin1.one = b;
	lin1.two = e;



	printf("are points equal (should be 1): %d \n", IsPointsEqual(a, b));
	printf("are points equal (should be 0): %d \n \n", IsPointsEqual(a, c));

	struct ray ray1;
	struct ray ray2;
	struct ray ray3;
	ray1.start = a; ray1.cosA = 1;
	ray2.start = b; ray2.cosA = 1 / 2;
	ray3.start = c; ray3.cosA = 0;

	printf("are ray origin the same(should be 1): %d \n", IsRaysStartsFromOnePoint(ray1, ray2));
	printf("are ray origin the same(should be 0): %d \n \n", IsRaysStartsFromOnePoint(ray3, ray2));

	printf("are point on a line (should be 1): %d \n", IsPointOnLine(lin1, c));
	printf("are point on a line (should be 0): %d \n \n", IsPointOnLine(lin1, d));



	struct point h;
	h.x = 5;
	h.y = 6;

	struct line lin2;
	lin2.one = d;
	lin2.two = h;

	struct line lin3;
	lin3.one = b;
	lin3.two = h;


	printf("are lines intersect(should be 1): %d \n", IsLinesIntersects(lin3, lin2));
	printf("are lines intersect(should be 0): %d \n \n", IsLinesIntersects(lin1, lin2));

	struct point recp1;
	recp1.x = 3; recp1.y = 3;
	struct point recp2;
	recp2.x = 6; recp2.y = 3;
	struct point recp3;
	recp3.x = 6; recp3.y = 6;

	struct rectangle rec1;
	rec1.one = recp1;
	rec1.two = recp3;

	struct rectangle rec2;
	rec2.one = recp1;
	rec2.two = h;


	struct triangle tri1;
	tri1.one = recp1;
	tri1.two = recp2;
	tri1.three = recp3;
	struct triangle tri2;
	tri2.one = recp1;
	tri2.two = recp2;
	tri2.three = h;

	printf("are triangle rectangular(should be 1): %d \n", IsTriangleRectangular(tri1));
	printf("are triangle rectangular(should be 0): %d \n \n", IsTriangleRectangular(tri2));

	printf("are rectangle is square(should be 1): %d \n", IsRectangleSquare(rec1));
	printf("are rectangle is square(should be 0): %d \n \n", IsRectangleSquare(rec2));

	struct circle cir;
	cir.center = c;
	cir.radius = 2;

	struct circle cir2;
	cir2.center = d;
	cir2.radius = 2;

	printf("are line on circle center (should be 1): %d \n", IsCirlceCenterOnLine(cir, lin1));
	printf("are line on circle center (should be 0): %d \n \n", IsCirlceCenterOnLine(cir2, lin1));
}