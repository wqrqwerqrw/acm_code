// Author : Wqr_
// Time : 19/09/14
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
ll n, k[nmax], ans[nmax];
bool iff;
struct w {
  ll val, pos;
} wk[nmax];
stack<w> a;
stack<int> b;
stack<w> c, ctmp;
void sync() {
  int tmp = b.top();
  b.pop();
  while (!b.empty() && tmp == b.top()) {
    tmp++;
    b.pop();
  }
  b.push(tmp);
  //cout << "----->" << b.top() << endl;
}
void init() {
  while (!a.empty()) a.pop();
  while (!b.empty()) b.pop();
  while (!c.empty()) c.pop();
  while (!ctmp.empty()) ctmp.pop();
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    init();
    printf("Case %d: ", kase);
    cin >> n;
    fill(ans, ans + n, 0);
    ll maxk = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", k + i);
      maxk = max(maxk, k[i]);
    }
    for (int i = 0; i < n; i++) {
      wk[i].val = maxk - k[i];
      wk[i].pos = i;
    }
    int to = maxk - 1;
    sort(wk, wk + n, [](w &in1, w &in2) { return in1.val < in2.val; });
    for (int i = n - 1; i >= 0; i--) {
      //cout << wk[i].val << "--" << wk[i].pos << endl;
      a.push(wk[i]);
    }
    ////////////////////////////////////////////////
    bool flag1 = 0;
    while (!a.empty()) {
      w tmp = a.top();
      a.pop();
      if (b.empty() || tmp.val >= b.top() - 1) {
        ans[tmp.pos] = 1;
        b.push(tmp.val);
        sync();
      } else {
        ctmp.push(tmp);
      }
      if (b.top() >= to) {
        flag1 = 1;
        break;
      }
    }
    while (!a.empty()) {
      ctmp.push(a.top());
      a.pop();
    }
    //cout << "1over" << endl;
    if (flag1) {
      while (!b.empty()) b.pop();
      while (!ctmp.empty()) {
        w tmp = ctmp.top();
        ctmp.pop();
        c.push(tmp);
        //cout << c.top().val << endl;
      }
      bool flag2 = 0;
      while (!c.empty()) {
        w tmp = c.top();
        c.pop();
        if (b.empty() || tmp.val >= b.top() - 1) {
          b.push(tmp.val);
          sync();
        }
        if (b.top() >= to) {
          flag2 = 1;
          break;
        }
      }
      if (flag2) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
          cout << ans[i];
        }
        cout << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
      continue;
    }
  }
  return 0;
}