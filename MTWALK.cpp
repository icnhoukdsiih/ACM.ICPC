// PREPARING ACM.ICPC 2018
// MTWALK - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

const int hmin=0;
const int hmax=110;
//minmx là độ cao nhỏ nhất lớn nhất, mxmin là độ cao lớn nhất nhỏ nhất có thể xét trong quá trình loang
//add là hiệu số dùng để loang sang các đỉnh trên, dưới, phải, trái
int n,a[101][101],res=hmax-hmin,minmx,mxmin,fr,re,mid,hight,add[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

//Kiểm tra loang các đỉnh có độ cao [l..m] từ (1,1) tới được (n,n) hay không
bool check(int l, int m) {
    bool fr[101][101]={0};
    int q[10001][2],da=0,ca=0;
    q[++ca][0]=1;
    q[ca][1]=1;
    fr[1][1]=1;
    while (da<ca) {
        da++;
        for (int i=0;i<4;i++) {
            int i1=q[da][0]+add[i][0], j1=q[da][1]+add[i][1];
            if (i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]>=l && a[i1][j1]<=m && fr[i1][j1]==0) {
                if (i1==n && j1==n) return 1;
                q[++ca][0]=i1;
                q[ca][1]=j1;
                fr[i1][j1]=1;
            }
        }
    }
    return 0;
}

int main() {
    //Đọc dữ liệu
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    //Tìm minmx, mxmin
    minmx=a[1][1]>a[n][n]?a[n][n]:a[1][1];
    mxmin=a[1][1]<a[n][n]?a[n][n]:a[1][1];
    //Với mỗi độ cao nhỏ nhất low, tiến hành chặt nhị phân tìm độ cao lớn nhất hight, 
    //sao cho loang (1,1)->(n,n) đi quá các đỉnh có độ cao [low..hight]
    for (int low=minmx;low>=0;low--) {
        fr=mxmin;
        re=(low+res)>hmax?hmax:(low+res);
        hight=hmax+1;
        while (fr<=re) {
            mid=(fr+re)/2;
            if (check(low,mid)) {
                hight=mid;
                re=mid-1;
            }
            else fr=mid+1;
        }
	//Kiểm tra nếu độ lệch nhỏ hơn kết quả thì cập nhật lại
        if (hight!=(hmax+1) && hight-low<res) res=hight-low;
    }
    printf("%d",res);
    return 0;
}
