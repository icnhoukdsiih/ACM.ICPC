// PREPARING ACM.ICPC 2018
// 10005UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const double EPS = 1e-6;
typedef struct Point {
    double x,y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
} point;
typedef struct Line {
    double a,b,c;
    Line(): a(0), b(0), c(0) {}
    Line(double _a, double _b, double _c): a(_a), b(_b), c(_c){}
} line;
//FILE *f = freopen("input.txt","rt",stdin);
int n, id1, id2;
double r, mr;
bool res;
point p[101];
void pointsToLine(point p1, point p2, line &l) {
    if (abs(p1.x - p2.x) == 0) {
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
bool areIntersect(line l1, line l2, point &p) {
    if (areParalel(l1,l2)) return false;
    p.x = (l2.c * l1.b - l1.c * l2.b)/(l1.a * l2.b - l2.a * l1.b);
    p.y = l1.b == 0 ? -l2.c - l2.a * p.x : -l1.c - l1.a * p.x;
    return true;
}
double sqrDis(point a, point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool checkPoint(point pt) {

    for (int i = 0; i < n; i++)
        if (r*r - sqrDis(pt,p[i]) < -EPS) return false;
    return true;
}
int main() {
    do {
        scanf("%d",&n);
        if (n == 0) break;
        //init
        id1 = 0;
        id2 = 0;
        mr = 1e10;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            for (int j = 0; j < i; j++) 
                if (sqrDis(p[id1],p[id2]) < sqrDis(p[i],p[j])) {
                    id1 = i;
                    id2 = j;    
                }
        }
        scanf("%lf",&r);
        //solve
        point mid11((p[id2].x + p[id1].x)/2, (p[id2].y + p[id1].y)/2);
        point mid12(mid11.x - p[id2].y + p[id1].y, mid11.y + p[id2].x - p[id1].x);
        line l1;
        pointsToLine(mid11,mid12,l1);
        res = checkPoint(mid11);
        if (res == false)
        for (int i = 0; i < n; i++) 
            if (i != id1 && i != id2) {
            point mid21((p[i].x + p[id2].x)/2, (p[i].y + p[id2].y)/2);
            point mid22(mid21.x - p[i].y + p[id2].y, mid21.y + p[i].x - p[id2].x);
            point intersect;
            line l2;
            pointsToLine(mid21, mid22, l2);
            if (areIntersect(l1,l2,intersect)) {
                res |= checkPoint(intersect);   
                if (res) 
                    mr = min(mr, sqrDis(intersect,p[id1]));
            }
            if (res) break;
        }
        if (res) printf("The polygon can be packed in the circle.\n");
        else printf("There is no way of packing that polygon.\n");
    } while (1);
    return 0;
}
