#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
} poi1, poi2, poi3, poi4, poi5, poi6, poi7, poi8, poi9;

struct line {
	struct point A;
	struct point B;
} lin1, lin2, lin3;

struct ray {
	struct point A;
	float deg;
} ray1, ray2, ray3;

struct trian {
	struct point A;
	struct point B;
	struct point C;
} trian1, trian2, trian3;

struct rectan {
	struct point A;
	struct point B;
	struct point C;
} rectan1, rectan2, rectan3;

struct circ {
	struct point A;
	float R;
} circ1, circ2, circ3;


int eq_point(struct point one, struct point two) {
	if (one.x == two.x && one.y == two.y) {
		printf("1\n");
	}
}

int eq_ray(struct ray one, struct ray two) {
	if (one.A.x == two.A.x && one.A.y == two.A.y) {
		printf("1\n");
	}
}

double TrianAre(struct trian trian) {
	return(((trian.B.x - trian.A.x) * (trian.C.y - trian.A.y) - (trian.C.x - trian.A.x) * (trian.B.y - trian.A.y)) / 2);
}


int obtain(struct line lin, struct point poi) {
	struct trian poiLine;
	poiLine.A = lin.A;
	poiLine.B = lin.B;
	poiLine.C = poi;
	return !(TrianAre(poiLine));
}


int obtain_circ(struct circ circc, struct line lin) {
	return (obtain(lin, circc.A));
}

int same_st(struct ray ra, struct ray ry) {
	return eq_point(ray1.A, ray2.A);
}

int sameli(struct line lin1, struct line lin2) {
	if (abs(lin1.A.x - lin1.B.x) / abs(lin1.A.y - lin1.B.y) == abs(lin2.A.x - lin2.B.x) / abs(lin2.A.y - lin2.B.y)) 
		printf("1\n");

}
double linLen(struct line lin) {
	if (abs(lin.A.x == lin.B.x)) {
		return abs(lin.A.y - lin.B.y);
	}
	
	if (abs(lin.A.y == lin.B.y)) {
		return abs(lin.A.x - lin.B.x);
	}

	else {
		return sqrt(abs(lin.A.x - lin.B.x)* abs(lin.A.x - lin.B.x) + abs(lin.A.y - lin.B.y)*abs(lin.A.y - lin.B.y));
	}
}

int square(struct rectan re) {

	struct line lineo;
	struct line linet;
	struct line lineg;

	lineo.A = re.A;
	lineo.B = re.B;

	linet.A = re.B;
	linet.B = re.C;

	lineg.A = re.A;
	lineg.B = re.C;

	if (linLen(lineo) + linLen(linet) == linLen(lineg)) {

		if (sameli(lineo, linet)) {
			printf("1\n");
		}
	}
}


void main() {

	poi1.x = 2;
	poi1.y = 6;

	poi2.x = 2;
	poi2.y = 6;

	poi3.x = 3;
	poi3.y = 9;

	poi4.x = 4;
	poi4.y = 12;

	poi5.x = 3;
	poi5.y = 6;

	poi6.x = 4;
	poi6.y = 6;

	poi7.x = 1;
	poi7.y = 2;

	poi8.x = 2;
	poi8.y = 1;

	poi9.x = 4;
	poi9.y = 5;

	eq_point(poi1, poi2); //1
	eq_point(poi1, poi3);


	lin1.A = poi1;
	lin1.B = poi3;

	lin2.A.x = 4;
	lin2.A.y = 12;
	lin2.B.x = 6;
	lin2.B.y = 18;

	lin3.A.x = 5;
	lin3.A.y = 10;
	lin3.B.x = 10;
	lin3.B.y = 18;

	obtain(lin1, poi1); //2
	obtain(lin1, poi3);

	sameli(lin1, lin2); //3
	sameli(lin1, lin3);


	ray1.A = poi1;
	ray1.deg = 30;

	ray2.A = poi1;
	ray2.deg = 45;

	ray3.A = poi3;
	ray3.deg = 30;

	same_st(ray1, ray2); //4
	same_st(ray1, ray3);

	circ1.A = poi1;
	circ1.R = 5;

	obtain_circ(circ1, lin1); //5

	rectan1.A = poi1;
	rectan1.B = poi3;
	rectan1.C = poi5;

	rectan2.A = poi1;
	rectan2.B = poi4;
	rectan2.C = poi6;

	rectan3.A = poi7;
	rectan3.B = poi8;
	rectan3.C = poi9;

	square(rectan1); //6
	square(rectan2);



}