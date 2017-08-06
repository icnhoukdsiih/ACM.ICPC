// PREPARING ACM.ICPC 2018
// 477UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
class Figure {
public:
    Figure() {};
    virtual bool contain(double _x, double _y) {
    }
};
class Rectangle:public Figure {
public:
    double x,y,x1,y1; //bottom-left and top-right
    Rectangle(double _x, double _y, double _x1, double _y1) {
        x = _x;
        y = _y;
        x1 = _x1;
        y1 = _y1;
    }
    bool contain(double _x, double _y) {
        return (x < _x && _x < x1 && y < _y && _y < y1);
    }
};
class Circle:public Figure {
public:
    double x,y,r;
    Circle(double _x, double _y, double _r) {
        x = _x;
        y = _y;
        r = _r;
    }
    bool contain(double _x, double _y) {
        return ((_x - x)*(_x - x) + (_y - y)*(_y - y) < r * r);
    }
};
Figure *r[10];
int sz = 0, szp = 0;
char c;
double px, py, px1, py1, rc;
bool check;
//FILE *f = freopen("input.txt","rt",stdin);
int main() {
    do {
        scanf("%c",&c);
        if (c == '*') break;
        if (c== 'r') {
            scanf("%lf%lf%lf%lf%*c", &px, &py1, &px1, &py);
            r[sz] = new Rectangle(px, py, px1, py1);
        }
        else {
            scanf("%lf%lf%lf%*c", &px, &py, &rc);
            r[sz] = new Circle(px, py, rc);
        }
        sz++;
    } while (1);
    do {
        scanf("%lf%lf",&px,&py);
        if (px == 9999.9  && py == 9999.9 ) break;
        szp++;
        check = false;
        for (int i = 0; i < sz; i++)
            if (r[i]->contain(px,py)) {
                check = true;
                printf("Point %d is contained in figure %d\n",szp,i+1);
            }
        if (check == false) printf("Point %d is not contained in any figure\n",szp);
    } while (1);
    return 0;
}
