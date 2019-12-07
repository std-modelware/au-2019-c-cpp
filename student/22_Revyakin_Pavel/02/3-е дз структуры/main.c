         #include <stdio.h>
#include <math.h>
struct point{
    float x,y;
};
struct line{
    struct point fir;
    struct point sec;
};
struct openline{
    struct point begin;
    float cos;
};
int sovpadenie_tochek(struct point one,struct point two)
{
    return ((one.x==two.x)&&(one.y==two.y));
}
int sovpadenie_tochek_luchey(struct openline frst,struct openline scnd){
    return sovpadenie_tochek(frst.begin, scnd.begin);
}
int peresechenie_liniu(struct line q, struct line z) {
    struct point pr;
    pr.x=(q.sec.y-q.fir.y)/(q.sec.x-q.fir.x); //угловой Коэфицент прямой
    pr.y=(q.sec.x*q.fir.y-q.fir.x*q.sec.y)/(q.sec.x-q.fir.x); //смещение прямой
    struct point pr2;
    pr2.x=(z.sec.y-z.fir.y)/(z.sec.x-z.fir.x); //угловой Коэфицент прямой
    pr2.y=(z.sec.x*z.fir.y-z.fir.x*z.sec.y)/(z.sec.x-z.fir.x); //смещение прямой

    return !((pr.x==pr2.x)&&(pr.y!=pr2.y));
}
struct treyg {
    struct point first;
    struct point second;
    struct point third;
};
struct pramoygolnik {
    struct point first;
    struct point second;
    struct point third;
    struct point fourth;
};

float dlina(struct point first, struct point second) {
    return (sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y), 2)));
}


int pointonline(struct line line, struct point po) {
    struct treyg plo;
    plo.first = line.fir;
    plo.second = line.sec;
    plo.third = po;
    if((plo.second.x - plo.first.x)*(plo.third.y - plo.first.y) - (plo.third.x - plo.first.x)*(plo.second.y - plo.first.y)!=0){
        return 0;
    }
    else{
        return 1;
    }
}

float maxzn(float a, float b) {
    return (a > b) ? a : b;
}
float minzn(float a, float b) {
    return (a < b) ? a : b;
}
float maxzn3(float a,float b,float c)
{
    return maxzn(maxzn(a,b),c);
}
float minzn3(float a,float b,float c){
    return minzn(minzn(a,b),c);
}

float srednee3(float a,float b,float c){
    float first=maxzn3(a,b,c);
    float second=minzn3(a,b,c);
    if((a!=first)&&(a!=second)){return a;}
    if((b!=first)&&(b!=second)){return b;}
    if((c!=first)&&(c!=second)){return c;}
}

int pramougtreug(struct treyg pr) {
    struct line first;
    first.fir=pr.first;
    first.sec=pr.second;
    struct line second;
    second.fir=pr.second;
    second.sec=pr.third;
    struct line third;
    third.fir=pr.third;
    third.sec=pr.first;
    float a=dlina(first.fir,first.sec);
    float b=dlina(second.fir,second.sec);
    float c=dlina(third.fir,third.sec);
    float maxdl=maxzn3(a,b,c);
    float sreddl=srednee3(a,b,c);
    float mindl=minzn3(a,b,c);
    return (pow(maxdl,2)==(pow(mindl,2)+pow(sreddl,2)));
}
int pramoug_kvadr(struct pramoygolnik vhod){
    struct line first;
    first.fir=vhod.first;
    first.sec=vhod.second;
    struct line second;
    second.fir=vhod.second;
    second.sec=vhod.third;
    float a=dlina(first.fir,first.sec);
    float b=dlina(second.fir,second.sec);
    return (pow(a,2)==(a*b));

}
struct kkk {
    struct point center;
    float radius;
};

