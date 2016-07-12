// PREPARING ACM.ICPC 2018
// SPACESET - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=12345678;
ll t,n,m,k,choice,res; //choice là số cách đi khi tàu đang ở 1 khu vực, res là kết quả

//Hàm tính value^p
ll power(ll value, ll p) {
    if (p==0) return 1;
    ll res=power(value,p/2)%mod;
    return ((res*res)%mod*(ll)(p%2==1?value:1))%mod;
}

int main() {
    //Đọc dữ liệu
    scanf("%lld",&t);
    for (ll c=0;c<t;c++) {
        scanf("%lld%lld%lld",&m,&n,&k);
        choice=((m<3?(m-1)*n:n*2)+(n<3?1:2))%mod; //Đếm số cách đi đến tầng trên, dưới và cùng tầng
        res=((m*n)%mod*power(choice,k-1))%mod;
        printf("%lld\n",res);
    }
    return 0;
}
