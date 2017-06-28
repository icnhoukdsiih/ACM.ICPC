// PREPARING ACM.ICPC 2018
// 10779UVA - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//S ->w(so items) -> m items (bob) -> w(1) -> n-1 nguoi(tru bob)  -> w(so items -1) -> m items(nhung nguoi khac) -> w(1) -> T
//                   m items (bob)                  -> w(so items) ->                  m items(nhung nguoi khac)
//                   m items(nhung nguoi khac))     -> w(INF)      ->                  m items (bob)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int S = 0;
const int BOB_ITEMS = 1; // <= 25 items
const int PEOPLE = 26; // <= 10 people
const int OTHERS_ITEMS = 36; // <= 25 items
const int T = 61;
const int INF = 30;
int test, n, m, ni, vi, maxFlow;
int edge[62][62];
void init() {
    for (int i = 0; i < 62; i++)
        for (int j = 0; j < 62; j++) edge[i][j] = 0;
    maxFlow = 0;
}
void matching() {
    int q[62][2], front, rear, u, v;
    bool visited[62] = {0};
    do {
        front = -1;
        rear = 1;
        q[0][0] = S;
        q[0][1] = -1;
        visited[S] = true;
        while (++front < rear) {
            int u = q[front][0];
            for (int i = S; i <= T; i++)
                if (visited[i] == false && edge[u][i] > 0) {
                    q[rear][0] = i;
                    q[rear++][1] = front;
                    visited[i] = true;
                    if (i == T) break;
                }
            if (visited[T]) break;
        }
        if (visited[T] == false) break;
        front = rear - 1;
        while (front > 0) {
            v = q[front][0];
            front = q[front][1];
            u = q[front][0];
            edge[u][v] -= 1;
            edge[v][u] += 1;
        }
        maxFlow += 1;
        for (int i = 0; i < rear; i++)
            visited[q[i][0]] = false;
    } while (1);
}
int main() {
    //doc input
    scanf("%d",&test);
    for (int ti = 1; ti <= test; ti++) {
        init();
        scanf("%d%d",&n,&m);
        //doc thong tin items bob
        scanf("%d", &ni);
        for (int i = 0; i < ni; i++) {
            scanf("%d", &vi);
            edge[S][BOB_ITEMS + vi - 1] += 1;
        }
        for (int i = 0; i < m; i++) {
            edge[BOB_ITEMS + i][OTHERS_ITEMS + i] = edge[S][BOB_ITEMS + i];
            edge[OTHERS_ITEMS + i][BOB_ITEMS + i] = INF;
        }
        //doc thong tin items nhung nguoi khac
        for (int i = 1; i < n; i++) {
            scanf("%d", &ni);
            for (int j = 0; j < ni; j++) {
                scanf("%d",&vi);
                edge[PEOPLE + i - 1][OTHERS_ITEMS + vi - 1]++;
            }
            for (int j = 0; j < m; j++)
                if (edge[PEOPLE + i - 1][OTHERS_ITEMS + j] > 0) edge[PEOPLE + i - 1][OTHERS_ITEMS + j]--;
            else edge[BOB_ITEMS + j][PEOPLE + i - 1] = 1;
        }
        for (int i = 0; i < m; i++)
            edge[OTHERS_ITEMS + i][T] = 1;
        matching();
        printf("Case #%d: %d\n", ti, maxFlow);
    }
    return 0;
}

