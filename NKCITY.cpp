// PREPARING ACM.ICPC 2018
// NKCITY - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int MAXM=10000;
int n,m,u[MAXM+1],v[MAXM+1],parent[MAXN+1],res=0,c;
set<pair<int,int> > edge;
//Tìm gốc của một nút
int findRoot(int node) {
    if (parent[node]<0) return node;
    return (parent[node]=findRoot(parent[node]));
}
//Ghép hai nút về một gốc
void joinNode(int u, int v,int co) {
    int ru=findRoot(u);
    int rv=findRoot(v);
    if (ru==rv) return;
    res=max(res,co);
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
    scanf("%d%d",&n,&m);
    edge.clear();
	//Khởi tạo mỗi nút là gốc và quản lý chính nó
    for (int i=1;i<=n;i++) parent[i]=-1;
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",u+i,v+i,&c);
		//Thêm cạnh và chỉ số cạnh vào set
        edge.insert(make_pair(c,i));
    }
	//Lấy các cạnh giá trị tăng dần trong set
    while (!edge.empty()) {
        pair<int,int> cur=*edge.begin();
        edge.erase(cur);
        joinNode(u[cur.second],v[cur.second],cur.first);
    }
    printf("%d",res);
    return 0;
}
