/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/07
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int ka[3][3];
int kb[3][3];
int mapp[3][3];
pii zhi(int i, int j) {
  pii ret;
  int reti, retj;
  if (mapp[i][j] == 1) { reti = i - 1, retj = j - 1; }
  if (mapp[i][j] == 2) { reti = i - 1, retj = j; }
  if (mapp[i][j] == 3) { reti = i - 1, retj = j + 1; }
  if (mapp[i][j] == 4) { reti = i, retj = j - 1; }
  if (mapp[i][j] == 6) { reti = i, retj = j + 1; }
  if (mapp[i][j] == 7) { reti = i + 1, retj = j - 1; }
  if (mapp[i][j] == 8) { reti = i + 1, retj = j; }
  if (mapp[i][j] == 9) { reti = i + 1, retj = j + 1; }
  ret.first = reti;
  ret.second = retj;
  return ret;
}
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    memset(ka, 0, sizeof(ka));
    memset(kb, 0, sizeof(kb));
    pii ansa, ansb;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> mapp[i][j];
        if (mapp[i][j] != 5)
          ka[zhi(i, j).first][zhi(i, j).second]++;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (mapp[i][j] != 5) {
          kb[i][j] = ka[zhi(i, j).first][zhi(i, j).second];
        } else {
          kb[i][j] = 9;
        }
      }
    }
    int maxa = -1;
    int minb = 1000000;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (ka[i][j] > maxa) {
          maxa = ka[i][j];
          ansa.first = i + 1;
          ansa.second = j + 1;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((i + 1) == ansa.first && (j + 1) == ansa.second) {
          continue;
        }
        if (kb[i][j] < minb) {
          minb = kb[i][j];
          ansb.first = i + 1;
          ansb.second = j + 1;
        }
      }
    }
    /*
        cout << "-----------" << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << ka[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------" << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << kb[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------" << endl;
        */
    cout << ansa.first << " ";
    cout << ansa.second << " ";
    cout << ansb.first << " ";
    cout << ansb.second << endl;
  }
  return 0;
}