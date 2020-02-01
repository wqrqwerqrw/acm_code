#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int base[N];
int n, k, a, b;

typedef pair<int, int> pii;
set<pii> s;
vector<int> v;

int check(int l, int r) {
  int l1 = lower_bound(base + 1, base + 1 + k, l) - base;
  int r2 = upper_bound(base + 1, base + 1 + k, r) - base;
  int sum = 0;
  if (l1 == k + 1)
    sum = 0;
  else {
    if (r2 == k + 1)
      sum = k - l1 + 1;
    else {
      sum = r2 - l1;
    }
  }
  return sum;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> a >> b;
  int len = (1 << n);
  for (int i = 1; i <= k; i++) {
    cin >> base[i];
  }
  sort(base + 1, base + 1 + k);
  int ans = 0;
  if (a <= b) {
    for (int i = 1; i <= k; i++) {
      int l = 1, r = len;
      while (l <= r) {
        cout << "=====" << l << "   " << r << endl;
        int mid = (l + r) >> 1;
        if (mid < base[i]) {
          s.emplace(l, mid);
          l = mid + 1;
        } else {
          s.emplace(mid + 1, r);
          r = mid - 1;
        }
      }
    }
    //cout<<"1====="<<endl;
    cout << k * b + a * (s.size() - k);
    return 0;
  } else {
    int l = 1, r = len;
    s.emplace(1, len);
    while (!s.empty()) {
      //cout<<"ttt"<<endl;
      pii tmp = *s.begin();
      s.erase(tmp);
      int l = tmp.first, r = tmp.second, mid = (l + r) >> 1;
      int sum = check(l, r);
      if (l == r) {
        if (sum)
          ans += b * sum;
        else
          ans += a;
        continue;
      }
      int cost;
      if (sum == 0) {
        ans += a;
        continue;
      } else
        cost = (r - l + 1) * b * sum;
      int cost1, cost2;
      int cnt1 = check(l, mid);
      int cnt2 = check(mid + 1, r);
      if (!cnt1)
        cost1 = a;
      else
        cost1 = cnt1 * (mid - l + 1) * b;
      if (!cnt2)
        cost2 = a;
      else
        cost2 = cnt2 * (r - mid) * b;
      if (cnt1 + cnt2 == l - r + 1) {
        s.emplace(l, mid);
        s.emplace(mid + 1, r);
      } else {
        if ((cnt1 == 0 || cnt2 == 0) && cost < a)
          ans += cost;
        else {
          s.emplace(l, mid);
          s.emplace(mid + 1, r);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}