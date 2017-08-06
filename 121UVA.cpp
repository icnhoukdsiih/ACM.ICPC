// PREPARING ACM.ICPC 2018
// 121UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
#include <math.h>
double a,b;
int resGrid, resSkew, oddRows, evenRows;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
int solveSkew(double v1, double v2) {
    v1 = sqrt(4 * (v1 - 1) * (v1 - 1) / 3);
    evenRows = int(v1) / 2 + int(v1) % 2;
    oddRows = int(v1) - evenRows;
    return int(v2) + (int)v2 * oddRows + int(v2 - 0.5) * evenRows;
}
int main() {
    while (scanf("%lf%lf",&a,&b) == 2) {
        if (a < 1 || b < 1) {
            printf("0 grid\n");
            continue;
        }
        resGrid = int(a) * int(b);
        resSkew = solveSkew(a,b) > solveSkew(b,a) ? solveSkew(a,b) : solveSkew(b,a);
        if (resGrid >= resSkew) printf("%d grid\n",resGrid);
        else printf("%d skew\n",resSkew);
    }
    return 0;
}
