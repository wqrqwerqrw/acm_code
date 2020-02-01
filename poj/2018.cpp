/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/10
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
double esp = 1e-5;
const int nmax = 1e5 + 50;
int n, l;
double a[nmax], b[nmax], s[nmax];
bool C(double cur) {
  for (int i = 0; i < n; i++) {
    b[i] = a[i] - cur;
    s[i] = (i == 0 ? b[i] : s[i - 1] + b[i]);
  }
  double minval = 1e10;
  for (int i = l - 1; i < n; i++) {
    minval = min(minval, s[i - l]);
    //cout << "#" << minval << endl;
    if (s[i] - minval + esp > 0) return true;
  }
  return false;
}
int main() {
  freopen("in.txt", "r", stdin);
  //std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
  double mid, lb = 0, ub = 2000.00;
  for (int i = 0; i < 100; i++) {
    mid = (lb + ub) / 2;
    if (C(mid))
      lb = mid;
    else
      ub = mid;
  }
  printf("%d\n", int(ub * 1000));
  return 0;
}