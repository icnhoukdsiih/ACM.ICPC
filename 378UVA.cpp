// PREPARING ACM.ICPC 2018
// 191UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
struct point {
    double x,y;
    point(): x(0), y(0) {}
    point(double _x, double _y): x(_x), y(_y) {}
};
struct line {
    double a,b,c;
    line(): a(0), b(0), c(0) {}
    line(double _a, double _b, double _c): a(_a), b(_b), c(_c){}
};
int n, xc1, yc1, xc2, yc2, xc3, yc3, xc4, yc4;
//FILE *f = freopen("input.txt","rt",stdin);
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1;
        l.b = 0;
        l.c = -p1.x;
    }
    else {
        l.a = (p2.y - p1.y) / (p1.x - p2.x);
        l.b = 1;
        l.c = -(l.a * p1.x + p1.y);
    }
}
bool areParalel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return (areParalel(l1,l2) && fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
    if (areParalel(l1,l2)) return false;
    p.x = (l2.c * l1.b - l1.c * l2.b)/(l1.a * l2.b - l2.a * l1.b);
    p.y = l1.b == 0 ? -l2.c - l2.a * p.x : -l1.c - l1.a * p.x;
}
int main() {
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    line l1, l2;
    point p;
    for (int t = 0; t < n; t++) {
        //Doc 2 diem cua moi duong thang va xay dung duong thang
        scanf("%d%d%d%d%d%d%d%d",&xc1,&yc1,&xc2,&yc2,&xc3,&yc3,&xc4,&yc4);
        pointsToLine(point(xc1, yc1), point(xc2, yc2), l1);
        pointsToLine(point(xc3, yc3), point(xc4, yc4), l2);    
        if (areSame(l1, l2)) printf("LINE\n");
        else if (areParalel(l1, l2)) printf("NONE\n");
        else {
            areIntersect(l1, l2, p);
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
