//s	->w(1)->	clubs(40000)	->w(1)->	residents(1000)	->w(1)->	party(1000)	->w(|clubs-1|/2)->	t
// Can than phan tim luong cuc dai
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int INF = 1000;
const int S = 0;
const int CLUB = 1;
const int RESIDENT = 1002;
const int PARTY = 2003;
const int T = 3004;

#define mp make_pair
#define pb push_back

int ts;
vector<string> sR, sC; //Lay chuoi cua dinh thu i trong edge
vector<pair<int, int> > edge[3005];
map<string, int> position;
map<pair<int,int>, int> a;
int nClub = 0, nResident = 0, nParty = 0;
int maxFlow;
bool visited[3005];
int q[3005][2];
bool findPath;
//FILE *f = freopen("input.txt","rt",stdin);
void init() {
	sR.resize(0);
	sC.resize(0);
	for (int i = 0; i <= T; i++) edge[i].resize(0);
	position.clear();
	a.clear();	
	nClub = 0;
	nResident = 0;
	nParty = 0;
	maxFlow = 0;
}

void addEdge(int pos1, int pos2, int w1, int w2) {
    if (a.find(mp(pos1,pos2)) != a.end()) return;
	a[mp(pos1,pos2)] = edge[pos1].size();
	a[mp(pos2,pos1)] = edge[pos2].size();
	edge[pos1].pb(mp(pos2,w1));
	edge[pos2].pb(mp(pos1,w2));
}
void matching() {
    for (int i = 0; i <= T; i++) visited[i] = false;
    int front, rear, u, v ,sz;
	do {
        q[0][0] = S;
        q[0][1] = -1;
        front = -1;
        rear = 1;
        visited[S] = true;
        while (++front < rear) {
            u = q[front][0];
            sz = edge[u].size();
            for (int i = 0; i < sz; i++) {
                v = edge[u][i].first;
                if (visited[v] == false && edge[u][i].second > 0) {
                    q[rear][0] = v;
                    q[rear++][1] = front;
                    visited[v] = true;
                    if (v == T) break;
                }
            }
            if (visited[T]) break;
        }
        if (visited[T] == false) break;
        front = rear - 1;
        while (front > 0) {
            v = q[front][0];
            front = q[front][1];
            u = q[front][0];
            edge[u][a[mp(u,v)]].second -= 1;
            edge[v][a[mp(v,u)]].second += 1;
        }
        maxFlow += 1;
        for (int i = 0; i < rear; i++) visited[q[i][0]] = false;
    } while (1);
	if (maxFlow == nClub) {
		for (int i = RESIDENT; i < RESIDENT + nResident; i++) {
			int sz = edge[i].size();
			for (int j = 0; j < sz; j++)
				if (edge[i][j].second == 1 && edge[i][j].first < RESIDENT) {
					cout << sR[i - RESIDENT] << " " << sC[edge[i][j].first - CLUB] << endl;
                    break;
                }
		}
	}
	else printf("Impossible.\n");
}
char scanfs(char st[]) {
    int pos = 0;
    char c;
    while (scanf("%c",&c)) {
        if (c == ' ' || c == '\n' || feof(stdin)) {
            st[pos++] = '\0';
            return c;
        }
        else st[pos++] = c;
    }
}
int main() {
	scanf("%d%*c%*c", &ts);
	char s[100];
	string st;
	char ch;
	for (int test = 0; test < ts; test++) {
		init();
		//doc mot test
		do {
			//doc resident
			ch = scanfs(s);
			if (feof(stdin) || s[0] == '\0') break;
			sR.pb(string(s));
			nResident++;
			//doc party
			ch = scanfs(s+1);
			s[0] = '!';
			st = string(s);
			if (position.find(st) == position.end()) position[st] = nParty++;
			addEdge(RESIDENT + nResident - 1, PARTY + position[st], 1, 0); //them canh
			//doc danh sach clubs
			while (ch == ' ') {
				ch = scanfs(s+1);
				s[0] = '@';
				st = string(s);
                if (s[1] == '\0') break;
				if (position.find(st) == position.end()) {
					position[st] = nClub++;
					if (nClub <= INF) sC.pb(st.substr(1));
				}
				if (nClub <= INF) addEdge(CLUB + position[st], RESIDENT + nResident - 1, 1, 0); //them canh	
				if (feof(stdin)) break;
			} 
			
		} while(feof(stdin) == false);
        if (nClub > nResident) {
            printf("Impossible.\n");
            if (test < ts - 1) printf("\n");
            continue;
        }
		for (int i = CLUB; i < CLUB + nClub; i++) addEdge(S, i, 1, 0);
		for (int i = PARTY; i < PARTY + nParty; i++) addEdge(i, T, (nClub - 1) / 2, 0);
		matching();
        if (test < ts - 1) printf("\n");
	}
	return 0;
}
