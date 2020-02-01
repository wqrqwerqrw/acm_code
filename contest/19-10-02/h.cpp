// Author : Wqr_
// Time : 19/10/02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
int a, b;
bool cur(int in) {
  int tmp = in;
  vi wei;
  vi nums(10, 0);
  while (tmp) {
    wei.push_back(tmp % 10);
    tmp /= 10;
  }
  //no 0
  for (auto i: wei) {
    nums[i]++;
    if (nums[i] > 1) return false;
  }
  if (nums[0]) return false;
  for (auto i: wei) {
    if (in % i != 0) return false;
  }
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (cur(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}