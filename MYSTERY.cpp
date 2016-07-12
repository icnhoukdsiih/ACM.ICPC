// PREPARING ACM.ICPC 2018
// MYSTERY - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=20122007;
ll a,res=1; //res dùng để tính kết quả

//Tính 3^k bằng chia để trị
ll threepow(ll k) {
    if (k==0) return 1;
    ll value=threepow(k/2);
    return ((value*value)%mod*(ll)(k%2==1?3:1))%mod;
}

int main() {
    scanf("%lld",&a);
    //Tìm các ước i của a và nhân dồn 3^i-1 vào res
    for (ll i=1;i<=(ll)sqrt(a);i++)
    if (a%i==0) {
        res=res*(threepow(i)-1)%mod;
        if (i*i!=a) res=res*(threepow(a/i)-1)%mod;
    }
    printf("%lld",res);
    return 0;
}
