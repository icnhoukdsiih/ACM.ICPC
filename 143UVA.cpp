// PREPARING ACM.ICPC 2018
// 143UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
typedef struct sPoint {
    double x,y;
    sPoint(): x(0), y(0) {};
    sPoint(double _x, double _y): x(_x), y(_y) {};
} Point;
const double EPS = 1e-8;
double minX[101], maxX[101]; 
Point a,b,c;
int res;
double abs(double v) {
    return v < 0 ? -v : v;
}
double findX(Point p1, double y, Point p2) {
    if (p1.x == p2.x || y == p1.y) return p1.x;    
    if (y == p2.y) return p2.x;
    return (y - p2.y) / (p1.y - p2.y) * (p1.x - p2.x) + p2.x;
}
int upperBound(double v) {
    if (abs(v - int(v)) <= EPS) return int(v);
    return int(v)+1;
}
int lowerBound(double v) {
    int re = upperBound(v);
    if (abs(re-v) <= EPS) return re;
    return re-1;
}
void solve(Point p1, Point p2) {
    if (p1.y == p2.y) return;
    if (p1.y > p2.y) {
        Point tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    for (int i = upperBound(p1.y); i <= lowerBound(p2.y); i++) 
        if (i > 0 && i < 100) {
            double v = findX(p1,i,p2);
            if (maxX[i] < v) maxX[i] = v;
            if (minX[i] > v) minX[i] = v;
        }
}
double min(double v1, double v2) {
    return v1<v2?v1:v2;
}
double max(double v1, double v2) {
    return v1>v2?v1:v2;
}
int main() {
    do {
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        if (a.x + b.x + c.x + a.y + b.y + c.y == 0)  break;
        for (int i = 1; i < 100; i++) {
            maxX[i] = -1;
            minX[i] = 101;
        }
        solve(a,b);
        solve(b,c);
        solve(a,c);
        res = 0;
        for (int i = 1; i < 100; i++) 
            if (maxX[i] > 0) 
                res += min(99,lowerBound(maxX[i])) - max(1,upperBound(minX[i])) + 1;
        printf("%4d\n",res);
    } while (1);
    return 0;
}