int p(struct kkk circle, struct line pry) {
    return (pointonline(pry, circle.center));
}
int main() {

    printf("Тестирование : \n \n");

    struct point a;
    struct point b;
    struct point c;
    struct point d;
    struct point e;
    struct point f;
    f.x=7;
    f.y=3;

    a.x = 7;
    a.y = 3;

    b.x = 5;
    b.y = 2;

    c.x = 7;
    c.y = 4;

    d.x = 9;
    d.y = 2;

    e.x = 11;
    e.y = 4;
    struct point de;
    de.x=1;
    de.y=1;
    struct point ded;
    ded.x=5;
    ded.y=2;
    printf("совпадают ли точки(не должны): %d \n", sovpadenie_tochek(a, b));
    printf("совпадают ли точки (должны): %d \n \n", sovpadenie_tochek(a, f));

    struct openline luch1;
    struct openline luch2;
    struct openline luch3;
    luch1.begin = a; luch1.cos = 0;
    luch2.begin = a; luch2.cos = 0;
    luch3.begin = c; luch3.cos = 0;

    printf("Cовпадение начала лучей(да) : %d \n", sovpadenie_tochek_luchey(luch1,luch2));
    printf("Совпадние точек начала лучей(нет): %d \n \n", sovpadenie_tochek_luchey(luch2,luch3));
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct line testline;
    testline.fir = b;
    testline.sec = e;
    printf("Лежит ли точка на прямой?(не лежит): %d \n", pointonline(testline, de));
    printf("Лежит ли точка на прямой (лежит): %d \n \n", pointonline(testline, ded));
    struct point b2;
    b2.x=6;
    b2.y=2;
    struct point e2;
    e2.x=12;
    e2.y=4;
    struct line testlineaway;
    testlineaway.fir = b2;
    testlineaway.sec = e2;

    struct point h;
    h.x = 5;
    h.y = 6;

    struct line testline2;
    testline2.fir = d;
    testline2.sec = h;

    struct line testline3;
    testline3.fir = b;
    testline3.sec = h;

    printf("Линии пересекаюся(да): %d \n", peresechenie_liniu(testline2,testline3));
    printf("Линии пересекаются?(нет): %d \n \n", peresechenie_liniu(testline, testlineaway));

    struct point recp1;
    recp1.x = 1; recp1.y = 2;
    struct point recp2;
    recp2.x = 4; recp2.y = 1;
    struct point recp3;
    recp3.x = 4; recp3.y = 5;
    struct point recp4;
    recp4.x = 1; recp4.y = 1;
    struct point recp5;
    recp5.x = 4; recp5.y = 1;
    struct point recp6;
    recp6.x = 4; recp6.y = 5;


    struct treyg tri1;
    tri1.first = recp4;
    tri1.second = recp5;
    tri1.third = recp6;
    struct treyg tri2;
    tri2.first = recp1;
    tri2.second = recp2;
    tri2.third = recp3;

    printf("Прямоуголен ли треугольник?(да): %d \n", pramougtreug(tri1));
    printf("прямоуголен ли треугольник?(нет): %d \n \n", pramougtreug(tri2));
    struct point recp7;
    recp7.x = 1; recp7.y = 1;
    struct point recp8;
    recp8.x = 4; recp8.y = 1;
    struct point recp9;
    recp9.x = 4; recp9.y = 3;
    struct point recp10;
    recp10.x=1;
    recp10.y=3;
    struct pramoygolnik pr;
    pr.first=recp7;
    pr.second=recp8;
    pr.third=recp9;
    pr.fourth=recp10;
    struct point recp11;
    recp11.x = 1; recp11.y = 1;
    struct point recp12;
    recp12.x = 4; recp12.y = 1;
    struct point recp13;
    recp13.x = 4; recp13.y = 4;
    struct point recp14;
    recp14.x=1;
    recp14.y=4;
    struct pramoygolnik pr2;
    pr2.first=recp11;
    pr2.second=recp12;
    pr2.third=recp13;
    pr2.fourth=recp14;
    printf("Квадрат ли прямоугольник?(да): %d \n", pramoug_kvadr(pr2));
    printf("Квадрат ли прямоугольник(нет): %d \n \n", pramoug_kvadr(pr));

    struct kkk cir;
    cir.center = e;
    cir.radius = 2;

    struct point recp15;
    recp15.x=100;
    recp15.y=100;
    struct kkk cir2;
    cir2.center = recp15;
    cir2.radius = 2;

    printf("пересечение центра окружности и линии  (Да): %d \n", p(cir, testline));
    printf(" пересечение центра окружности и линии(Нет): %d \n \n", p(cir2, testline));
}