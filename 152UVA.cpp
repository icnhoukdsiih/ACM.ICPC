// PREPARING ACM.ICPC 2018
// 152UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//Chu y them dong trong sau khi output
#include <bits/stdc++.h>
using namespace std;
typedef struct point3d {
    int x,y,z;
} p3d;
int intDis3d(p3d a, p3d b) {
    return int(sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)));
}
int cou[10] = {0}, n = 0, dis;
p3d p[5001];
int main() {
    do {
        scanf("%d%d%d",&p[n].x, &p[n].y, &p[n].z);
        if (p[n].x == 0 && p[n].y == 0 && p[n].z == 0) break;
        n++;
    } while (1);
    for (int i = 0; i < n; i++) {
        dis = 10;
        for (int j = 0; j < n; j++)
            if (i != j) dis = min(dis, intDis3d(p[i], p[j]));
        if (dis < 10) cou[dis]++;
    }
    for (int i = 0; i < 10; i++) printf("%4d",cou[i]);
    printf("\n");
    return 0;
}
