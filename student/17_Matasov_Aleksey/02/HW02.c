#include <stdio.h>
#include <math.h>
 
double min(double a, double b){
    if(a>b) return b;
    return a;
}
 
double max(double a, double b){
    if( a>b ) return a;
    return b;
}
 
typedef struct point {
    double x, y;
} point;
 
typedef struct ray {
    point A, B;
} ray;
 
typedef struct line {
    point A, B;
    double a; // B.y - A.y;
    double b; // B.x - A.x;
    double c; // B.x*A.y - B.y*A.x;
} line;

line buildLine(point A, point B) {
    line l = {A, B};
    l.a = B.y - A.y;
    l.b = A.x - B.x;
    l.c = B.x*A.y - B.y*A.x;
    return l;
}

typedef struct triangle {
    point A, B, C;
    double aa; // (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
    double bb; // (C.x-B.x)*(C.x-B.x) + (C.y-B.y)*(C.y-B.y);
    double cc; // (A.x-C.x)*(A.x-C.x) + (A.y-C.y)*(A.y-C.y);
} triangle;
 
triangle buildTriangle(point A, point B, point C) {
    triangle t;
    t.A = A;
    t.B = B;
    t.C = C;
    t.aa = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
    t.bb = (C.x-B.x)*(C.x-B.x) + (C.y-B.y)*(C.y-B.y);
    t.cc = (A.x-C.x)*(A.x-C.x) + (A.y-C.y)*(A.y-C.y);
    return t;
}

typedef struct circle {
    point O;
    double r;
} circle;
 
typedef struct rectangle {
    point A, B, C, D;
    double aa;
    double bb;
    double cc;
    double dd;
} rectangle;

rectangle buildRectangle(point A, point B, point C, point D) {
    rectangle r = {A, B, C, D};
    r.aa = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
    r.bb = (C.x-B.x)*(C.x-B.x) + (C.y-B.y)*(C.y-B.y);
    r.cc = (D.x-C.x)*(D.x-C.x) + (D.y-C.y)*(D.y-C.y);
    r.dd = (A.x-D.x)*(A.x-D.x) + (A.y-D.y)*(A.y-D.y);
    return r;
}
 
 
int pEquality(point A, point B) {
    return A.x == B.x && A.y == B.y;
}
 
int rStartPointEquality(ray a, ray b) {
    return pEquality(a.A, b.A) ;
}
 
int pointIsOnLine (point M, line a) {
    return a.a*M.x + a.b*M.y + a.c == 0;
}
 
int linesIntersect (line l, line m) {
    return (l.a / m.a) != (l.b / m.b) || pointIsOnLine(l.A, m) == 1;
}
 
int triangleIsRight (triangle t) { 
    return ( min(t.aa, min(t.bb, t.cc)) + (t.aa + t.bb + t.cc - min(t.aa, min(t.bb, t.cc)) - max(t.aa, max(t.bb, t.cc))) ==
max(t.aa, max(t.bb, t.cc)) );
}
 
int rectangleIsSquare (rectangle r) {
    return r.aa == r.bb;
}
 
int circleCenterIsOnLine (circle c, line l) {
    return pointIsOnLine(c.O, l);
}
 
int main() {
    point p1 = { 0, 4 }, p2 = {0, 0}, p3 = {3, 0}, p4 = {0, 4}, p5 = {6, -4}, p6 = {0, 2}, p7 = {1.5, 0}, p8 = {3, 2}, p9 = {0, 3}, p10 = {3, 3};
    ray r1 = {p1, p2}, r2 = {p3, p2}, r3 = {p4, p3};
    line l1 = buildLine(p1, p3), l2 = buildLine(p6, p7), l3 = buildLine(p2, p5);
    triangle t1 = buildTriangle(p1, p2, p3), t2 = buildTriangle(p2, p3, p5);
    rectangle rec1 = buildRectangle(p2, p6, p8, p3), rec2 = buildRectangle(p3, p2, p9, p10);
    circle c = {p5, 4};
    printf("p1 == p4 : %d\n", pEquality(p1, p4));
    printf("p3 == p4 : %d\n", pEquality(p3, p4));
    printf("r1 start point == r2 start point : %d\n", rStartPointEquality(r1, r2));
    printf("r1 start point == r3 start point : %d\n", rStartPointEquality(r1, r3));
    printf("p5 is on line l1 : %d\n", pointIsOnLine(p5, l1));
    printf("p6 is on line l1 : %d\n", pointIsOnLine(p6, l1));
    printf("l1 intersect l2 : %d\n", linesIntersect(l1, l2));
    printf("l1 intersect l3 : %d\n", linesIntersect(l1, l3));
    printf("t1 is right : %d\n", triangleIsRight(t1));
    printf("t2 is right : %d\n", triangleIsRight(t2));
    printf("rec1 is square : %d\n", rectangleIsSquare(rec1));
    printf("rec2 is square : %d\n", rectangleIsSquare(rec2));
    printf("c center is on l1 : %d\n", circleCenterIsOnLine(c, l1));
    printf("c center is on l2 : %d\n", circleCenterIsOnLine(c, l2));
//    printf("a = %f, b = %f, c = %f", l1.a, l1.b, l1.c);
}