#include <stdio.h>
#include <vector>
#include <math.h>

#define pb push_back

using namespace std;

const double EPS = 1e-6;

struct point {
	double x,y;
	point(): x(0), y(0) {};
	point(double _x, double _y): x(_x), y(_y) {};
	bool operator == (const point &p) const {
		return (x == p.x && y == p.y);
	}
};

class figure {
public:
	virtual bool inside(const point &p1) {
	
	}
};

class circle: virtual public figure {
public:
	point p;
	double r;
	circle(point _p, double _r) {
		p = _p;
		r = _r;
	}
	bool inside(const point &p1) {
		return ((p1.x-p.x)*(p1.x-p.x) + (p1.y-p.y) * (p1.y-p.y) < r * r);
	}
};

class rectangle: virtual public figure {
public:
	point ul, lr;
	rectangle(point p1, point p2) {
		ul = p1;
		lr = p2;
	}
	bool inside(const point &p1) {
		return (p1.x < lr.x && p1.x > ul.x && p1.y < ul.y && p1.y > lr.y);
	}
};

class triangle: virtual public figure {
public:
	point a, b, c;
	triangle(point p1, point p2, point p3) {
		a = p1;
		b = p2;
		c = p3;
	}
	double area() {
		return fabs(a.x * b.y - a.y * b.x + b.x * c. y - b.y * c.x + c.x * a.y - c.y * a.x) / 2;
	}
	bool inside(const point &p1) {
		if  (p1 == a || p1 == b || p1 == c) return false;
		double sabp1 = triangle(a,b,p1).area(), sbcp1 = triangle(b,c,p1).area(), sacp1 = triangle(a,c,p1).area();
		if (sabp1 < EPS || sbcp1 < EPS || sacp1 < EPS) return false;
		return (fabs(area() - sabp1 - sbcp1 - sacp1) < EPS);
	}
};

vector<figure*> f;

int main() {
	//freopen("in","r",stdin);
	//freopen("ou","w",stdout);
	f.clear(); f.resize(0);
	char ch;
	point p1,p2,p3;
	double v;
	do {
		scanf("%c",&ch);
		if (ch == '*') break;
		if (ch == 'r') {
			scanf("%lf%lf%lf%lf%*c",&p1.x,&p1.y,&p2.x,&p2.y);
			f.pb(new rectangle(p1,p2));
		}
		else if (ch == 'c') {
			scanf("%lf%lf%lf%*c",&p1.x,&p1.y,&v);
			f.pb(new circle(p1,v));
		}
		else {
			scanf("%lf%lf%lf%lf%lf%lf%*c", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
			f.pb(new triangle(p1,p2,p3));
		}
	} while (1);
	int count = 0;
	bool check;
	do {
		++count;
		check = false;
		scanf("%lf%lf",&p1.x,&p1.y);
		if (p1.x == 9999.9 && p1.y == 9999.9) break;
		for (int i = 0; i < f.size(); i++)
			if (f[i]->inside(p1)) {
				printf("Point %d is contained in figure %d\n",count,i+1);
				check = true;
			}
		if (check == false) printf("Point %d is not contained in any figure\n",count);
	} while (1);
	return 0;
}
