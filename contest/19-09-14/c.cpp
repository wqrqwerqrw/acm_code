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
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    printf("Case %d: ", kase);
    cin >> n;
    fill(ans, ans + n, 0);
    ll maxk = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", k + i);
      maxk = max(maxk, k[i]);
    }
    for (int i = 0; i < n; i++) {
      k[i] = maxk - k[i];
    }
    int to = maxk - 1;
    sort(k, k + n);
    //第一遍
    int now = k[0];
    int tmp;
    ans[0] = 1;
    bool flag1 = 0;
    if (now >= to) {
      flag1 = 1;
    } else {
      for (int i = 1; i < n; i++) {
        //currect
        if (now >= to) {
          flag1 = 1;
          break;
        }

        //currect
        if (k[i] == now) {
          now = k[i] + 1;
          ans[i] = 1;
        }
        if (k[i] > now) {
          now = k[i];
          ans[i] = 1;
        }
      }
    }
    if (flag1) {
      // 第二遍
      int nowwz;
      for (int i = 1; i < n; i++) {
        if (!ans[i]) {
          now = k[i];
          nowwz = i;
          break;
        }
      }
      bool flag2 = 0;
      if (now >= to) {
        flag2 = 1;
      } else {
        for (int i = nowwz + 1; i < n; i++) {
          if (now >= to) {
            flag2 = 1;
            break;
          }
          if (k[i] == now) {
            now = k[i] + 1;
          }
          if (k[i] > now) {
            now = k[i];
          }
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
        continue;
      }
    } else {
      cout << "NO" << endl;
      continue;
    }
  }
  return 0;
}