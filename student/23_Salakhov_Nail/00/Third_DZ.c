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

int point_and_line(struct line one, struct point two) {
    struct point a = one.l1;
    struct point b = one.l2;
    struct point c = two;
    return((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y) == 0);
}
int circle_and_line( struct line l, struct circle r){
    return(point_and_line(l, r.c));

}

int two_lines(struct line one, struct line two) {
     struct point a = one.l1;
     struct point c = one.l2;
     struct point b = two.l1;
     struct point d = two.l2;
     return((b.x - d.x)*(c.y - a.y) == (b.y - d.y)*(c.x - a.x));
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

int Rectangle_square(struct rectangle rec) {
    return ((rec.p1.x - rec.p2.x) == (rec.p1.y - rec.p2.y));
}

void main() {
    struct point L1;
    L1.x=0;
    L1.y=4;
    struct point L2;
    L2.x=4;
    L2.y=16;
    struct point L3;
    L3.x=-4;
    L3.y=0;
    struct point L4;
    L4.x=0;
    L4.y=12;
    struct line line1;
    line1.l1= L1;
    line1.l2=L2;
    struct line line2;
    line2.l1=L3;
    line2.l2=L4;
    printf("%d", two_lines(line1, line2));
}







