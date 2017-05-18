// PREPARING ACM.ICPC 2018
// PALINY - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 3;
int n, res = 1; // n la do dai chuoi, res la ket qua chuoi doi xung dai nhat
string s; // s la chuoi nhap vao
// hash0[i] la gia tri hash chuoi s tu 0 -> i-1
// hashn[i] la gia tri hash chuoi s tu n-1 -> i-1
// pow256[i] = 256^i
ll hash0[50002], hashn[50002], pow256[50001];
// tinh day doi xung dai nhat co chuoi chinh giua la s[mid1..mid2]
int solve(int mid1, int mid2) {
    int l = 0, r = n / 2, tmp, ma = 1; //ma la do dai chuoi doi xung dai nhat, l: can duoi, r: can tren
    if (mid2 > n || s[mid1 - 1] != s[mid2 - 1]) return 1;
    while (l <= r) {
        tmp = (l + r) / 2;
        if (mid1 - tmp < 1 || mid2 + tmp > n) r = tmp - 1;
        else {
            // Neu gia tri hash cua chuoi [mid1-tmp..mid2+tmp] = gia tri hash [mid2+tmp..mid1-tmp] thi cap nhat ma
            if ((hash0[mid2 + tmp] - (hash0[mid1 - tmp - 1] * pow256[2 * tmp + mid2 - mid1 + 1]) % MOD + MOD) % MOD
                == (hashn[mid1 - tmp] - (hashn[mid2 + tmp + 1] * pow256[2 * tmp + mid2 - mid1 + 1]) % MOD + MOD) % MOD) {
                    ma = 2 * tmp + mid2 - mid1 + 1;
                    l = tmp + 1;
                }
            else r = tmp - 1;
        }
    }
    return ma;
}
int main() {
    //freopen("in.txt","rt",stdin);
    cin >> n >> s;
    // Tinh pow256, hash0, hashn
    hash0[0] = 0;
    hashn[n + 1] = 0;
    pow256[0] = 1;
    for (int i = 0; i < n; i++) {
        hash0[i + 1] = (hash0[i] * 256 + s[i]) % MOD;
        hashn[n - i] = (hashn[n - i + 1] * 256 + s[n - i - 1]) % MOD;
        if (i > 0) pow256[i] = (pow256[i - 1] * 256) % MOD;
    }
    pow256[n] = (pow256[n - 1] * 256) % MOD;
    // Tim day doi xung dai nhat voi chuoi giua la s[i..i] hoac s[i..i+1]
    for (int i = 1; i <= n; i++) {
        res = max(max(res,solve(i, i)), solve(i, i + 1));
    }
    cout << res;
    return 0;
}
