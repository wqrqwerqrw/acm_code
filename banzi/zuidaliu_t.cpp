#include <bits/stdc++.h>
#define int long long
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mem0(a) memset((a), 0, sizeof(a))
#define mem(a, b) memset((a), (b), sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const int maxn = 35;

int aa[maxn];
char g[maxn][maxn];

const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;
struct Edge {
  int to, next, cap, flow, cost;
} e[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;
void init(int n) {
  N = n;
  tol = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost) {
  e[tol].to = v;
  e[tol].cap = cap;
  e[tol].cost = cost;
  e[tol].flow = 0;
  e[tol].next = head[u];
  head[u] = tol++;
  e[tol].to = u;
  e[tol].cap = 0;
  e[tol].cost = -cost;
  e[tol].flow = 0;
  e[tol].next = head[v];
  head[v] = tol++;
}
bool spfa(int s, int t) {
  queue<int> q;
  for (int i = 0; i < N; i++) {
    dis[i] = inf;
    vis[i] = false;
    pre[i] = -1;
  }
  dis[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = e[i].next) {
      int v = e[i].to;
      if (e[i].cap > e[i].flow && dis[v] > dis[u] + e[i].cost) {
        dis[v] = dis[u] + e[i].cost;
        pre[v] = i;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  return pre[t] != -1;
}

int minCostMaxflow(int s, int t, int &cost) {
  int flow = 0;
  cost = 0;
  while (spfa(s, t)) {
    int Min = inf;
    for (int i = pre[t]; i != -1; i = pre[e[i ^ 1].to]) {
      if (Min > e[i].cap - e[i].flow)
        Min = e[i].cap - e[i].flow;
    }
    for (int i = pre[t]; i != -1; i = pre[e[i ^ 1].to]) {
      e[i].flow += Min;
      e[i ^ 1].flow -= Min;
      cost += e[i].cost * Min;
    }
    flow += Min;
  }
  return flow;
}

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int32_t main() {
  IOS;
  int n, m, c;
  cin >> m >> n >> c;
  init(2 * (n * m) + 2);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  for (int i = 0; i < c; i++) {
    cin >> aa[i];
  }
  int s = 0, t = 2 * (n * m) + 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = i + 1, jj = j + 1;
      int pos1 = (ii - 1) * m + jj, pos2 = pos1 + m * n;
      if (g[i][j] == '.' || g[i][j] == 'B') {
        addedge(pos1, pos2, inf, 0);
      } else {
        addedge(pos1, pos2, aa[g[i][j] - 'a'], 0);
      }
    }
  }
  int tt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = i + 1, jj = j + 1;
      int pos1 = (ii - 1) * m + jj, pos2 = pos1 + m * n;
      if (g[i][j] == 'B') tt = pos1;
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        addedge(pos2, t, inf, 0);
      } else
        for (int z = 0; z < 4; z++) {
          int xx = ii + dx[z], yy = jj + dy[z];
          int pp = (xx - 1) * m + yy;
          if (xx >= 1 && xx <= n && jj >= 1 && jj <= m) {
            addedge(pos2, pp, inf, 0);
          }
        }
    }
  }
  addedge(s, tt, inf, 0);
  int co;
  int as = minCostMaxflow(s, t, co);
  if (as >= inf)
    cout << -1;
  else
    cout << as;
  return 0;
}
