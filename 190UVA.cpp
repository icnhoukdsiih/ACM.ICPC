// PREPARING ACM.ICPC 2018
// 190UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
#include <math.h>
typedef struct Point {
    double x,y;
    Point(): x(0), y(0) {};
    Point(double _x,double _y): x(_x), y(_y) {};
} point;
typedef struct Line {
    double a,b,c;
} line;
point A, B, C;
line l1, l2;
//FILE *f =freopen("input.txt","rt",stdin);
void createline(point p1, point p2, line &l) {
    l.a = p2.y - p1.y;
    l.b = p1.x - p2.x;
    if (l.b == 0) l.a =1;
    else {
        l.a /= l.b;
        l.b = 1;
    }
    l.c = -(l.a * p1.x + l.b * p1.y);
}
void intersect(line l1, line l2, point &p) {
    p.x = (l2.c * l1.b - l1.c * l2.b) / (l1.a * l2.b - l2.a * l1.b);
    if (l1.b == 0) p.y = -(l2.c + l2.a * p.x) / l2.b;
    else p.y = -(l1.c + l1.a * p.x) / l1.b;
}
double sqr(double v) {
    return v * v;
}
double distance(point p1, point p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}
int main() {
    while (scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y) == 6) {
        point p1 = point((A.x + B.x) / 2, (A.y + B.y) / 2);
        point p2 = point(p1.x + B.y - A.y, p1.y + A.x - B.x);
        createline(p1, p2, l1);
        p1 = point((A.x + C.x) / 2, (A.y + C.y) / 2);
        p2 = point(p1.x + C.y - A.y, p1.y + A.x - C.x);
        createline(p1, p2, l2);
        point o;
        intersect(l1,l2,o);
        double r = distance(o,A);
        char c1 = '-',c2 = '-',c3 = '+';
        if (o.x < 0) c1 = '+';
        if (o.y < 0) c2 = '+';
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", c1, fabs(o.x), c2, fabs(o.y), r);
        if (o.x * o.x + o.y * o.y - r * r < 0) c3 = '-';
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", c1, fabs(2*o.x), c2, fabs(2*o.y), c3, fabs(o.x * o.x + o.y * o.y - r * r));
    }
    return 0;
}
