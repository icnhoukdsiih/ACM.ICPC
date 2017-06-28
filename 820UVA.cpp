// PREPARING ACM.ICPC 2018
// 820UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6 + 1; //oo
//edge la ma tran mo ta trong so tat ca cac canh
//maxFlow, minEdge la luong cuc dai va trong so nho nhat tren duong di
int n, s, t, m, edge[101][101], maxFlow, minEdge, test = 0;
//connect luu canh noi voi moi dinh (connec[u] chua cac dinh ke u)
vector<int> connect[101];
//q, front, rear tuong ung hang doi, chi so dau, cuoi cua hang doi
//previous luu chi so truoc cua 1 dinh khi bfs
int q[101], front, rear, previous[101];
FILE *f = freopen("input.txt","rt",stdin);
//Khoi tao
void init() {
	for (int i = 0; i < 101; i++) connect[i].resize(0);
	memset(edge, 0, sizeof(edge));
	maxFlow = 0;
	minEdge = INF;
}
//Tang luong
void incFlow(int pos) {
	int v = q[pos]; //Lay dinh tuong ung
	int previousPos = previous[v]; //Truy vet vi tri truoc pos
	if (previousPos == -1) return;
	int u = q[previousPos]; //Dinh truoc v
	if (minEdge > edge[u][v]) minEdge = edge[u][v]; //Tim canh nho nhat
	incFlow(previousPos); 
	edge[u][v] -= minEdge; //- (+) trong so canh cung chieu (nguoc chieu)
	edge[v][u] += minEdge;
}
//Tim luong cuc dai
void matChing() {
	do {
		for (int i = 0; i <= n; i++) previous[i] = -2;
		front = -1;
		rear = 1;
		q[0] = s;
		previous[s] = -1;
		while (++front < rear) {
			int u = q[front];
			int sz = connect[u].size(), v;
			for (int i = 0; i < sz; i++) {
				v = connect[u][i];
				//Neu dinh chua duyet va trong so canh > 0
				if (edge[u][v] > 0 && previous[v] == -2) {
					previous[v] = front;
					q[rear++] = v;
					if (v == t) break; //Da duyet t thi break
				}	
			}
			if (previous[t] != -2) break; //Da duyet t thi break
		}
		if (previous[t] == -2) break; //Neu khong co duong di den t thi break
		minEdge = INF;
		incFlow(rear - 1);
		maxFlow += minEdge; 
	} while (1);	
}
int main() {
	do {
		test++;
		init();
		scanf("%d", &n); //Doc so dinh
		if (n == 0) return 0;
		scanf("%d%d%d", &s, &t, &m); //Doc dinh phat, dinh thu va so canh
		int u, v, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c); //Doc tung canh noi
			if (edge[u][v] == 0) { //Them canh vao connect neu chua them
				connect[u].push_back(v);
				connect[v].push_back(u);
			}
			edge[u][v] += c; //Tang trong so 
			edge[v][u] += c;
		}
		matChing();
		printf("Network %d\n", test);
		printf("The bandwidth is %d.\n\n", maxFlow);
	} while (1);	
	return 0;
}
