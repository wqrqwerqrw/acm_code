//dijkstra------407ms
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#define inf 99999999
using namespace std;
const int MAX = 1000 + 10;
int map[MAX][MAX], dis[MAX], book[MAX];
void dijkstra(int n) {
  int i, j, max, t;
  for (i = 1; i <= n; i++) {
    dis[i] = map[1][i];
    book[i] = 0;
  }
  dis[1] = 0;
  for (i = 1; i <= n; i++) {
    max = -1;
    for (j = 1; j <= n; j++)
      if (book[j] != 1 && dis[j] > max) {
        max = dis[j];
        t = j;
      }
    book[t] = 1;
    for (j = 1; j <= n; j++)
      if (book[j] != 1 && dis[j] < min(dis[t], map[t][j]))
        dis[j] = min(dis[t], map[t][j]);
  }
}
int main() {
  //freopen("in.in","r",stdin);
  int t, i, k, n, m, u, v, w;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    memset(map, 0, sizeof(map));
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      map[u][v] = map[v][u] = w;
    }
    dijkstra(n);
    for (int i = 0; i < n; i++) {
      cout << dis[i] << " ";
    }
    cout << endl;
    printf("Scenario #%d:\n", k);
    printf("%d\n\n", dis[n]);
  }
  return 0;
}