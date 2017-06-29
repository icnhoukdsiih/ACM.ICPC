// PREPARING ACM.ICPC 2018
// 191UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//Chu y cac diem nam trong hinh chu nhat cung duoc tinh la giao voi hinh chu nhat
#include <bits/stdc++.h>
using namespace std;
int xstart, ystart, xend, yend, xleft, ytop, xright,ybottom,n;
void intersectSegment(double l1, double r1, double l2, double r2, double &l, double &r) {
    l = max(l1,l2);
    r = min(r1,r2);
}
double ytox(double y) {
    return 1.0 * (y - ystart) * (xend - xstart) / (yend - ystart) + xstart;
}
int main() {
    scanf("%d",&n);
    for (int t = 0; t < n; t++) {
        scanf("%d%d%d%d%d%d%d%d",&xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
        int maxx = max(xstart, xend), maxy = max(ystart, yend), minx = min(xstart, xend), miny = min(ystart, yend);
        //Vi dinh nghia top left - bottom right tuy y nen chuyen ve dang mac dinh
        //xleft <= xright; ybottom <= ytop
        if (xleft > xright) swap(xleft, xright);
        if (ybottom > ytop) swap(ybottom, ytop);
        double lx = 1, rx = 0, ly = 1, ry = 0, lx1 = xstart, rx1 = xend, l = 1 , r = 0;
        //Neu co it nhat 1 diem nam ngoai hoac tren hinh chu nhat
        if (maxx >= xright || minx <= xleft || maxy >= ytop || miny <= ybottom) {
            //Tim doan giao nhau theo truc x
            intersectSegment(minx, maxx, xleft, xright, lx, rx);
            //Tim doan giao nhau theo truc y
            intersectSegment(miny, maxy, ybottom, ytop, ly, ry);
            //Neu khong giao nhau theo truc x hay truc y thi xuat F
            if (lx > rx || ly > ry) printf("F\n");
            else {
                if (ystart != yend) {
                    lx1 = ytox(ly);
                    rx1 = ytox(ry);
                }
                if (lx1 > rx1) swap(lx1, rx1);
                intersectSegment(lx, rx, lx1, rx1, l, r);
                if (l > r) printf("F\n");
                else printf("T\n");
            }
        }
        else printf("T\n");
    }
    return 0;
}
