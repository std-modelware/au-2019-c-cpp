#include <stdio.h>
#include <math.h>

struct point {
    int x, y;
}p;

struct ray {
    int x1, y1;
    int x2, y2;
};

struct line {
    int x1, y1;
    int x2, y2;
};

struct triangle {
    struct point first;
    struct point second;
    struct point third;
};

struct rectangle {
    struct point first;
    struct point second;
};

struct circle {
    int x, y, r;
};

int equal_points(struct point p1, struct point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int equal_start(struct ray r1, struct ray r2) {
    return r1.x1 == r2.x1 && r1.y1 == r2.y1;
}

int on_line(struct line l, struct point p) {
    if ((l.y1 - l.y2) * p.x + (l.x2 - l.x1) * p.y + (l.x1 * l.y2 - l.x2 * l.y1) == 0)//уравнение прямой через координаты
        return 1;
    else
        return 0;
}

int intersect(struct line l1, struct line l2) {
    if ((l1.y2-l1.y1)/(l1.x2-l1.x1) != (l2.y2-l2.y1)/(l2.x2-l2.x1))
        return 1;
    else
        return 0;
}

int right_triangle(struct triangle t) {
    int side1;
    int side2;
    int side3;
    int hyp = 0;
    int leg1;
    int leg2;
    side1 = sqrt((t.second.x - t.first.x) * (t.second.x - t.first.x) + (t.second.y - t.first.y) * (t.second.y - t.first.y));
    side2 = sqrt((t.third.x - t.second.x) * (t.third.x - t.second.x) + (t.third.y - t.second.y) * (t.third.y - t.second.y));
    side3 = sqrt((t.first.x - t.third.x) * (t.first.x - t.third.x) + (t.first.y - t.third.y) * (t.first.y - t.third.y));
    if (side1 > side2) {
        if (side1 > side3) {
            hyp = side1;
            leg1 = side2;
            leg2 = side3;
        } else {
            hyp = side3;
            leg1 = side1;
            leg2 = side2;
        }
    }
    else{
        if (side2 > side3){
            hyp = side2;
            leg1 = side1;
            leg2 = side3;
        }
        else{
            hyp = side3;
            leg1 = side1;
            leg2 = side2;
        }

    }
    if (hyp * hyp == leg1 * leg1 + leg2 * leg2)
        return 1;
    else
        return 0;
}

int IsRectangleSquare(struct rectangle rec) {
    return (abs(rec.first.x - rec.second.x) == abs(rec.first.y - rec.second.y));
}

int through_the_center(struct circle c, struct line l) {
    if ((l.y1 - l.y2) * c.x + (l.x2 - l.x1) * c.y + (l.x1 * l.y2 - l.x2 * l.y1) == 0)
        return 1;
    else
        return 0;
}

int main() {
    struct line a;
    a.x1 = 0;
    a.y1 = 0;
    a.x2 = 1;
    a.y2 = 1;

    struct line b;
    b.x1 = 0;
    b.y1 = 0;
    b.x2 = 2;
    b.y2 = 1;
    int c;
    c = intersect(a, b);
    printf("%d", c);
}