#include <stdio.h>
#include <math.h>

enum BOOLEAN {
	B_FALSE,
	B_TRUE
};

struct point {
	long int x, y;
};

struct ray {
	struct point points;
	struct point pointe;
};

struct line {
	struct point point1;
	struct point point2;


};

struct triangle {
	struct point point1;
	struct point point2;
	struct point point3;

};

struct rectangle {
	struct point point1;
	struct point point2;
	struct point point3;
	struct point point4;
};

struct circle{
	struct point pointo;
	long int r;
};
int equalpoints(struct point point1, struct point point2) {
	if ((point1.x == point2.x) && (point1.y == point2.y)) return B_TRUE;
	return B_FALSE;
}

int rays_from_same_point(struct ray ray1, struct ray ray2) {
	if (equalpoints(ray1.points, ray2.points)) return B_TRUE;
	return B_FALSE;
}


int point_belong_line(struct point point, struct line line) {
	if ((point.x - line.point1.x)*(line.point2.y - line.point1.y)/(line.point2.x - line.point1.x) + line.point1.y == point.y) return B_TRUE;
	return B_FALSE;
}

int lines_crossed(struct line line1, struct line line2) {
	if ((abs(line1.point1.x - line1.point2.x) / abs(line2.point1.x - line2.point2.x)) == (abs(line1.point1.y - line1.point2.y) / abs(line2.point1.y - line2.point2.y))) return B_FALSE;
	return B_TRUE;
}

int square_len(struct point point1, struct point point2) {
	return pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2);
}

int right_triangle(struct triangle tr) {
	int a = square_len(tr.point1, tr.point2);
	int b = square_len(tr.point2, tr.point3);	
	int c = square_len(tr.point1, tr.point3);

	if (a > c) {
		a += c;
		c = a - c;
		a -= c;
	}
	if (b > c) {
		b += c;
		c = b - c;
		b -= c;
	}
	if (a + b == c) {
		return B_TRUE;
	}
	return B_FALSE;
}


 int check_rectangle(struct rectangle r1) {
	if ((square_len(r1.point1, r1.point3)) == (square_len(r1.point2, r1.point4))) {
		if ((square_len(r1.point2, r1.point3)) == (square_len(r1.point1, r1.point4))) {
			if ((square_len(r1.point1, r1.point2)) == (square_len(r1.point3, r1.point4))) {
				return B_TRUE;
			}

		}
	}
	return B_FALSE;
}
 
int square(struct rectangle rect) {
	if (check_rectangle(rect)) {
		if ((square_len(rect.point1, rect.point2)) == (square_len(rect.point2, rect.point3))) {
			return B_TRUE;
		}
	}
	return B_FALSE;
}

int line_mid_circle(struct circle circle, struct line line) {
	if (point_belong_line(circle.pointo, line)) return B_TRUE;
	return B_FALSE;
}

void main() {

	// (1)
	struct point point_A;
	point_A.x = 3; point_A.y = 5;

	struct point point_B;
	point_B.x = 3; point_B.y = 5;

	int ans1 = equalpoints(point_A, point_B);
	printf("1) %d\n", ans1);

	//------------------------------------

	//(2)
	struct ray ray_A;
	ray_A.points.x = 3; ray_A.points.y = 3;
	ray_A.pointe.x = 6; ray_A.pointe.y = 7;

	struct ray ray_B;
	ray_B.points.x = 3; ray_B.points.y = 3;
	ray_B.pointe.x = 6; ray_B.pointe.y = 7;

	int ans2 = rays_from_same_point(ray_A, ray_B);
	printf("2) %d\n", ans2);

	//------------------------------------

	//(3)

	struct point point_L;
	point_L.x = 3; point_L.y = 12;

	struct line line_a;
	line_a.point1.x = 1; line_a.point1.y = 4;
	line_a.point2.x = 10; line_a.point2.y = 40;

	int ans3 = point_belong_line(point_L, line_a);
	printf("3) %d\n", ans3);

	//------------------------------------

	//(4)

	struct line line_b;
	line_b.point1.x = 1; line_b.point1.y = 2;
	line_b.point2.x = 2; line_b.point2.y = 4;

	struct line line_c;
	line_c.point1.x = 4; line_c.point1.y = 7;
	line_c.point2.x = 5; line_c.point2.y = 9;

	int ans4 = lines_crossed(line_b, line_c);
	printf("4) %d\n", ans4);

	//------------------------------------

	//(5)
	
	struct triangle t;
	t.point1.x = 0; t.point1.y = 0;
	t.point2.x = 0; t.point2.y = 3;
	t.point3.x = 4; t.point3.y = 0;

	int ans5 = right_triangle(t);
	printf("5) %d\n", ans5);

	//(6)
	
	struct rectangle r;
	r.point1.x = 0; r.point1.y = 0;
	r.point2.x = 4; r.point2.y = 0;
	r.point3.x = 4; r.point3.y = 4;
	r.point4.x = 0; r.point4.y = 4;

	int rect = check_rectangle(r);
	if (rect) {
		int ans6 = square(r);
		printf("6) %d\n", ans6);
	} else {
		printf("6) %d\n", 0);
	}
	
	//(7)

	struct circle o;
	o.pointo.x = 0; o.pointo.y = 0;
	o.r = 7;

	struct line line_r;
	line_r.point1.x = 3; line_r.point1.y = 3;
	line_r.point2.x = -2; line_r.point2.y = -3;

	int ans7 = line_mid_circle(o, line_r);
	printf("7) %d\n", ans7);

}