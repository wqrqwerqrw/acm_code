// Author : Wqr_
// Time : 19/09/13
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 10e6 + 100;
string a, b;
int n;
int nxt[nmax][30];
int now[nmax];
bool init() {
  memset(now, -1, sizeof(now));
  //memset(nxt, -1, sizeof(nxt));
  for (int i = a.length() - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      nxt[i][j] = now[j];
    }
    now[a[i] - 'a'] = i;
  }
  /*
    for(int i = 0; i < a.length(); i++){
        cout << nxt[i]['a' - 'a'] << " ";
    }
    cout << endl;
    for(int i = 0; i < a.length(); i++){
        cout << now[i] << " ";
    }
    cout << endl;
    */
}
void solve() {
  bool flag = 1;
  int wz = 0;
  wz = now[b[0] - 'a'];
  if (wz < 0) {
    cout << "No" << endl;
    return;
  }
  for (int i = 1; i < b.length(); i++) {
    int c = b[i] - 'a';
    wz = nxt[wz][c];
    if (wz < 0) {
      flag = 0;
      break;
    }
  }
  /*
    for (auto ch : b) {
        int c = ch - 'a';
        wz = nxt[wz][c] + 1;
        if(wz <= 0){
            flag = 0;
            break;
        }
    }
    */
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  iofuck;
  cin >> a;
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    cin >> b;
    solve();
  }
  return 0;
}
