// PREPARING ACM.ICPC 2018
// 833UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef struct segmentLine {
    int x1,y1,x2,y2;
    segmentLine(): x1(0),y1(0),x2(0),y2(0) {}
    segmentLine(int _x1, int _y1, int _x2, int _y2): x1(_x1),y1(_y1),x2(_x2),y2(_y2) {} 
    bool operator < (segmentLine other) const {
        return min(y1,y2) < min(other.y1, other.y2);
    }
} segLine;

int t, nl, np, v1, v2, v3, v4;
vector<segLine> a;
vector<int> fallRes;
//FILE *f = freopen("input.txt","rt",stdin);

int fall(segLine l) {
    return l.y1 < l.y2 ? l.x1 : l.x2;
}
int falledSegment(int x, int y, int n1) {
    double maxY = -1, yc;
    int pos = -1, minX, maxX;
    for (int i = n1; i>=0; i--) {
        minX = min(a[i].x1, a[i].x2);
        maxX = max(a[i].x1, a[i].x2);
        if (minX < x && maxX > x) {
            yc = (double)(a[i].y1-a[i].y2)*(x - a[i].x2)/(a[i].x1 - a[i].x2) + a[i].y2;
            if (yc < y && maxY < yc) {
                maxY = yc;
                pos = i;
            }
        }
    }
    return pos;
}
int main() {
    scanf("%d",&t);
    for (int ti = 0; ti < t; ti++) {
        a.resize(0);
        scanf("%d",&nl);
        for (int i = 0; i < nl; i++) {
            scanf("%d%d%d%d", &v1,&v2,&v3,&v4);
            a.pb(segLine(v1,v2,v3,v4));
        }
        sort(a.begin(), a.end());
        fallRes.resize(0);
        fallRes.pb(fall(a[0]));
        for (int i = 1; i < nl; i++) {
            int fx = fall(a[i]);
            int fy = (fx == a[i].x1 ? a[i].y1 : a[i].y2);
            int pre = falledSegment(fx, fy, i-1);
            if (pre == -1) fallRes.pb(fx);
            else fallRes.pb(fallRes[pre]);
        }
        scanf("%d", &np);
        for (int i = 0; i < np; i++) {
            scanf("%d%d",&v1,&v2);
            int res = falledSegment(v1,v2,nl-1);
            printf("%d\n",(res == -1 ? v1 : fallRes[res]));
        }
        if (ti < t-1) printf("\n");
    }
    return 0;
}
