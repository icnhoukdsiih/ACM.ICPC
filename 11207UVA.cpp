// PREPARING ACM.ICPC 2018
// 11207UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
int n, h, w, id, tmp;
double sz, csz;
//FILE *f = freopen("input.txt","rt",stdin);
double max(double v1, double v2) {
    return v1 < v2 ? v2 : v1;
}
double min(double v1, double v2) {
    return v1 < v2 ? v1 : v2;
}
int main() {
    do {
        scanf("%d",&n);
        if (n == 0) break;
        sz = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d",&h,&w);
            if (h > w) {
                tmp = h;
                h = w;
                w = tmp;
            }
            csz = max(h / 2.0,min(w, h * 4) / 4.0);
            if (csz > sz) {
                id = i + 1;
                sz = csz;
            }
        }
        printf("%d\n",id);
    } while (1);
    return 0;
}
