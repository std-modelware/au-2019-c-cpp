#include <stdio.h>

struct point {
    float x;
    float y;
};
struct ray {
    struct point r;
    float tga;
};

struct line {
    struct point l1;
    struct point l2;
};

struct triangle {
    struct point t1;
    struct point t2;
    struct point t3;
};

struct rectangle {
    struct point p1;
    struct point p2;
};

struct circle {
    float radius;
    struct point c;
};
float max(float a, float b) {
    float m;
    (a > b) ? (m = a) : (m = b);
    return m;
}
int point_ray_compare(struct point one, struct point two){
    return ((one.x == two.x) & (one.y == two.y));
}

int line_and_point(struct line one, struct point two) {
    struct point a = one.l1;
    struct point b = one.l2;
    struct point c = two;
    return(((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y)) == 0);
}
int circle_and_line(struct line l, struct circle r){
    return(line_and_point(l, r.c));
}

int two_lines(struct line one, struct line two) {
     struct point a = one.l1;
     struct point c = one.l2;
     struct point b = two.l1;
     struct point d = two.l2;
     return((b.y - a.y)*(d.x - c.x) != (d.y - c.y)*(b.x - a.x));
}

int triangle_90(struct triangle tri) {
    float y2 = tri.t2.y - tri.t1.y;
    y2 = y2 * y2;
    float y3 = tri.t3.y - tri.t2.y;
    y3 = y3 * y3;
    float y1 = tri.t3.y - tri.t1.y;
    y1 = y1 * y1;
    float x2 = tri.t2.x - tri.t1.x;
    x2 = x2 * x2;
    float x3 = tri.t3.x - tri.t2.x;
    x3 = x3 * x3;
    float x1 = tri.t3.x - tri.t1.x;
    x1 = x1 * x1;
    float a = y1 + x1;
    float b = y2 + x2;
    float c = y3 + x3;
    float sum = a + b + c;
    float m = max(a, max(b, c));
    return(m == sum - m);
}

int rectangle_square(struct rectangle rec) {
    return ((rec.p1.x - rec.p2.x) == (rec.p1.y - rec.p2.y));
}

void main() {
    struct point p1 = {2, 2};
    struct point p2 = {2, 3};
    struct point p3 = {2, 2};
    printf(" points: (%.2f; %.2f) == (%.2f; %.2f) is %d\n", p1.x, p1.y, p2.x, p2.y, point_ray_compare(p1, p2));
    printf(" points: (%.2f; %.2f) == (%.2f; %.2f) is %d\n", p1.x, p1.y, p3.x, p3.y, point_ray_compare(p1, p3));
    struct ray r1 = {{1, 8},1};
    struct ray r2 = {{1, 8},3};
    struct ray r3 = {{1, 10},2.4};
    printf("rays: (%.2f; %.2f) == (%.2f; %.2f) is %d\n", r1.r.x, r1.r.y, r2.r.x, r2.r.y, point_ray_compare(r1.r, r2.r));
    printf("rays: (%.2f; %.2f) == (%.2f; %.2f) is %d\n", r1.r.x, r1.r.y, r3.r.x, r3.r.y, point_ray_compare(r1.r, r3.r));
    struct line line1 = {{10,0}, {1,1}};
    printf(" line and point: (%.2f; %.2f);(%.2f; %.2f) and (%.2f; %.2f) is %d\n", line1.l1.x, line1.l1.y, line1.l2.x,line1.l2.y, p1.x, p1.y, line_and_point(line1, p1));
    printf(" line and point: (%.2f; %.2f);(%.2f; %.2f) and (%.2f; %.2f) is %d\n", line1.l1.x, line1.l1.y, line1.l2.x,line1.l2.y, p2.x, p2.y, line_and_point(line1, p2));
    struct line line2 = {{1,1}, {2,2}};
    struct line line3 = {{1,2}, {2,3}};
    printf(" line and line: (%.2f; %.2f);(%.2f; %.2f) and (%.2f; %.2f);(%.2f; %.2f) is %d\n", line1.l1.x, line1.l1.y, line1.l2.x,line1.l2.y, line2.l1.x, line2.l1.y, line2.l2.x,line2.l2.y, two_lines(line1, line2));
    printf(" line and line: (%.2f; %.2f);(%.2f; %.2f) and (%.2f; %.2f);(%.2f; %.2f) is %d\n", line1.l2.x, line1.l2.y, line1.l2.x,line1.l2.y, line3.l1.x, line3.l1.y, line3.l2.x,line3.l2.y, two_lines(line2, line3));
    struct triangle t1 = {{1,1}, {1,3},{2,3}};
    struct triangle t2 = {{1,1}, {1,3},{2,2.5}};
    printf("rectangular triangle is %d\n", triangle_90(t1));
    printf("triangle isn't rectangular is %d\n", triangle_90(t2));
    struct rectangle is_square = {{1,1},{2,2}};
    struct rectangle not_square = {{1,1},{2,3}};
    printf("square rectangle is %d\n", rectangle_square(is_square));
    printf("square rectangle is %d\n", rectangle_square(not_square));
    struct circle cir = {{5}, {2,2}};
    printf("line passes center of circle is %d\n", circle_and_line(line2, cir));
    printf("line not passes center of circle is %d", circle_and_line(line1, cir));
}





