#include <stdio.h>
#include "struct.h"
#include <math.h>
#include <stdlib.h>

void twopoints_func(struct point a, struct point b);
void tworays_func(struct point a, struct point b);
void point_on_straigt_func(struct straigt2 strt, struct point a);
void triangle_func(struct triangle trg);
void crossings_straigts(struct straigt2 strt1, struct straigt2 strt2);
void rectangle_func(struct rectangle rect);
void circle_func(struct circle crl, struct straigt2 strt1);
float lenght_square_func(struct point a, struct point b);

void main () {
	struct point a, b, c;
	printf("Input two times X and Y:\n");
	scanf_s("%f %f %f %f", &a.x, &a.y, &b.x, &b.y);
	twopoints_func(a,b);

	printf("Input two times X and Y:\n");
	scanf_s("%f %f %f %f", &a.x, &a.y, &b.x, &b.y);
	tworays_func(a, b);

	struct straigt2 strt1, strt2;
	printf("Input A and B & X and Y:\n");
	scanf_s("%f %f %f %f", &strt1.a, &strt1.b, &a.x, &a.y);
	point_on_straigt_func(strt1, a);
	
	printf("Input two times A and B:\n");
	scanf_s("%f %f %f %f", &strt1.a, &strt1.b, &strt2.a, &strt2.b);
	crossings_straigts(strt1, strt2);

	struct triangle trg;
	printf("Input three points:\n");
	scanf_s("%f %f %f %f %f %f", &trg.a.x, &trg.a.y, &trg.b.x, &trg.b.y, &trg.c.x, &trg.c.y);
	triangle_func(trg);

	struct rectangle rect;
	printf("Input two points:\n");
	scanf_s("%f %f %f %f", &rect.topleft.x , &rect.topleft.y, &rect.rightdown.x, &rect.rightdown.y);
	rectangle_func(rect);

	struct circle crl;
	printf("Input circles' centre:\n");
	scanf_s("%f %f %f %f", &crl.centre.x, &crl.centre.y, &strt1.a, & strt1.b);
	circle_func(crl, strt1);
}
// квадрат длинны 
float lenght_square_func (struct point a, struct point b) {
	return ( pow((a.y - b.y), 2) + pow((a.x - b.x), 2));
}
// две точки
void twopoints_func (struct point a, struct point b){
	if ((a.x == b.x) && (a.y == b.y)) {
		printf("Two points are equal\n");
	}
	else {
		printf("Two points are not equal\n");
	}
}
// два луча
void tworays_func (struct point a, struct point b) {
	if ((a.x == b.x) && (a.y == b.y)) {
		printf("Two rays exit the same point\n");
	}
	else {
		printf("Two rays do not exit the same point\n");
	}
}
// точка и прямая
void point_on_straigt_func (struct straigt2 strt, struct point a) {
	if (a.y == strt.a * a.x + strt.b) {
		printf("The point lies on a straight line\n");
	}
	else {
		printf("The point does not lie on a straight line\n");
	}
}
// две прямые
void straigt1_straigt2_func(struct point a, struct point b) {
	if ((a.x == b.x) && (a.y == b.y)) {
		printf("Two rays exit the same point\n");
	}
	else {
		printf("Two rays exit the same point\n");
	}
}
// точка пересечения двух прямых
void crossings_straigts(struct straigt2 strt1, struct straigt2 strt2) {
	if ((strt1.a == strt2.a) && (strt1.b != strt2.b)) {
		printf("Two straights do not intersect\n");
	}
	else if ((strt1.a == strt2.a) && (strt1.b == strt2.b)) {
		printf("Two straigts coincide and have infinitely many intersection points!\n");
	}
	else {
		printf("Two straights are crossed\n");
	}
}
// треугольник 
void triangle_func (struct triangle trg) {
	float ab2, bc2, ac2;
	ab2 = lenght_square_func(trg.a, trg.b);
	bc2 = lenght_square_func(trg.b, trg.c);
	ac2 = lenght_square_func(trg.a, trg.c);
	if  (ab2 == bc2 + ac2) {
		printf("Triangle is rectangular\n");
	}
	else if (bc2 == ab2 + ac2) {
		printf("Triangle is rectangular\n");
	}
	else if (ac2 == ab2 + bc2) {
		printf("Triangle is rectangular\n");
	}
	else {
		printf("Triangle is not rectangular\n");
	}
}
// прямоугольник
void rectangle_func(struct rectangle rect) {
	float ab2, bc2;
	struct point temp;
	temp.x = rect.topleft.x;
	temp.y = rect.rightdown.y;
	ab2 = lenght_square_func(rect.topleft, temp);
	bc2 = lenght_square_func(rect.rightdown, temp);
	if (ab2 == bc2) {
		printf("The rectangle is a square\n");
	}
	else {
		printf("The rectangle is not a square\n");
	}
}
// окружность
void circle_func(struct circle crl, struct straigt2 strt1) {
	//point_on_straigt_func(strt1, crl.centre);
	if (crl.centre.y == strt1.a * crl.centre.x + strt1.b) {
		printf("Straight pass through the center of the circle\n");
	}
	else {
		printf("Straight does not pass through the center of the circle!\n");
	}
}