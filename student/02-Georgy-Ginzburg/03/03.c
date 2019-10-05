//
// Created by georgyginzburg on 03.10.2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//#define DEBUG
typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p_start, p;
} Ray;

typedef struct { // y = kx + b
    double k;
    double b;
} Line;

typedef struct {
    Point p1, p2, p3;
} Triangle;

typedef struct {
    Point p1, p2;
    /*
        p1---p
        |   |
        p---p2
                */
} Rectangle;

typedef struct {
    Point p_center;
    double radius;
} Circle;

bool are_points_equal(Point p1, Point p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}

bool are_rays_starting_from_same_point(Ray r1, Ray r2) {
    return are_points_equal(r1.p_start, r2.p_start);
}

bool is_point_on_line(Point p, Line l) {
    return p.y == l.k * p.x + l.b;
}

bool do_lines_intersect(Line l1, Line l2) {
    if (l1.b != l2.b) {
        return (l1.k != l2.k);
    }
    return 1;
}

bool is_triangle_right(Triangle t) {
    double sqr_side_1 = pow(t.p1.x - t.p2.x, 2) +
                        pow(t.p1.y - t.p2.y, 2); // side_1 squared
    double sqr_side_2 = pow(t.p2.x - t.p3.x, 2) +
                        pow(t.p2.y - t.p3.y, 2);
    double sqr_side_3 = pow(t.p1.x - t.p3.x, 2) +
                        pow(t.p1.y - t.p3.y, 2);
    double sqr_hypotenuse = fmax(sqr_side_1, fmax(sqr_side_2, sqr_side_3));

#ifdef DEBUG
    printf("%f %f %f\n", sqr_side_1, sqr_side_2, sqr_side_3);
#endif

    if (sqr_hypotenuse == sqr_side_1)
        return sqr_side_1 == sqr_side_2 + sqr_side_3;
    else if (sqr_hypotenuse == sqr_side_2)
        return sqr_side_2 == sqr_side_1 + sqr_side_3;
    else if (sqr_hypotenuse == sqr_side_3)
        return sqr_side_3 == sqr_side_1 + sqr_side_2;
}

bool is_rect_sqr(Rectangle r) {
    return fabs(r.p1.y - r.p2.y) == fabs(r.p1.x - r.p2.x);
}

bool does_line_intersect_circle_center(Line l, Circle c) {
    return is_point_on_line(c.p_center, l);
}

int main() {
    Point p1 = {1, 0.5};
    Point p2 = {1, 8};
    Point p3 = {1, 8};

    Ray r1 = {{1, 8},
              {2, 4}};
    Ray r2 = {{1,   8},
              {0.3, -0.2}};
    Ray r3 = {{23,    9},
              {0.494, 39321}};

    Line l1 = {3, 5};
    Line l2 = {3, 6};
    Line l3 = {4,
               103};

    Triangle tr_r = {{0, 0},
                     {3, 0},
                     {0, 5}};
    Triangle tr_notr = {{0, 0},
                        {3, 1},
                        {0, 5}};
    Rectangle rect_sq = {{1, 2},
                         {2, 1}};
    Rectangle rect_nonsq = {{1, 3},
                            {1, 5}};
    Circle c = {{0, 5}, 3};

    printf("Equal points: %d ", are_points_equal(p1, p3));
    printf("%d\n", are_points_equal(p3, p2));
    printf("Rays from one starting point: %d ", are_rays_starting_from_same_point(r1, r2));
    printf("%d\n", are_rays_starting_from_same_point(r3, r2));
    printf("Is point on line: %d ", is_point_on_line(p2, l1));
    printf("%d\n", is_point_on_line(p2, l2));
    printf("Do lines intersect: %d ", do_lines_intersect(l1, l2));
    printf("%d\n", do_lines_intersect(l1, l3));
    printf("Is triangle right: %d ", is_triangle_right(tr_r));
    printf("%d\n", is_triangle_right(tr_notr));
    printf("Is rectangle a square: %d ", is_rect_sqr(rect_sq));
    printf("%d\n", is_rect_sqr(rect_nonsq));
    printf("Does a line intersect circle center: %d ", does_line_intersect_circle_center(l1, c));
    printf("%d\n", does_line_intersect_circle_center(l2, c));
    return 0;
}
