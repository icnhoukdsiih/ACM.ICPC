// PREPARING ACM.ICPC 2018
// 10209UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
const double PI = acos(0) * 2;
using namespace std;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
double a, v1, v2, v3;
int main() {
    while (scanf("%lf",&a) == 1) {
        double h1 = a * (1 - sqrt(3) / 2);
        double _s2 = PI * a * a / 12 - a * a / 4;        
        v1 = a * h1 / 2 - 2 * _s2;
        v2 = a * a - PI * a * a / 4 - 2 * v1;
        v3 = a * a - 4 * (v1 + v2);
        printf("%.3lf %.3lf %.3lf\n",v3,4*v2,4*v1);
    }
    return 0;
}
