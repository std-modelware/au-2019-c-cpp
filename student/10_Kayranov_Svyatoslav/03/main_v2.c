#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct point {
	int x;
	int y;
} point1, point2;

struct ray {
	struct point pt1;
	struct point pt2;
} ray1, ray2;

struct line {
	struct point pt1;
	struct point pt2;
} line1, line2;

struct triangle {
	struct point pt1;
	struct point pt2;
    struct point pt3;
} triangle1, triangle2;

struct rect {
	struct point pt1;
	struct point pt2;
	struct point pt3;
	struct point pt4;
} rect1, rect2;

struct circle {
	struct point pt1;
	int r;
} circle1, circle2;

bool equalPoints(struct point p1, struct point p2){
    return (p1.x == p2.x && p1.x == p2.x); //проверяем совпадение координат точек
}

bool rayFromOnePoint(struct ray r1, struct ray r2){
    return (r1.pt1.x == r2.pt1.x && r1.pt1.y == r2.pt1.y);  //проверяем совпадение координат точек начала лучей  
}

bool pointOnLine(struct point point, struct line line) {
    if (point.y == (point.x - line.pt1.x) * (line.pt2.y - line.pt1.y) / //я просто взял формулу отсюда https://math.semestr.ru/line/equation.php
    (line.pt2.x - line.pt1.x) + line.pt1.y)
        return(1); 
    else return(0);
}

bool parallelLines(struct line l1, struct line l2) { //берем две координаты первой линии, вычитаем из одного другое, делаем то же самое со второй, сравниваем
    if ((abs(abs(l1.pt1.x) - abs(l1.pt2.x)) == abs(abs(l2.pt1.x) - abs(l2.pt2.x))) && //если получилась одинаковая итоговая координата значит линии прямые
    (abs(abs(l1.pt1.y) - abs(l1.pt2.y)) == abs(abs(l2.pt1.y) - abs(l2.pt2.y)))) //и никогда не пересекутся
        return(0);
    else return(1);
}

bool rightTriangle(struct triangle trgl) { //проверям что координаты точек лежащих на одной линии совпадают.
    if (((trgl.pt1.x == trgl.pt2.x) && (trgl.pt2.y == trgl.pt3.y)) || 
        ((trgl.pt2.x == trgl.pt3.x) && (trgl.pt3.y == trgl.pt1.y)) || 
        ((trgl.pt3.x == trgl.pt1.x) && (trgl.pt1.y == trgl.pt2.y)))
        return(1);
    else return (0);    
}

bool rectIsSquare(struct rect rect) { //то же самое что и с прямоугольным треугольником, только кода больше
    if (((rect.pt1.y == rect.pt2.y) && (rect.pt2.x == rect.pt3.x) && (rect.pt3.x == rect.pt4.x) && (rect.pt4.x == rect.pt1.x)) ||
    ((rect.pt2.y == rect.pt3.y) && (rect.pt3.x == rect.pt4.x) && (rect.pt4.x == rect.pt1.x) && (rect.pt1.x == rect.pt2.x)) || 
    ((rect.pt3.y == rect.pt4.y) && (rect.pt4.x == rect.pt1.x) && (rect.pt1.x == rect.pt2.x) && (rect.pt2.x == rect.pt3.x)) ||
    ((rect.pt4.y == rect.pt1.y) && (rect.pt1.x == rect.pt2.x) && (rect.pt2.x == rect.pt3.x) && (rect.pt3.x == rect.pt4.x)))
        return(1);
    else return(0);
}

bool centerLine(struct circle crcl, struct line line) { //ctrl+c, ctrl+v из pointOnLine
    if (crcl.pt1.y == (crcl.pt1.x - line.pt1.x) * (line.pt2.y - line.pt1.y) / 
    (line.pt2.x - line.pt1.x) + line.pt1.y)
        return(1); 
    else return(0);
}

int main() {
    int gay;
    int a1, a2, a3, a4, a5, a6, a7, a8;
    printf("Введите необходимую операцию \n");
    printf("1 - equalPoints\n");
    printf("2 - rayFromOnePoint\n");
    printf("3 - pointOnLine\n");
    printf("4 - parallelLines\n");
    printf("5 - rightTriangle\n");
    printf("6 - rectIsSquare\n");
    printf("7 - centerLine\n");
    scanf("%d", &gay);
    switch(gay) {
        case 1:
            printf("Введите две точки в виде x1 y1 x2 y2\n");
            scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
            struct point obj1 = {a1, a2};
            struct point obj2 = {a3, a4};
            printf("%d", equalPoints(obj1, obj2));
        break;

        case 2:
            printf("Введите две координы двух лучей в виде\n r1x1, r1y1 r1x2 r1y2 r2x1, r2y1 r2x2 r2y2\n");
            scanf("%d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
            struct ray obj3 = {a1, a2, a3, a4};
            struct ray obj4 = {a5, a6, a7, a8};
            printf("%d", rayFromOnePoint(obj3, obj4));
        break;

        case 3:
            printf("Введите введите точку и координаты прямой в виде pX pY lX1 lY1 lX2 lY2\n");
            scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
            struct line obj5 = {a1, a2, a3, a4};
            struct point obj6 = {a5, a6};
            printf("%d", pointOnLine(obj6, obj5));
        break;

        case 4:
            printf("Введите две координаты двух прямых в виде/n l1X1 l1Y1 l1X2 l1Y2 l2X1 l2Y1 l2X2 l2Y2");
            scanf("%d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
            struct line obj7 = {a1, a2, a3, a4};
            struct line obj8 = {a5, a6, a7, a8};
            printf("%d", parallelLines(obj7, obj8));
        break;

        case 5:
            printf("Введите координаты трех вершин треугольника в виде\n x1 y1 x2 y2 x3 y3\n");
            scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
            struct triangle obj9 = {a1, a2, a3, a4, a5, a6};
            printf("%d", rightTriangle(obj9));
        break;

        case 6:
            printf("Введите координаты вершин четырехугольника в виде\n x1 y1 x2 y2 x3 y3 x4 y4\n");
            scanf("%d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
            struct rect obj10 = {a1, a2, a3, a4, a5, a6, a7, a8};
            printf("%d", rectIsSquare(obj10));
        break;

        case 7:
            printf("Введите координаты центра и длинну радиуса в виде\n x y R, а затем координаты прямой в виде x1 y1 x2 y2\n");
            scanf("%d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7);
            struct circle obj11 = {a1, a2, a3};
            struct line obj12 = {a4, a5, a6, a7};
            printf("%d", centerLine(obj11, obj12));
        break;
    }
    return(0);
}