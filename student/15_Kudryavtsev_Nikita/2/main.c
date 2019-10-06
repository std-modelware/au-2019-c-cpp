#include <math.h>
#include <stdio.h>

struct point {long int x, y;};
struct ray {long int xs, ys, xe, ye;};
struct line {long int xs, ys, xe, ye;};
struct triangle {double x1, y1, x2, y2, x3, y3;};
struct rectangle {double x1, y1, x2, y2, x3, y3, x4, y4;};
struct circle {long int x, y, r;};

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
    double side1, side2, side3;
    double third_side1, third_side2;
    double hypotenuse = -1;
    double eps = 1E-10;
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
    if (fabs(hypotenuse*hypotenuse - (third_side1*third_side1 + third_side2*third_side2))<eps)
        return 1;
    else
        return 0;
}

int square(struct rectangle r) {
    double side1, side2, side3, side4;
    double eps = 1E-10;
    side1 = sqrt((r.x4 - r.x2) * (r.x4 - r.x2) + (r.y4 - r.y2) * (r.y4 - r.y2));
    side2 = sqrt((r.x4 - r.x3) * (r.x4 - r.x3) + (r.y4 - r.y3) * (r.y4 - r.y3));
    side3 = sqrt((r.x2 - r.x1) * (r.x2 - r.x1) + (r.y2 - r.y1) * (r.y2 - r.y1));
    side4 = sqrt((r.x3 - r.x1) * (r.x3 - r.x1) + (r.y3 - r.y1) * (r.y3 - r.y1));
    int is_equal = fabs(side1-side2)<eps;
    if (fabs(side1-side2)<eps && fabs(side2-side3)<eps && fabs(side3-side4)<eps)
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

int main() {
    struct point p1 = {1, 1};
    struct point p2 = {1, 1};
    struct ray r1 = {1, 1, 10, 10};
    struct ray r2 = {1, 1, 10, 10};
    struct line l1 = {1, 1, 10, 10};
    struct line l2 = {1, 2, 10, 11};
    struct triangle t = {1, 1, 5, 1, 1, 5};
    struct rectangle rec = {1, 1, 5, 1, 1, 5, 5, 5};
    struct circle c = {2, 2, 10};


    printf("equal_points: %d\n", equal_points(p1, p2));
    printf("equal_ray_start: %d\n", equal_ray_start(r1, r2));
    printf("point_on_line: %d\n", point_on_line(l1, p1));
    printf("lines_intersection: %d\n", lines_intersection(l1, l2));
    printf("right_triangle: %d\n", right_triangle(t));
    printf("square: %d\n", square(rec));
    printf("straight_center_circle: %d", straight_center_circle(c, l1));

}
