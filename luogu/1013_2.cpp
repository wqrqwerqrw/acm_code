// Author : Wqr_
// Time : 2019/9/2 20:23:12

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 11;
string ss[nmax][nmax];
map<int, char> hor, ver;
int main() {
  int n;
  cin >> n;
  bool iferror = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ss[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    int wei_hor = 0, wei_ver = 0;
    for (int j = 1; j < n; j++) {
      if (ss[i][j].size() == 2) wei_hor++;
      if (ss[j][i].size() == 2) wei_ver++;
    }
    if (hor.find(wei_hor) != hor.end())
      iferror = 1;
    else
      hor[wei_hor] = ss[i][0][0];
    if (ver.find(wei_ver) != ver.end())
      iferror = 1;
    else
      ver[wei_ver] = ss[0][i][0];
  }

  // hor == ver?
  for (int i = 0; i < n - 1; i++)
    if (hor[i] != ver[i]) iferror = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ss[i][j].size() == 2 && ss[i][j][0] != hor[1]) {
        iferror = 1;
      }
      if (iferror) break;
    }
    if (iferror) break;
  }
  if (iferror) {
    cout << "ERROR!" << endl;
    return 0;
  } else {
    for (int i = 0; i < n - 1; i++) {
      if (i) cout << " ";
      cout << hor[i] << "=" << i;
    }
    cout << endl
         << n - 1 << endl;
  }
  return 0;
}
