// PREPARING ACM.ICPC 2018
// 155UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
int k, x, y, res;
//FILE *f = freopen("input.txt","rt",stdin);
void solve(int a, int r, int c) {
    if (a == 0) return;
    if (r >= -a && r <= a && c >= -a && c <= a) res++;
    if (r > 0 && c > 0) solve(a/2, r-a, c-a);
    else if (r > 0 && c < 0) solve(a/2, r-a, c+a);
    else if (r < 0 && c > 0) solve(a/2, r+a, c-a);
    else solve(a/2, r+a, c+a);
}
int main() {
    do {
        scanf("%d%d%d",&k,&x,&y);
        if (k == 0 && x == 0 && y == 0)  break;
        res = 0;
        solve(k,x-1024,y-1024);
        printf("%3d\n",res);
    } while (1);
    return 0;
}
