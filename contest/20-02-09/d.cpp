// Wqr_
// Time : 20/02/09
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct point{
  int x, y;
};
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int n, m;
    cin >> n >> m;
    bool flag = 0;
    if(n > m) swap(m, n), flag = 1;
    vector<point> ans; 
    vector<vector<int>> mp(n + 1, vector<int>(m + 1));
    auto vis = mp;
    vector<int> num(2);
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        mp[i][j] = (i + j) % 2;
      }
    }
    auto move0 = [&](int x, int y){
      int nn = n * m / 2;
      int tar = 1;
      while(nn--){
        ans.push_back({x, y});
        if(tar){
          if(x == m){
            x--;
            y++;
            tar = !tar;
          }else if(x == m - 1){
            x++;
            y++;
            tar = !tar;
          }else{
            x += 2;
          }
        }else{
          if(x == 1){
            x++;
            y++;
            tar = !tar;
          }else if(x == 2){
            x--;
            y++;
            tar = !tar;
          }else{
            x -= 2;
          }
        }
      }
    };
    move0(1, 1);
    int kase;
    auto e0 = ans.back();
    if(e0.x == 1) kase = 1;
    if(e0.x == 2) kase = 2;
    if(e0.x == m - 1) kase = 3;
    if(e0.x == m) kase = 4;
    auto mover = [&](int x, int y){

    };
    auto movel = [&](int x, int y){

    };
    function<void()> move[5];
    move[1] = [&](){
      int x = e0.x + 1, y = e0.y - 2;
      
      mover(x, y);
    };
    move[2] = [&](){
      int x = e0.x - 1, y = e0.y - 2;

      mover(x, y);
    };
    move[3] = [&](){
      int x = e0.x + 1, y = e0.y - 2;

      movel(x, y);
    };
    move[4] = [&](){
      int x = e0.x - 1, y = e0.y - 2;

      movel(x, y);
    };
    move[kase]();
    cout << "YES" << endl;
    for(auto i : ans){
      if(flag) cout << i.y << " " << i.x << endl;
      else cout << i.x<< " " << i.y << endl;
    }
  }
  return 0;
}