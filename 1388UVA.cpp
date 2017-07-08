// PREPARING ACM.ICPC 2018
// 1388UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const double L = 10000;
const double EPS = 1e-8;
//FILE *f = freopen("input.txt","rt",stdin);
int n,m;
double posi, bf, af, res;
int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		res = 0;
		for (int i = 0; i < n; i++) {
			posi = L / n * i;
			bf = int(posi / (L / (m + n))) * L / (m + n);
			af = bf + L / (m + n);
			res += min(af-posi, posi - bf);
		}	
		printf("%.4f\n",fabs(res) <= EPS ? 0 : res);
	}	
    return 0;
}
