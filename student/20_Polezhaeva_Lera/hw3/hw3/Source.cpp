#include <stdio.h>
#include <math.h>

	struct point {
		// 2 координаты на плоскости
		int x;
		int y;
	} p1,p2,p3;

	struct half_line {
		//координаты двух точек, первая точка начало
		point a1;
		point a2;
	}hl1,hl2;

	struct line {
		//y = kx + b
		int k;
		int b;
	}l1,l2,l3,l4;
	struct triangle {
		//координаты трех точек;
		point tr1;
		point tr2;
		point tr3;
	}t1;
	struct rectangle {
		// координаты 3 вершин
		point re1, re2, re3;
	}r1;

	struct circle {
		//координаты центра и значение радиуса
		point ci;
		float R;
	}c1,c2;

	int points(point p1, point p2) {
		if ((p1.x == p2.x) && (p1.y == p2.y)) {
			return 1;
		}
		else return 0;
	};

	int half_lines(half_line hl1, half_line hl2) {
		if ((hl1.a1.x == hl2.a1.x) && (hl1.a1.y == hl2.a1.y)) {
			return 1;
		}
		else return 0;
	};
	
	int lines(line l3, point p3){ 
		if (p3.y == l3.k * p3.y + l3.b) {
			return 1;
		}
		else return 0;
	}

	int lines1(line l1, line l2) {
		if (l1.k != l2.k) {
			return 1;
		}
		else if (l1.b == l2.b) {
			return -1;
		}
		else return 0;
	}
	int right_tri(triangle t1){
		float l1 = pow((t1.tr1.x - t1.tr2.x),2) + pow((t1.tr1.y - t1.tr2.y),2);
		float l2 = pow((t1.tr1.x - t1.tr3.x),2) + pow((t1.tr1.y - t1.tr3.y),2);
		float l3 = pow((t1.tr2.x - t1.tr3.x),2) + pow((t1.tr2.y - t1.tr3.y),2);
		if ((l1 + l2 == l3) || (l1 + l2 == l2) || (l2 + l3 == l1)) {
			return 1;
		}
		else return 0;
	}

	int square(rectangle r1) {
		float a1 = sqrt(pow((r1.re1.x - r1.re2.x), 2) + pow((r1.re1.y - r1.re2.y), 2));
		float a2 = sqrt(pow((r1.re1.x - r1.re3.x), 2) + pow((r1.re1.y - r1.re3.y), 2));
		float a3 = sqrt(pow((r1.re2.x - r1.re3.x), 2) + pow((r1.re2.y - r1.re3.y), 2));
		if (((a1 > a2) && (a2 == a3)) || ((a2 > a1) && (a1 == a3)) || ((a3 > a2) && (a1 = a2))) {
			return 1;
		}
		else return 0;
	}

	int lastf(circle c1, line l4) {
		if (c1.ci.y == l4.k * c1.ci.x + l4.b) {
			return 1;
		}
		else return 0;
	}

	void main() {
		p1.x = 1;
		p1.y = 2;
		p2.x = 1;
		p2.y = 2;
		int answ1 = points(p1, p2);
		printf("if 1 point = 2 point - 1, else 0:");
		printf("%d\n", answ1);

		hl1.a1.x = 1;
		hl1.a1.y = 2;
		hl2.a1.x = 1;
		hl2.a1.y = 2;

		int answ2 = half_lines(hl1, hl2);
		printf("half-lines with same beginnings, 1 if yes, 0 if no:");
		printf("%d\n", answ2);

		l3.k = 1;
		l3.b = 0;
		p3.x = 1;
		p3.y = 1;

		int answ3 = lines(l3, p3);
		printf("poin and line, 1 if point belongs, else - 0:");
		printf("%d\n", answ3);

		l1.k = 1;
		l1.b = 0;
		l2.k = -1;
		l2.b = 0;

		int answ4 = lines1(l1, l2);
		printf("lines intersect. 1 if yes, 0 if no, -1 if considence:");
		printf("%d\n", answ4);

		t1.tr1.x = 1;
		t1.tr1.y = -1;
		t1.tr2.x = 0;
		t1.tr2.y = 0;
		t1.tr3.x = 0;
		t1.tr3.y = 1;

		int answ5 = right_tri(t1);
		printf("right triangle:");
		printf("%d\n", answ5);

		r1.re1.x = 0;
		r1.re1.y = 0;
		r1.re2.x = 1;
		r1.re2.y = 0;
		r1.re3.x = 0;
		r1.re3.y = 1;

		int answ6 = square(r1);
		printf("sq : %d\n", answ6);

		c1.ci.x = 0;
		c1.ci.y = 0;
		l4.k = 1;
		l4.b = 0;
		int answ7 = lastf(c1, l4);
		printf("circle and line : %d\n", answ7);

	}