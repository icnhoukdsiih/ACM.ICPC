// PREPARING ACM.ICPC 2018
// 10136UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
typedef struct Point {
    double x,y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
} point;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
int t, n, res, l;
char line[100];
point p[202];
double toDouble(char s[], int i, int j) {
    double v = 0;
    while (i <= j && s[i] != '.') 
        v = v * 10 + s[i++] - 48;
    double v1 = 0;
    while (j > i) 
        v1 = v1 / 10 + s[j--] - 48;
    return v + v1 / 10;
}
void toPoint(char s[], point &p) {
    for (int i = 0; i < l; i++) 
        if (s[i] == ' '){
            p = Point(toDouble(s, 0, i - 1), toDouble(s, i + 1, l - 1));
            break;
        }
}
void readLine(char s[]) {
    l = 0;
    while (feof(stdin) == false && scanf("%c",s+(l++)) == 1) 
        if (s[l-1] == '\n') break;
    s[--l] = '\0';
}
double sqrDis(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int checkPoint(point o) {
    int count = 0;
    for (int i = 0; i < n; i++) 
        if (6.25 - sqrDis(p[i],o) >= -EPS) count++;
    return count;
}
void solve() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) 
            if (25 - sqrDis(p[i],p[j]) >= -EPS){
            // l^2 = r^2 - sqrDis / 4 | vtpt * sqrt(l^2 / l(vtpt) ^ 2)
            // mid + vtpt'
            double ap = sqrt((6.25 - sqrDis(p[i],p[j]) / 4) / sqrDis(p[i],p[j])); //scale
            point vtpt((p[j].y - p[i].y) * ap, (p[i].x - p[j].x) * ap); //vertical vector
            point o((p[i].x + p[j].x) / 2 + vtpt.x,(p[i].y + p[j].y) / 2 + vtpt.y);
            res = max(max(res, checkPoint(o)), checkPoint(point(o.x - 2 * vtpt.x, o.y - 2 * vtpt.y)));
        }
}
int main() {
    scanf("%d%*c%*c",&t);
    for (int ti = 0; ti < t; ti++) {
        n = 0;
        do {
            readLine(line);
            if (feof(stdin) || line[0] == '\0') {
                res = (n > 0);
                solve();
                break;
            }
            else toPoint(line, p[n++]);    
        } while (1);
        printf("%d\n",res);
        if (ti < t - 1) printf("\n");
    }
    return 0;
}
