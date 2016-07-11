#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e18;
ll f[4001][90][3]={0},n,res[3]={0};
int main() {
    scanf("%lld",&n);
    for (ll i=1;i<=n;i++) f[i][1][0]=1;
    for (ll i=1;i<=n;i++)
    for (ll j=2;j*(j+1)<=2*i;j++){
        ll nho=0;
        for (ll k=0;k<3;k++) {
            f[i][j][k]=f[i-j][j][k]+f[i-j][j-1][k]+nho;
            nho=f[i][j][k]/mod;
            f[i][j][k]%=mod;
    }
    }
    for (ll j=2;j*(j+1)<=2*n;j++) {
        ll nho=0;
        for (ll k=0;k<3;k++) {
            res[k]+=f[n][j][k]+nho;
            nho=res[k]/mod;
            res[k]%=mod;
    }
    }
    ll pos=2;
    while (res[pos]==0 && pos>0) pos--;
    printf("%lld",res[pos]);
    for (ll i=pos-1;i>=0;i--){
        ll cou=17;
        if (res[i]>0) cou-=(ll)log10(res[i]);
        for (ll j=1;j<=cou;j++) printf("0");
        printf("%lld",res[i]);
    }
    return 0;
}
