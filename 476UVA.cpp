// PREPARING ACM.ICPC 2018
// 476UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
typedef struct Rectangle {
    double x,y,x1,y1; //bottom-left and top-right coordinates
    bool contain(double _x, double _y) const {
        return (x < _x && _x < x1 && y < _y && _y < y1);
    }
} rectangle;
rectangle r[10];
int sz = 0, szp = 0;
char c;
double px,py;
bool check;
//FILE *f = freopen("input.txt","rt",stdin);
int main() {
    do {
        scanf("%c",&c);
        if (c == '*') break;
        scanf("%lf%lf%lf%lf%*c",&r[sz].x ,&r[sz].y1,&r[sz].x1,&r[sz].y);
        sz++;
    } while (1);
    do {
        scanf("%lf%lf",&px,&py);
        if (px == 9999.9  && py == 9999.9 ) break;
        szp++;
        check = false;
        for (int i = 0; i < sz; i++)
            if (r[i].contain(px,py)) {
                check = true;
                printf("Point %d is contained in figure %d\n",szp,i+1);
            }
        if (check == false) printf("Point %d is not contained in any figure\n",szp);
    } while (1);
    return 0;
}
