// Wqr_
// Time : 20/02/10
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  auto perfix = a, suffix = a;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  perfix[1] = ~a[1];
  suffix[n] = ~a[n];
  for(int i = 2; i <= n; i++){
    perfix[i] = perfix[i - 1] & (~a[i]);
  }
  for(int i = n - 1; i >= 1; i--){
    suffix[i] = suffix[i + 1] & (~a[i]);
  }
  int maxn = -1e9;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int tmp;
    if(i == 1) tmp = a[i] & suffix[i + 1];
    else if(i == n) tmp = a[i] & perfix[i - 1];
    else tmp = perfix[i-1] & suffix[i+1] & a[i];
    if(tmp > maxn){
      maxn = tmp;
      ans = i;
    }
  }
  cout << a[ans] << " ";
  for(int i = 1; i <= n; i++){
    if(i == ans) continue;
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}