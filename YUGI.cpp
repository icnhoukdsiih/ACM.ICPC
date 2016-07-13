// PREPARING ACM.ICPC 2018
// YUGI - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

//Kiểu cấu trúc lưu thông tin độ tương tác c của cặp bài u,v
struct edge {
    int u, v, c;
};
int n,k,val,m=0,root[201],cou,pu,pv; //root dùng để tìm lá bài gốc j mà cùng nhóm với lá bài đang xét i, khi đó -root[j] là số lá cùng nhóm với j
edge a[20000]; //a lưu thông tin các cặp bài

//Hàm so sánh để sắp xếp a tăng dần theo độ tương tác
bool compare(const edge &v1, const edge &v2) {
    return (v1.c<v2.c);
}

//Tìm bộ bài gốc cùng nhóm với node
int findroot(int node) {
    while (root[node]>0) node=root[node];
    return node;
}

int main() {
    //Đọc thông tin
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) {
        scanf("%d",&val);
        if (j>i) {
            a[++m].u=i;
            a[m].v=j;
            a[m].c=val;
        }
    }
    //Sắp xếp a 
    sort(a+1,a+m+1,compare);
    cou=n;
    //Khởi tạo gốc của từng lá bài
    for (int i=1;i<=n;i++) root[i]=-1;
    for (int i=1;i<=m;i++) {
        pu=findroot(a[i].u);
        pv=findroot(a[i].v);
	//Nếu 2 lá khác gốc
        if (pu!=pv) {
	    //Nếu số nhóm đã đủ k thì cặp bài đang xét có độ tương tác nhỏ nhất trong các lá  bài khác nhóm còn lại
            if (cou==k) {
                printf("%d",a[i].c);
                return 0;
            }
	    //Nếu số nhóm chưa đủ k thì cập nhật lại gốc 
            if (-root[pu]>-root[pv]) {
                root[pu]+=root[pv];
                root[pv]=pu;
            }
            else {
                root[pv]+=root[pu];
                root[pu]=pv;
            }
            cou--;
        }
    }
}
