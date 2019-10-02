#include <math.h>

struct point {
    long int x;
    long int y;
};

struct ray {
    long int xs;
    long int ys;
    long int xe;
    long int ye;
};

struct line {
    long int xs;
    long int ys;
    long int xe;
    long int ye;
};

struct triangle {
    long int x1;
    long int y1;
    long int x2;
    long int y2;
    long int x3;
    long int y3;
};

struct rectangle {
    long int x1;
    long int y1;
    long int x2;
    long int y2;
    long int x3;
    long int y3;
    long int x4;
    long int y4;
};

struct circle {
    long int x;
    long int y;
    long int r;
};

int equal_points(struct point p1, struct point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int equal_ray_start(struct ray r1, struct ray r2) {
    return r1.xs == r2.xs && r1.ys == r2.ys;
}

int point_on_line(struct line l, struct point p) {
    if ((l.ys - l.ye) * p.x + (l.xe - l.xs) * p.y + (l.xs * l.ye - l.xe * l.ys) == 0)
        return 1;
    else
        return 0;
}

int lines_intersection(struct line l1, struct line l2) {
    if ((l1.ye-l1.ys)/(l1.xe-l1.xs) == (l2.ye-l2.ys)/(l2.xe-l2.xs))
        return 1;
    else
        return 0;
}

int right_triangle(struct triangle t) {
    long int side1;
    long int side2;
    long int side3;
    long int hypotenuse = -1;
    long int third_side1;
    long int third_side2;
    side1 = sqrt((t.x2 - t.x1) * (t.x2 - t.x1) + (t.y2 - t.y1) * (t.y2 - t.y1));
    side2 = sqrt((t.x3 - t.x2) * (t.x3 - t.x2) + (t.y3 - t.y2) * (t.y3 - t.y2));
    side3 = sqrt((t.x1 - t.x3) * (t.x1 - t.x3) + (t.y1 - t.y3) * (t.y1 - t.y3));
    if (side1 > hypotenuse) {
        hypotenuse = side1;
        third_side1 = side2;
        third_side2 = side3;
    }
    if (side2 > hypotenuse) {
        hypotenuse = side2;
        third_side1 = side1;
        third_side2 = side3;
    }
    if (side3 > hypotenuse) {
        hypotenuse = side3;
        third_side1 = side1;
        third_side2 = side2;
    }
    if (hypotenuse*hypotenuse == third_side1*third_side1 + third_side2*third_side2)
        return 1;
    else
        return 0;
}

int square(struct rectangle r) {
    long int side1;
    long int side2;
    long int side3;
    long int side4;
    side1 = sqrt((r.x2 - r.x1) * (r.x2 - r.x1) + (r.y2 - r.y1) * (r.y2 - r.y1));
    side2 = sqrt((r.x3 - r.x2) * (r.x3 - r.x2) + (r.y3 - r.y2) * (r.y3 - r.y2));
    side3 = sqrt((r.x4 - r.x3) * (r.x4 - r.x3) + (r.y4 - r.y3) * (r.y4 - r.y3));
    side4 = sqrt((r.x1 - r.x4) * (r.x1 - r.x4) + (r.y1 - r.y4) * (r.y1 - r.y4));
    if (side1 == side2 == side3 == side4)
        return 1;
    else
        return 0;
}

int straight_center_circle(struct circle c, struct line l) {
    if ((l.ys - l.ye) * c.x + (l.xe - l.xs) * c.y + (l.xs * l.ye - l.xe * l.ys) == 0)
        return 1;
    else
        return 0;
}

int main() {}
