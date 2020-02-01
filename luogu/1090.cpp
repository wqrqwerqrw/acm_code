// Author : Wqr_
// Time : 2019年08月27日 星期二 18时33分05秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int n;
int main() {
  int ans = 0;
  cin >> n;
  priority_queue<int, vector<int>, greater<int> > q;
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    q.push(in);
  }
  while (q.size() != 1) {
    int a, b, tmp;
    a = q.top(), q.pop();
    b = q.top(), q.pop();
    tmp = a + b;
    q.push(tmp);
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
