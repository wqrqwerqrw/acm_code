#include <bits/stdc++.h>
using namespace std;
struct team{
  string name;
  int solve;
  int time;
};
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int n, d;
    cin >> n >> d;
    vector<team> ts(n); 
    for(int i = 0; i < n; i++){
      cin >> ts[i].name >> ts[i].solve >> ts[i].time;
    }
    if(n * d % 10 != 5){
      cout << "Quailty is very great" << "\n";
      continue;
    }
    sort(ts.begin(), ts.end(), [](const team& a, const team& b){
      if(a.solve == b.solve){
        return a.time < b.time;
      }else {
        return a.solve > b.solve;
      }
    });
    cout << ts[n * d / 10].name << "\n";
  }
  return 0;
}