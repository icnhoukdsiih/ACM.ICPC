// PREPARING ACM.ICPC 2018
// IOIBIN - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int parent[N+1],p,x,y,z;
//Tìm gốc của một nút
int findRoot(int node) {
    if (parent[node]<0) return node;
    return (parent[node]=findRoot(parent[node]));
}
//Ghép hai nút vào chung một gốc
void joinNode(int u, int v) {
    int ru=findRoot(u);
    int rv=findRoot(v);
    if (ru==rv) return; //Nếu 2 gốc giống nhau thì thoát
	//Ngược lại lấy nút gốc quản lý ít nút hơn làm con nút kia
    if (abs(parent[ru])>abs(parent[rv])) {
        parent[ru]+=parent[rv];
        parent[rv]=ru;
    }
    else {
        parent[rv]+=parent[ru];
        parent[ru]=rv;
    }
}
int main() {
    //freopen("input.txt","rt",stdin);
    scanf("%d",&p);
	//Khởi tạo mỗi nút là gốc và số nút quản lý là 1 (chính nó)
    for (int i=1;i<=N;i++) parent[i]=-1;
    for (int i=1;i<=p;i++) {
        scanf("%d%d%d",&x,&y,&z);
        if (z==1) joinNode(x,y);
        else if (findRoot(x)==findRoot(y)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
