// PREPARING ACM.ICPC 2018
// 375UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
#include <math.h>
int t;
double b,h;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
int main() {
    scanf("%d",&t);
    for (int c = 0; c < t; c++) {
        scanf("%lf%lf",&b,&h);
        double l = sqrt(b*b / 4 + h * h);
        double ratio = 1 - b / (b / 2 + l);
        //printf("%lf\n",ratio);
        int k = int(-(6+log10(h/2)+log10(1-ratio)) / log10(ratio) + 1);
        //printf("%d\n",k);
        printf("%13.6lf\n", 2*acos(0)*(h-pow(ratio,k) * h));
        if (c < t - 1) printf("\n");
    }
    return 0;
}

