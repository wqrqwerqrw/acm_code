#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5 + 5;

struct node {
  int i, j;
};
vector<node> ans;
int a[N], pos[N];

void swp(int i, int j) {
  ans.push_back((node){i, j});
  swap(pos[a[i]], pos[a[j]]);
  swap(a[i], a[j]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
  for (int i = 2; i < n; i++) {
    if (a[i] == i) continue;
    int p = pos[i];
    if (abs(p - i) >= n / 2) {
      sum++;
      swp(i, p);
    } else {
      if (i <= n / 2 && p <= n / 2) {
        sum += 2;
        swp(p, n);
        swp(i, n);
      } else if (i <= n / 2 && p > n / 2) {
        swp(1, p);
        swp(1, n);
        swp(i, n);
        sum += 3;
      } else {
        swp(1, p);
        swp(1, i);
        sum += 2;
      }
    }
  }
  if (a[1] != 1) swp(1, n), sum++;
  cout << sum << endl;
  for (int i = 0; i < sum; i++) cout << ans[i].i << " " << ans[i].j << endl;
}
