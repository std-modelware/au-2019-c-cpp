#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int print(a) {
    return printf("%d\n", a);
};

struct point {
	int x;
	int y;
};

struct ray {
	struct point pt1;
	struct point pt2;
};

struct line {
	struct point pt1;
	struct point pt2;
};

struct triangle {
	struct point pt1;
	struct point pt2;
    struct point pt3;
};

struct rect {
	struct point pt1;
	struct point pt2;
	struct point pt3;
	struct point pt4;
};

struct circle {
	struct point pt1;
	int r;
};

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
    printf("I love C language! \n");
//    printf("%b", parallelLines(?????????????); //А КАК ВЫЗЫВАТЬ?
    return(0);
}