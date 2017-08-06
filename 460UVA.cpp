// PREPARING ACM.ICPC 2018
// 460UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
int xbl, ybl, xtr, ytr, x1bl, y1bl, x1tr, y1tr, t;
//FILE *f = freopen("input.txt","rt",stdin);
//FILE *f1 = freopen("output.txt","wt",stdout);
int main() {
    scanf("%d",&t);
    for (int c = 0; c < t; c++) {
        scanf("%d%d%d%d", &xbl, &ybl, &xtr, &ytr);
        scanf("%d%d%d%d", &x1bl, &y1bl, &x1tr, &y1tr);    
        if (xbl < x1bl) xbl = x1bl;
        if (ybl < y1bl) ybl = y1bl;
        if (xtr > x1tr) xtr = x1tr;
        if (ytr > y1tr) ytr = y1tr;
        if (xbl >= xtr || ybl >= ytr) printf("No Overlap\n");
        else printf("%d %d %d %d\n",xbl,ybl,xtr,ytr);
        if (c < t-1) printf("\n");
    }
    return 0;
}
