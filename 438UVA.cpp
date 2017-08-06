// PREPARING ACM.ICPC 2018
// 438UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
#include <math.h>
typedef struct Point {
    double x,y;
    Point(): x(0), y(0) {};
    Point(double _x, double _y): x(_x), y(_y) {};
} point;
typedef struct Line {
    double a,b,c;
} line;
point A, B, C;
line l1, l2;
//FILE *f =freopen("input.txt","rt",stdin);
//FILE *f1 =freopen("output.txt","wt",stdout);
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
int main() {
    while (scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y) == 6) {
        point p1 = point((A.x + B.x) / 2, (A.y + B.y) / 2);
        point p2 = point(p1.x + B.y - A.y, p1.y + A.x - B.x);
        createline(p1,p2,l1);
        p1 = point((A.x + C.x) / 2, (A.y + C.y) / 2);
        p2 = point(p1.x + C.y - A.y, p1.y + A.x - C.x);
        createline(p1,p2,l2);
        point o;
        intersect(l1,l2,o);
        double r = sqrt(pow(o.x - A.x,2)+pow(o.y - A.y,2));
        printf("%.2lf\n",4*acos(0)*r);
    }
    return 0;
}
