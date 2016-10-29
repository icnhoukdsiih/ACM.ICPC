#include <bits/stdc++.h>
using namespace std;
const int MAX_N=10000;
const int MAX_M=100000;
int n,m,parent[MAX_N+1],u[MAX_M+1],v[MAX_M+1],c,cost=0;
set<pair<int,int>,greater<pair<int,int> > > edge;
//Tìm gốc của một nút
int findRoot(int node) {
    if (parent[node]<0) return node;
    return (parent[node]=findRoot(parent[node]));
}
//Ghép hai nút lại chung một gốc
void joinNode(int u, int v,int co) {
    int ru=findRoot(u);
    int rv=findRoot(v);
    if (ru==rv) return; //Nếu 2 nút chung gốc thì cạnh nối u-v được đặt camera
	//Ngược lại thì ghép u-v vào 1 gốc 
    cost-=co;
    if (abs(parent[ru]>abs(parent[rv]))) {
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
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",u+i,v+i,&c);
        cost+=c;
		//Đưa cạnh vào set theo chi phí lắp giảm dần
        edge.insert(make_pair(c,i));
    }
    for (int i=1;i<=n;i++) parent[i]=-1;
    while (!edge.empty()) {
        pair<int,int> cur=*edge.begin();
        edge.erase(cur);
        joinNode(u[cur.second],v[cur.second],cur.first);
    }
    printf("%d",cost);
    return 0;
}
