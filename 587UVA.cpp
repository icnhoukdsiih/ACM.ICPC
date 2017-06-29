// PREPARING ACM.ICPC 2018
// 587UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define make_pair mp
string s;
int l, n = 0;
map<string, double> a;
map<string, double>::iterator iti;
string lst[8] = {"N","E","W","S","NE","NW","SW","SE"};
//FILE *f = freopen("input.txt","rt",stdin);
int toNum(int left, int right) {
    int res = 0;
    for (int i = left; i <= right; i++)
        res = res * 10 + s[i] - '0';
    return res;
}
void add(int left, int right) {
    if (s[right-1] >= '0' && s[right-1] <= '9') a[s.substr(right,1)] += toNum(left, right-1);
    else a[s.substr(right-1,2)] += toNum(left,right-2);
}
int main() {
    for (int i = 0; i < 8; i++) a[lst[i]] = 0;
    do {
        cin >> s;
        if (s[0] == 'E') break;
        l = 0;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == ',' || s[i] == '.') {
                add(l,i-1);
                l = i + 1;
            }
        a["N"] -= a["S"];
        a["E"] -= a["W"];
        a["NE"] -= a["SW"];
        a["SE"] -= a["NW"];
        double v1 = sqrt(a["NE"] * a["NE"] / 2);
        if (a["NE"] < 0) v1 = -v1;
        double v2 = sqrt(a["SE"] * a["SE"] / 2);
        if (a["SE"] < 0) v2 = -v2;
        a["N"] += v1 - v2;
        a["E"] += v1 + v2;
        printf("Map #%d\n", ++n);
        printf("The treasure is located at (%.3f,%.3f).\n", a["E"], a["N"]);
        printf("The distance to the treasure is %.3f.\n\n",sqrt(a["N"]*a["N"] + a["E"] * a["E"]));
        for (iti = a.begin(); iti != a.end(); iti++)
            iti->second = 0;
    } while (1);
    return 0;
}
