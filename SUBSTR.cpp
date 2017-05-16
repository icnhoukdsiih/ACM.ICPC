// PREPARING ACM.ICPC 2018
// SUBSTR - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e16 + 3;
string s1, s2; // s2 la chuoi mau can so vi tri xuat hien trong chuoi s1
int l1, l2; // l1, l2 la do dai s1, s2
ll pow26, v1 = 0, v2 = 0; // pow26 luu 26^l2 % MOD; v2 la gia tri hash s2, v1 la gia tri hash o vi tri hien tai cua s1
int main() {
    //freopen("in.txt","rt",stdin);
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    pow26 = 26;
    v2 = s2[0] - 97;
    v1 = s1[0] - 97;
    for (int i = 1; i < l2; i++) {
        pow26 = (pow26 * 26) % MOD; //Tinh 26^l2 %MOD
        v2 = (v2 * 26 + s2[i] - 97) % MOD; // Tinh hash s2
        v1 = (v1 * 26 + s1[i] - 97) % MOD; // Tinh hash s1 bat dau tai vi tri khong (do dai bang l2)
    }
    if (v1 == v2) cout << 1 << " "; // Neu gia tri hash bang nhau thi vi tri 1 trung
    for (int i = l2; i < l1; i++) { // Xet cac vi tri tiep theo, i la vi tri cuoi cua doan dang xet
        v1 = (((v1 * 26 + s1[i] - 97) % MOD - pow26 * (s1[i - l2] - 97) % MOD) + MOD) % MOD; // Tinh gia tri hash cua chuoi ket thuc tai i
        if (v1 == v2) cout << i - l2 + 2 << " "; // Neu gia tri hash bang nhau thi vi tri i - l2 + 2 trung
    }
    return 0;
}
