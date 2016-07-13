// PREPARING ACM.ICPC 2018
// LIS - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll Max=1e18;
ll Min[30001],n,val,d,c,l=0,mid; 
//Min[i] dùng để lưu giá trị nhỏ nhất phần tử thứ i trong dãy con tăng độ dài i
//l là độ dài dãy con tăng dài nhất

int main() {
    scanf("%lld",&n);
    //Khởi tạo
    Min[0]=-Max;
    for (int i=1;i<=n;i++) Min[i]=Max;
    for (int i=1;i<=n;i++) {
        scanf("%lld",&val);
	//Nếu phần tử hiện tại lớn hơn Min[l] thì ta cập nhật Min[l+1] và độ dài của dãy con tăng dài nhất
        if (val>Min[l]) Min[++l]=val;
	//Ngược lại tiến hành duyệt nhị phân tìm độ dài dãy con tăng dài nhất kết thúc tại vị trí đang xét
        else {
            d=1;
            c=l;
            while (d<=c) {
                mid=(d+c)/2;
                if (val<Min[mid] && val>Min[mid-1]) {
                    Min[mid]=val;
                    break;
                }
                if (Min[mid]<val) d=mid+1;
                else c=mid-1;
            }
        }
    }
    printf("%lld",l);
    return 0;
}
