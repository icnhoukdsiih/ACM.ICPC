// PREPARING ACM.ICPC 2018
// 10180UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
typedef struct Point {
    double x,y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
} point;
typedef struct Line {
    double a,b,c;
    Line(): a(0), b(1), c(0) {}
    Line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
} line;
int n;
point p1, p2;
line l;
double res, r;
void pointToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) <= EPS) {
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
double sqrDis(point p1, point p2 = point(0,0)) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    scanf("%d",&n);
    for (int ti = 0; ti < n; ti++) {
        scanf("%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &r);
        pointToLine(p1, p2, l);
        line pt(l.b, -l.a, 0);
        if (l.c * l.c / (l.a * l.a + l.b * l.b) - r * r >= -EPS || 
           (pt.a * p1.x + pt.b * p1.y + pt.c)*(pt.a * p2.x + pt.b * p2.y + pt.c) >= 0) res = sqrt(sqrDis(p1,p2));
        else {
            double ap = acos((p1.x * p2.x + p1.y * p2.y) / sqrt(sqrDis(p1) * sqrDis(p2)));
            double arc = (ap - acos(r / sqrt(sqrDis(p1))) - acos(r / sqrt(sqrDis(p2)))) * r;
            res = arc + sqrt(sqrDis(p1) - r * r) + sqrt(sqrDis(p2) - r * r); 
        }
        printf("%.3lf\n",res);
    }
    return 0;
}
