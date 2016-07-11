// PREPARING ACM.ICPC 2018
// PBCDEM - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e18; //Lưu trữ các số theo hệ cơ số mod
//f là mảng quy hoạch động, với f[i][j] là số cách biểu diễn thỏa mãn dãy có tổng là i thành j số
//Chiều thứ 3 của f dùng để lưu kết quả theo hệ mod
ll f[4001][90][3]={0},n,res[3]={0}; 
int main() {
    scanf("%lld",&n);
    //Khởi tạo với trường hợp tổng i chỉ có 1 số
    for (ll i=1;i<=n;i++) f[i][1][0]=1;
    //Xét trường hợp tổng i có từ 2 số trở lên
    for (ll i=1;i<=n;i++)
    for (ll j=2;j*(j+1)<=2*i;j++){
        ll nho=0;
        for (ll k=0;k<3;k++) {
            //Xét theo 2 trường hợp, dãy không có số 1(f[i-j][j]) và dãy có số 1(f[i-j][j-1])
            //Dãy không có số 1 chính là các dãy phân tích số i-j thành j thành phần và mỗi thành phần cộng thêm 1
            /*Dãy có số 1 chính là các dãy phân tích số i-j thành j-1 thành phần và mỗi thành phần cộng thêm 1, 
            còn dư số 1 làm thành phần đầu tiên của các dãy*/
            f[i][j][k]=f[i-j][j][k]+f[i-j][j-1][k]+nho;
            nho=f[i][j][k]/mod;
            f[i][j][k]%=mod;
    }
    }
    //Cộng các kết quả có tổng n và độ dài 2 trở lên
    for (ll j=2;j*(j+1)<=2*n;j++) {
        ll nho=0;
        for (ll k=0;k<3;k++) {
            res[k]+=f[n][j][k]+nho;
            nho=res[k]/mod;
            res[k]%=mod;
    }
    }
    //In kết quả
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
