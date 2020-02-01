// Author : Wqr_
// Time : 2019年06月10日 星期一 21时06分40秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map<int, int> men;
bool ifmen[100000 + 5];
bool book[200000 + 5];
struct node {
  int now, men, time;
};
bool cmp(node &a, node &b) {
  return a.men < b.men;
}
vector<node> ans;
int n, m, k;
void bfs() {
  queue<node> q;
  q.push(node{0, 0, 0});
  book[0] = 1;
  while (!q.empty()) {
    node tmp = q.front();
    q.pop();
    //cout << tmp.now << endl;
    if (tmp.time > k + 1) continue;
    if (tmp.now > 2 * n) continue;
    if (tmp.now == n) ans.push_back(tmp);
    if (ifmen[tmp.now] && !book[men[tmp.now]]) {
      q.push(node{men[tmp.now], tmp.men + 1, tmp.time});
      //book[men[tmp.now]] = 1;
    }
    for (int tx = -1; tx <= 1; tx++) {
      if (tx == 0) continue;
      int nx = tmp.now + tx;
      if (nx < 0) continue;
      if (!book[nx]) {
        q.push(node{nx, tmp.men, tmp.time + 1});
        book[nx] = 1;
      }
    }
  }
  if (ans.size()) {
    sort(ans.begin(), ans.end(), cmp);
    for (auto tmp: ans) {
      cout << tmp.men << " " << tmp.time << endl;
    }
    cout << ans[0].men << " " << ans[0].time << endl;
  } else {
    cout << "summon TanYz" << endl;
  }
}
int main() {
  iofuck;
  while (cin >> n >> m >> k) {
    memset(ifmen, 0, sizeof(ifmen));
    memset(book, 0, sizeof(book));
    men.clear();
    ans.clear();
    int a, b;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      men[a] = b;
      men[b] = a;
      ifmen[a] = 1;
      ifmen[b] = 1;
    }
    bfs();
  }
  return 0;
}
