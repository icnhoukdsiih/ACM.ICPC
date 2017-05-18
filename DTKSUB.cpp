// PREPARING ACM.ICPC 2018
// DTKSUB - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 3;
// s: chuoi nhap vao
// n: do dai chuoi nhap vao; k: so lan lap lai; res: ket qua; l,r: can duoi, can tren cua res; tmp: gia tri chat nhi phan hien tai
// pow26[] voi pow26[i] = 26^i; hash0[] voi hash0[i] la gia tri hash s[0..i-1];
// k1: bien dem so lan lap mot gia tri hash cua chuoi do dai tmp
// cou[] chua cac gia tri hash cua chuoi do dai tmp; lcou: do dai cua cou
int n, k, l, r, tmp, res = 0, pow26[50001], hash0[50001], k1, cou[50001], lcou;
char s[50001];
int main() {
    //freopen("in.txt","rt",stdin);
    scanf("%d%d%*c%s",&n, &k, s);
    if (k == 1) { // Neu k = 1 thi ket qua chinh la n
        printf("%d", n);
        return 0;
    }
    // Tinh pow26[] va hash0[]
    pow26[0] = 1;
    hash0[0] = 0;
    for (int i = 1; i <= n; i++) {
        pow26[i] = ((ll)pow26[i - 1] * 26) % MOD;
        hash0[i] = ((ll)hash0[i - 1] * 26 + s[i - 1] - 97) % MOD;
    }
    // Gia tri can tren, can duoi ban dau de chat nhi phan
    l = 1;
    r = n - k + 1;
    // Chat nhi phan
    while (l <= r) {
        tmp = (l + r) / 2;
        lcou = 0;
        for (int i = 1; i <= n - tmp + 1; i++)
        cou[lcou++] = (hash0[i+tmp-1] - ((ll)hash0[i-1] * pow26[tmp]) % MOD + MOD) % MOD; // Dua gia tri hash chuoi s[i..i+tmp-1] vao cou[]
        sort(cou, cou + lcou); // Sap xep cou[] tang dan
        k1 = 1;
        for (int i = 1; i < lcou; i++) {
            if (cou[i] == cou[i - 1]) k1 ++; // Dem so lan lap cua 1 gia tri hash
            else k1 = 1;
            if (k1 >= k) { // Neu so lan lap >= k thi cap nhat res va can duoi
                res = tmp;
                l = tmp + 1;
                break;
            }
        }
        if (res != tmp) r = tmp - 1; // Neu can duoi khong cap nhat thi cap nhat lai can tren
    }
    printf("%d", res);
    return 0;
}
