#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

using namespace std;

typedef struct {
	double x;
	double y;
} Dot;

typedef struct {
	Dot p;
	double k;
} Ray;

typedef struct {
	double k;
	double b;
} Line;

typedef struct {
	Dot p1;
	Dot p2;
	Dot p3;
} Triangle;

typedef struct {
	Dot p1;
	Dot p2;
	Dot p3;
} Rectangle;

typedef struct {
	Dot p;
	double r;
} Circle;

double distance_dots(Dot p1, Dot p2) {
	return (sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}

int equal_dots(Dot p1, Dot p2) {
	if (p1.x == p2.x && p1.y == p2.y) { return 1; }
	return 0;
}

int samebeggining_rays(Ray r1, Ray r2) {
	if (equal_dots(r1.p, r2.p)) { return 1; }
	return 0;
}

int in_dot_line(Dot p, Line l) {
	if (l.k*p.x + l.b == p.y) { return 1; }
	return 0;
}

int cross_line(Line l1, Line l2) {
	if (l1.k != l2.k) { return 1; }
	return 0;
}

int isright_triangle(Triangle t) {
	double l1 = distance_dots(t.p1, t.p2);
	double l2 = distance_dots(t.p2, t.p3);
	double l3 = distance_dots(t.p3, t.p1);
	if (l1*l1 + l2*l2 == l3*l3 || l2*l2 + l3*l3 == l1*l1 || l3*l3 + l1*l1 == l2*l2) { return 1; }
	return 0;
}

int issquare_rectangle(Rectangle r){
	double l1 = distance_dots(r.p1, r.p2);
	double l2 = distance_dots(r.p2, r.p3);
	double l3 = distance_dots(r.p3, r.p1);
	if (l1 == l2 || l2 == l3 || l3 == l1) { return 1; }
	return 0;
}

int isthroughcenter_line_circle(Line l, Circle c) {
	if (in_dot_line(c.p, l)) { return 1; }
	return 0;
}

void main() {

	Dot p1 = { 1, 2 };
	Dot p2 = { 1, 6 };
	Dot p3 = { 5, 6 };
	Dot p4 = { 3, 5 };
	Dot p5 = { 5,5 };
	Ray r1 = { p1, 6 };
	Ray r2 = { p1,7 };
	Ray r3 = { p2, 8 };
	Line l1 = { 4, -2 };
	Line l2 = { 3, -5 };
	Line l3 = { 4, -3 };
	Triangle t1 = { p1,p2,p3 };
	Triangle t2 = { p1,p2,p4 };
	Rectangle rec1 = { p1,p2,p3 };
	Rectangle rec2 = { p1,p2,p5 };
	Circle c1 = { p1, 8 };
	Circle c2 = { p2, 7 };

	cout << "Are dots A(1,2) and B(1,6) equal?:" << equal_dots(p1, p2) << endl;
	cout << "Are dots A(1,2) and B(1,2) equal?:" << equal_dots(p1, p1) << endl;
	cout << "Are rays A(start point - (1,2), angular coefficient - 6) AND B(start point - (1,2), angular coefficient - 7) start from the same point?:" << samebeggining_rays(r1, r2) << endl;
	cout << "Are rays A(start point - (1,6), angular coefficient - 6) AND B(start point - (1,2), angular coefficient - 7) start from the same point?:" << samebeggining_rays(r2, r3) << endl;
	cout << "Is dot A(1,2) in line 4x - 2?:" << in_dot_line(p1, l1) << endl;
	cout << "Is dot A(1,6) in line 4x - 2?:" << in_dot_line(p2, l1) << endl;
	cout << "Are lines 4x - 2 and 3x - 5 cross?:" << cross_line(l1, l2) << endl;
	cout << "Are lines 4x - 2 and 4x - 3 cross?:" << cross_line(l1, l3) << endl;
	cout << "Is triangle of points A(1,2), B(1,6), C(5,6) right?:" << isright_triangle(t1) << endl;
	cout << "Is triangle of points A(1,2), B(1,6), C(3,5) right?:" << isright_triangle(t2) << endl;
	cout << "Is rectangle of points A(1,2), B(1,6), C(5,6), D(5,1) - square?:" << issquare_rectangle(rec1) << endl;
	cout << "Is rectangle of points A(1,2), B(1,6), C(5,5), D(2,-3) - square?:" << issquare_rectangle(rec2) << endl;
	cout << "Is center of circle O(center - (1,2), radius - 8) in line 4x-2?:" << isthroughcenter_line_circle(l1, c1) << endl;
	cout << "Is center of circle O(center - (1,6), radius - 7) in line 4x-2?:" << isthroughcenter_line_circle(l1, c2) << endl;

}