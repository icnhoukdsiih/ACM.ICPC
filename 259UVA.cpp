// PREPARING ACM.ICPC 2018
// 259UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//Luu y dong cuoi co the khong phai la dong trong
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int INF = 1000;
const int S = 0; //Chi so dinh s trong edge
const int T = 37;//Chi so dinh t trong edge
const int APPS = 1; //Chi so application A trong edge
const int COMS = 27; //Chi so computer 0 trong edge
int edge[38][38]; //Bieu dien cac  canh noi trong do thi
char s[2][20]; //Doc du lieu input
int maxFlow, minEdge, totalUser;
//Khoi tao luong
void init() {
	totalUser = 0;
	maxFlow = 0;
	minEdge = INF;
	s[0][0] = '\0';
	s[1][0] = '\0';
	memset(edge, 0, sizeof(edge));
	//Khoi tao trong so canh tu cac may tinh 0..9 -> t la 1
	for (int i = COMS; i < COMS + 10; i++) 
		edge[i][T] = 1;
}
//Tang luong
void incFlow(int q[38][2], int pos) {
	int node = q[pos][0];
	int prev = q[pos][1];
	if (prev != -1) {
		int u = q[prev][0];
		if (minEdge > edge[u][node]) minEdge = edge[u][node];
		incFlow(q, prev);
		edge[u][node] -= minEdge;
		edge[node][u] += minEdge;
	} 
}
//Tim luong cuc dai
void matching() {
	do {
		//bfs tim duong di tu s den t
		int q[38][2], d = -1, c = 1, idT;
		bool visited[38] = {false};
		q[0][0] = S;
		q[0][1] = -1;
		visited[S] = true;
		while (++d < c) {
			int u = q[d][0];
			for (int i = 0; i <= T; i++) 
				if (visited[i] == false && edge[u][i] > 0) {
					if (i == T) idT = c;
					q[c][0] = i;
					q[c++][1] = d;
					visited[i] = true;		
				}
			if (visited[T])  break;
		}
		//Neu co duong di thi tang luong
		if (visited[T]) {
			minEdge = INF;
			incFlow(q, idT);
			maxFlow += minEdge;
		}
		else break; //Nguoc lai xuat ket qua va thoat
	} while (1);
	if (totalUser == maxFlow) {
		for (int i = COMS; i < COMS + 10; i++) {
			char ch = '_';
			for ( int j = APPS; j < APPS + 26; j++)
				if (edge[j][i] == INF - 1) ch = j-APPS+'A';
			printf("%c",ch);
		}
	}
	else printf("!");
	printf("\n");
	init();
}
int main() {
	init();
	while (feof(stdin) == false) {  
		scanf("%c",s[0]);
		if (s[0][0] != '\n' && feof(stdin) == false) {
			scanf("%s%s%*c", s[0]+1, s[1]);
			//Noi canh tu s toi s[0][0] voi trong so la s[0][1]
			int u  = APPS + s[0][0] - 'A';
			edge[S][u] += int(s[0][1] - '0');
			totalUser += int(s[0][1] - '0');
			//Noi canh tu s[0][0] toi cac may tinh voi trong so la INF
			int l = strlen(s[1]) - 1;
			for (int i = 0; i < l; i++) {
				int v = COMS + s[1][i] - '0';
				edge[u][v] = INF;
			}
		}
		else {
			matching();
			s[0][0] = '\0';
			if (feof(stdin)) break;
		}
	}
	return 0;
}
