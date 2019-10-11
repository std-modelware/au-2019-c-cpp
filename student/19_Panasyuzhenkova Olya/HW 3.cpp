#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void twopoints(struct point a, struct point b);
void tworays(struct point a, struct point b);
void point_on_line(struct straigt2 strt, struct point a);
void triangle(struct triangle trg);
void straight_cr(struct straigt2 strt1, struct straigt2 strt2);
void rectangle(struct rectangle rect);
void circle(struct circle crl, struct straigt2 strt1);
float lenght_func(struct point a, struct point b);

//STRUCTURES

struct point  //Point Structure
{
	float x; //Coordinates X-Y 
	float y;
};

struct ray //Ray Structure
{
	struct point a0; //Start point
	float angle; //angle
};
struct straigt1 //Two straights for 4th task
{
	struct point a; //Coorsinates X-Y 2 points
	struct point b;
};
struct straigt2  // Equation: y=ax+b
{
	float a; 
	float b;			
};
struct triangle //Triangle Structure
{
	struct point a; //Three points
	struct point b;
	struct point c;
}; 
struct rectangle //Rectangle Structure
{
	struct point r1;
	struct point r3;
};
struct circle //Circle Structure
{
	struct point c0; //center
	float cr; //radius
};

//FUNCTIONS
void twopoints(struct point a, struct point b) { //DONE
	if ((a.x == b.x) && (a.y == b.y)) {
		printf("Equal\n\n");
	}
	else {
		printf("Not equal\n\n");
	}
}

void tworays(struct point a, struct point b) {  //DONE
	if ((a.x == b.x) && (a.y == b.y)) {
		printf("From one point\n\n");
	}
	else {
		printf("Not from one point\n\n");
	}
}

void point_on_line(struct straigt2 line, struct point a) { //DONE
	if (a.y == line.a * a.x + line.b) {
		printf("Point on line \n\n");
	}
	else {
		printf("Point doesn't on line\n\n");
	}
}


void straight_cr(struct straigt2 strt1, struct straigt2 strt2) { //DONE
	if ((strt1.a == strt2.a) && (strt1.b != strt2.b)) { 
		printf("Lines doesn't intersect\n\n");
	}
	else if ((strt1.a == strt2.a) && (strt1.b == strt2.b)) {
		printf("Lines coinside\n\n");
	}
	else {
		printf("Lines intersect\n\n");
	}
}

void triangle(struct triangle trg) { //DONE
	float ab2, bc2, ac2;
	ab2 = lenght_func(trg.a, trg.b); //length of segments
	bc2 = lenght_func(trg.b, trg.c);
	ac2 = lenght_func(trg.a, trg.c);
	if (ab2 == bc2 + ac2) {
		printf("Triangle is rectangular\n\n");
	}
	else if (bc2 == ab2 + ac2) {
		printf("Triangle is rectangular\n\n");
	}
	else if (ac2 == ab2 + bc2) {
		printf("Triangle is rectangular\n\n");
	}
	else {
		printf("Triangle isn't rectangular\n\n");
	}
}

void rectangle(struct rectangle rec) { //DONE
	float ab2, bc2;
	struct point temp;
	temp.x = rec.r1.x;
	temp.y = rec.r3.y;
	ab2 = lenght_func(rec.r1, temp);
	bc2 = lenght_func(rec.r3, temp);
	if (ab2 == bc2) {
		printf("Square\n\n");
	}
	else {
		printf("Not a square\n\n");
	}
}

void circle(struct circle cr, struct straigt2 strtt1) {
	point_on_line(strtt1, cr.c0);
	if (cr.c0.y == strtt1.a * cr.c0.x + strtt1.b) {
		printf("Pass\n");
	}
	else {
		printf("Doesn't pass!\n");
	}
}

float lenght_func(struct point a, struct point b) {
	return (pow((a.y - b.y), 2) + pow((a.x - b.x), 2));
}


void main() {

	struct point a, b;
	    printf("1) Checking 2 points for EQUALITY:\n"); //done
		printf("Enter X and Y coordinates 1st point:\n");
		scanf_s("%f %f", &a.x, &a.y);
		printf("Enter X and Y coordinates 2nd point:\n");
		scanf_s("%f %f",  &b.x, &b.y);
		twopoints(a, b);

		printf("2) Checking 2 rays at the START POINT:\n"); //done
		printf("Enter X and Y of start point RAY 1:\n");
	    scanf_s("%f %f", &a.x, &a.y);
		printf("Enter X and Y of start point RAY 2:\n");
		scanf_s("%f %f", &b.x, &b.y);
	    tworays(a, b);

		
		struct straigt2 strt1, strt2;  //done
		printf("3) Does the point ON LINE:\n"); 
		printf("Enter coeff-s A and B of line :\n");
		scanf_s("%f %f", &strt1.a, &strt1.b);
		printf("Enter X and Y of point:\n");
		scanf_s("%f %f", &a.x, &a.y);
		point_on_line(strt1, a);


		printf("4) INTERSECTING LINES?:\n"); //done
		printf("Enter coeff-s A and B of line 1:\n");
		scanf_s("%f %f", &strt1.a, &strt1.b);
		printf("Enter coeff-s A and B of line 2:\n");
		scanf_s("%f %f", &strt2.a, &strt2.b);
		straight_cr(strt1, strt2);

		struct triangle trg; //done
		printf("5) Is triangle rectangular?:\n");
		printf("Enter different coord-s X,Y of 1st point:\n");
		scanf_s("%f %f", &trg.a.x, &trg.a.y);
		printf("Enter different coord-s X,Y of 2nd point:\n");
		scanf_s("%f %f", &trg.b.x, &trg.b.y);
		printf("Enter different coord-s X,Y of 3rd point:\n");
		scanf_s("%f %f", &trg.c.x, &trg.c.y);
		triangle(trg);

		struct rectangle rec; //done
		printf("6) Is rectangle a SQUARE?:\n");
		printf("Enter coord-s of 1st point:\n");
		scanf_s("%f %f", &rec.r1.x, &rec.r1.y);
		printf("Enter coord-s of 2nd point:\n");
		scanf_s("%f %f", &rec.r3.x, &rec.r3.y);
		rectangle(rec);

		struct circle crl;
		printf("7) Does the line cross the center of the circle?:\n");
		printf("Enter coord-s X, Y of circles' center:\n");
		scanf_s("%f %f", &crl.c0.x, &crl.c0.y);
		printf("Enter coeff-s A,B of line:\n");
		scanf_s("%f %f", &strt1.a, &strt1.b);
		circle(crl, strt1);
}

