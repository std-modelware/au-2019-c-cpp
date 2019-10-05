#include <stdio.h>
#include <math.h>

struct point {
	double x;
	double y;
};

struct ray {
	struct point start_point;
	struct point point;
};

struct line {
	struct point first_cord;
	struct point second_cord;
};

struct triangle {
	struct point first_cord;
	struct point second_cord;
	struct point third_cord;
};

struct rectangle {
	struct point first_cord;
	struct point second_cord;
};

struct circle {
	struct point center_p;
	float radius;
};

double max(double a, double b)
{
	return (a >= b ? a : b);
}

int EqualOfPoints(struct point p1, struct point p2) {
	return ((p1.x == p2.x) && (p1.y == p2.y));
}

int TRAP(struct ray r1, struct ray r2) {
	return ((r1.start_point.x == r2.start_point.x) && (r1.start_point.y == r2.start_point.y));
}

int POTheL(struct line l, struct point p) {
	float a, b;
	a = (l.first_cord.y - l.second_cord.y) / (l.first_cord.x - l.second_cord.x);
	b = l.first_cord.y - a * l.first_cord.x;
	return (a * p.x + b == p.y);
}

int InterOTL(struct line l1, struct line l2) {
	return  ((l1.second_cord.y - l1.first_cord.y) / (l1.second_cord.x - l1.first_cord.x) != (l2.second_cord.y - l2.first_cord.y) / (l2.second_cord.x - l2.first_cord.x));
}

int RightTriangle(struct triangle triangle){
	
	double s1;
	double s2;
	double s3;
	s1 = pow((triangle.second_cord.x - triangle.first_cord.x), 2) + pow((triangle.second_cord.y - triangle.first_cord.y), 2);
	s2 = pow((triangle.third_cord.x - triangle.second_cord.x), 2) + pow((triangle.third_cord.y - triangle.second_cord.y), 2);
	s3 = pow((triangle.first_cord.x - triangle.third_cord.x), 2) + pow((triangle.first_cord.y - triangle.third_cord.y), 2);

	double gip = max(max(s1, s2), s3);

	if (gip == s1) {
		return (gip == s2 + s3);
	} 
	else if (gip == s2) {
		return (gip == s1 + s3);
	}
	else {
		return (gip == s1 + s2);
	}
	/*
	switch (gip) {
	case s1:
		return sqrt(gip) == sqrt(s2) + sqrt(s3);
		break;
	case s2:
		return sqrt(gip) == sqrt(s1) + sqrt(s3);
		break;
	case s3:
		return sqrt(gip) == sqrt(s1) + sqrt(s2);
		break;
	default:
		return 0;
		break;
	}
	*/		
}

int ItsSquare(struct rectangle rect) {
	return (abs(rect.first_cord.x - rect.second_cord.x) == abs(rect.first_cord.y - rect.second_cord.y));
}

int CirlceCenter(struct circle c, struct line l) {
	return (POTheL(l, c.center_p));
}

int main() {

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

	printf("(1) %d \n", EqualOfPoints(a, b));
	printf("(1) %d \n\n", EqualOfPoints(c, d));

	struct ray ray_1;
	struct ray ray_2;
	struct ray ray_3;
	
	ray_1.start_point = a; 
	ray_1.point = d;
	
	ray_2.start_point = b; 
	ray_2.point = e;
	
	ray_3.start_point = c; 
	ray_3.point = c;

	printf("(2) %d \n", TRAP(ray_1, ray_2));
	printf("(2) %d \n\n", TRAP(ray_1, ray_3));

	struct line l_1;
	l_1.first_cord = b;
	l_1.second_cord = e;

	printf("(3) %d \n", POTheL(l_1, c));
	printf("(3) %d \n\n", POTheL(l_1, d));

	struct point h;
	h.x = 5;
	h.y = 6;

	struct line l_2;
	l_2.first_cord = d;
	l_2.second_cord = h;

	struct line l_3;
	l_3.first_cord = b;
	l_3.second_cord = h;

	printf("(4) %d \n", InterOTL(l_3, l_2));
	printf("(4) %d \n", InterOTL(l_1, l_2));
	printf("(4) %d \n\n", InterOTL(l_2, l_2));

	struct point rec_point_1;
	rec_point_1.x = 3; rec_point_1.y = 3;
	struct point rec_point_2;
	rec_point_2.x = 6; rec_point_2.y = 3;
	struct point rec_point_3;
	rec_point_3.x = 6; rec_point_3.y = 6;

	
	struct triangle tr_point_1;
	tr_point_1.first_cord = rec_point_1;
	tr_point_1.second_cord = rec_point_2;
	tr_point_1.third_cord = rec_point_3;
	
	struct triangle tr_point_2;
	tr_point_2.first_cord = rec_point_1;
	tr_point_2.second_cord = rec_point_2;
	tr_point_2.third_cord = e;

	printf("(5) %d \n", RightTriangle(tr_point_1));
	printf("(5) %d \n\n", RightTriangle(tr_point_2));

	struct rectangle rect1;
	rect1.first_cord = rec_point_1;
	rect1.second_cord = rec_point_3;

	struct rectangle rect2;
	rect2.first_cord = rec_point_1;
	rect2.second_cord = e;

	printf("(6) %d \n", ItsSquare(rect1));
	printf("(6) %d \n\n", ItsSquare(rect2));
	
	struct circle circle_1;
	circle_1.center_p = c;
	circle_1.radius = 2;

	struct circle circle_2;
	circle_2.center_p = d;
	circle_2.radius = 2;

	printf("(7) %d \n", CirlceCenter(circle_1,l_1));
	printf("(7) %d \n\n", CirlceCenter(circle_2, l_1));

}