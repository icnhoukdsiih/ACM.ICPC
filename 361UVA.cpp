// 361UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define pb push_back

const double EPS = 1e-6;

using namespace std;

struct point {
	int x, y;
	point(): x(0), y(0) {};
	point(int _x, int _y): x(_x), y(_y) {};
	bool operator == (const point &p) const {
		return (x == p.x && y == p.y);
	}
};
int c, r, o, test = 0;
vector<point> posC, posR, posO, chC, chR;
int *isSafe;
point pivot(0,0);

void readInput() {
	++test;
	int cx,cy;

	posC.clear(); posC.resize(0);
	posR.clear(); posR.resize(0);
	posO.clear(); posO.resize(0);

	scanf("%d%d%d",&c,&r,&o);

	for (int i = 0; i < c; i++) {
		scanf("%d%d",&cx,&cy);
		posC.pb(point(cx,cy));
	}
	for (int i = 0; i < r; i++) {
		scanf("%d%d",&cx,&cy);
		posR.pb(point(cx,cy));
	}
	for (int i = 0; i < o; i++) {
		scanf("%d%d",&cx,&cy);
		posO.pb(point(cx,cy));
	}
}

//check p0->p1->p2 turn clockwise 
bool ccw(point p0, point p1, point p2) {
	point v1(p1.x - p0.x, p1.y - p0.y);
	point v2(p2.x - p1.x, p2.y - p1.y);
	return (v1.x * v2.y - v2.x * v1.y > 0);
}

//length of vector v
double vec2Len(point v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

//check point p inside convexhull h
bool insideCH(point p, vector<point> ch) {
	double s = 0;
	for (int i = 0; i < ch.size() - 1; i++) {
		if (p == ch[i] || p == ch[i+1]) return true;
		point u(p.x - ch[i].x, p.y - ch[i].y);
		point v(p.x - ch[i+1].x, p.y - ch[i+1].y);
		if (u.x * v.y == u.y * v.x && (((p.x - ch[i].x) * (p.x - ch[i+1].x) < 0) || ((p.y - ch[i].y) * (p.y - ch[i+1].y) < 0))) return true;
		if (ccw(ch[i],p,ch[i+1])) s -= acos((u.x * v.x + u.y * v.y) / (vec2Len(u) * vec2Len(v)));
		else s += acos((u.x * v.x + u.y * v.y) / (vec2Len(u) * vec2Len(v)));
	}
	return (fabs(s-acos(0)*4) < EPS);
}

bool pointCmp(const point &p1, const point &p2) {
	point v1(p1.x - pivot.x, p1.y - pivot.y);
	point v2(p2.x - pivot.x, p2.y - pivot.y);
	if (v1.x * v2.y == v2.x * v1.y) return  (abs(v1.x) < abs(v2.x));
	return (acos(v1.x/vec2Len(v1)) < acos(v2.x/vec2Len(v2)));
}

//build covex hull with p.size() > 2
void CH(vector<point> p, vector<point> &ch) {
	int p0 = 0;
	for (int i = 1; i < p.size(); i++)
		if (p[i].y < p[p0].y || (p[i].y == p[p0].y && p[i].x > p[p0].x)) p0 = i;
	point tmp = p[p0];
	p[p0] = p[0];
	p[0] = tmp;
	pivot = p[0];
	sort(p.begin()+1, p.end(), pointCmp);
	
	ch.clear(); ch.resize(0);
	ch.pb(p[p.size()-1]);
	ch.pb(p[0]);
	ch.pb(p[1]);
	int sz = 2;
	for (int i = 2; i < p.size(); i++) {
		while (sz > 1 && ccw(ch[sz-1], ch[sz], p[i]) == false) sz--;
		ch.resize(sz+1);
		ch.pb(p[i]);
		sz++;
	}
	//for (int i = 0; i < ch.size(); i++) printf("%d %d\n",ch[i].x,ch[i].y);
	//printf("------\n");
}

//case 2 cops or 2 robbers => no one either safe or robbed 
void solve() {
	isSafe = new int[o];
	for (int i = 0; i < o; i++) isSafe[i] = 0;
	if (c >= 3) {
		CH(posC, chC);
		for (int i = 0; i < o; i++)
			if (insideCH(posO[i], chC)) 
				isSafe[i] = 1;
	}
	if (r >= 3) {
		CH(posR, chR);
		for (int i = 0; i < o; i++)
			if (isSafe[i] == 0 && insideCH(posO[i], chR)) 
				isSafe[i] = 2;
	}
	printf("Data set %d:\n",test);
	for (int i = 0; i < o; i++)
		if (isSafe[i] == 0) printf("     Citizen at (%d,%d) is neither.\n",posO[i].x, posO[i].y);
		else if (isSafe[i] == 1) printf("     Citizen at (%d,%d) is safe.\n",posO[i].x, posO[i].y);
		else printf("     Citizen at (%d,%d) is robbed.\n",posO[i].x, posO[i].y);
	printf("\n");
	delete []isSafe;
}
int main() {
	//freopen("in","r",stdin);
	//freopen("ou","w",stdout);
	do {
		readInput();
		if (c == 0 && r == 0 && o == 0) break;
		solve();
	} while (1);
	return 0;
}
