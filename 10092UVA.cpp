#include <bits/stdc++.h>
using namespace std;
const int INF = 200; 
#define mp make_pair
#define pb push_back
//np, nk tuong ung so problems, so categories; totalQuestion la tong so cau hoi cua de
//maxFlow, minEdge la luong cuc dai va trong so cuc tieu tren duong di 
//s,t la dinh nguon, dinh thu trong mang
int np, nk, totalQuestion, maxFlow, minEdge,s,t;
//Cac dinh source node->problem nodes->categories nodes->sink node
//Tuong ung voi dinh [0 .. np + nk +1]
vector<pair<int,int> > edge[1030];
//map[mp(u,v)] tuong ung vi tri dinh v trong edge[u]
map<pair<int,int>, int > a;
//q, previous la hang doi duyet bfs va dinh lien truoc dinh duyet trong bfs
//front, rear la chi so dau, cuoi cua hang doi
int q[1030], previous[1030], front, rear;
//Khoi tao khi bat dau moi test
void init() {
	a.clear();
	for (int i = 0; i < nk + np + 2; i++) 
		edge[i].clear();
	totalQuestion = 0;
	maxFlow = 0;
	minEdge = INF;
	s = 0;
	t = np + nk + 1;
	for (int i = 1; i <= np; i++) {
		a[mp(0, i)] = edge[0].size(); //Luu vi tri dinh i trong edge[0]
		a[mp(i, 0)] = edge[i].size(); //Luu vi tri dinh 0 trong edge[i]
		edge[0].pb(mp(i, 1)); //0 noi i trong so 1
		edge[i].pb(mp(0, 0)); //i noi 0 trong so 0
	}
}
//Tang luong
void incFlow(int pos) {
	int v = q[pos];
	int previousPos = previous[v];
	if (previousPos == -1) return;
	int u = q[previousPos];
	if (minEdge > edge[u][a[mp(u,v)]].second) 
		minEdge = edge[u][a[mp(u,v)]].second;
	incFlow(previousPos);
	edge[u][a[mp(u,v)]].second -= minEdge;
	edge[v][a[mp(v,u)]].second += minEdge;
}
//Tim luong cuc dai
void matching() {
	do {
		for (int i = 0; i <= nk + np + 2; i++) previous[i] = -2;
		front = -1;
		rear = 1;
		q[0] = s;
		previous[s] = -1;
		while (++front < rear) {
			int u = q[front], v;
			int sz = edge[u].size();
			for (int i = 0; i < sz; i++) {
				v = edge[u][i].first;
				//Neu dinh chua duyet va canh u,v trong so > 0
				if (previous[v] == -2 && edge[u][i].second > 0){ 
					previous[v] = front;
					q[rear++] = v;
					if (v == t) break; //Neu duyet toi sink thi break
				}
			}
			if (previous[t] != -2) break; //Neu dinh sink da duyet thi break
		}
		if (previous[t] == -2) break; //Neu sink chua duyet thi break
		minEdge = INF;
		incFlow(rear - 1);
		maxFlow += minEdge;
	} while (1);
	if (maxFlow == totalQuestion) {
		printf("1\n");
		for (int i = np + 1; i <= np + nk; i++) {
			int sz = edge[i].size();
			for (int j = 0; j < sz; j++) 
				if (edge[i][j].second == 1) printf("%d ", edge[i][j].first);
			printf("\n");
		}
	}
	else printf("0\n");
}
int main() {
	do {
		scanf("%d%d", &nk, &np);
		if (nk == 0 && np == 0) break;
		init();
		int problems;
		for (int i = np + 1; i <= np + nk; i++) {
			scanf("%d", &problems);
			a[mp(t, i)] = edge[t].size(); //Luu vi tri dinh i trong edge[t]
			a[mp(i, t)] = edge[i].size(); //Luu vi tri dinh t trong edge[i]
			edge[i].pb(mp(t, problems)); //i noi voi t trong so problems
			edge[t].pb(mp(i, 0)); //t noi voi i trong so 0
			totalQuestion += problems; //Tang so cau hoi trong de
		}
		int ni, c;
		for (int i = 1; i <= np; i++) {
			scanf("%d", &ni);
			for (int j = 0; j < ni; j++) {
				scanf("%d", &c);
				a[mp(np + c, i)] = edge[np + c].size(); //Luu vi tri dinh i trong edge[np+c]
				a[mp(i, np + c)] = edge[i].size(); //Luu vi tri dinh np+c trong edge[i]
				edge[i].pb(mp(np + c, 1)); //i noi np+c voi trong so 1
				edge[np + c].pb(mp(i, 0)); //np+c noi i voi trong so 0
			}
		}
		matching();
	} while (1);
	return 0;
}
