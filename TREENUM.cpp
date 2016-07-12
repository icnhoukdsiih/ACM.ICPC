// PREPARING ACM.ICPC 2018
// TREENUM - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
//Kiểu cấu trúc dùng để lưu trữ số lớn
struct bignum {
    int a[40];
    int l;
};
int t;
ll n;
bignum threepow[66],res; //threepow[i] dùng để tính 3^i, res dùng để lưu kết quả

//Khởi tạo giá trị một số lớn
void init(bignum &num) {
    for (int i=0;i<40;i++) num.a[i]=0;
    num.l=1;
}

int main() {
    //Tính các phần tử trong mảng threepow
    init(threepow[0]);
    threepow[0].a[0]=1;
    for (int i=1;i<66;i++) {
        int nho=0;
        init(threepow[i]);
        threepow[i].l=threepow[i-1].l;
        for (int j=0;j<threepow[i-1].l;j++) {
            threepow[i].a[j]=threepow[i-1].a[j]*3+nho;
            nho=threepow[i].a[j]/10;
            threepow[i].a[j]%=10;
        }
        if (nho>0) threepow[i].a[threepow[i].l++]=nho;
    }
    //Đọc các test và giá trị n trong mỗi test
    scanf("%d",&t);
    for (int c=0;c<t;c++) {
        scanf("%llu",&n);
        init(res);
	//Xác định bit thứ i của n là 1 hay không
        for (int i=0;i<66;i++)
        if (n%2==1) {
	    //Nếu bit i là 1 thì cộng kết quả cho threepow[i]
            if (res.l<threepow[i].l) res.l=threepow[i].l;
            int nho=0;
            for (int j=0;j<res.l;j++) {
                res.a[j]+=threepow[i].a[j]+nho;
                nho=res.a[j]/10;
                res.a[j]%=10;
            }
            if (nho>0) res.a[res.l++]=nho;
            n/=2;
        } else n/=2;
	//Xuất kết quả
        for (int i=res.l-1;i>=0;i--) printf("%d",res.a[i]);
        printf("\n");
    }
    return 0;
}
