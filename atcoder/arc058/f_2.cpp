#include <bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
vector<int> v[26];
string s[maxn];
int n, k;

int main() {
  #ifdef Wqr_
  freopen("in.txt","r",stdin);
  #endif
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    v[s[i][0] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      for (int k = 0; k < 26; k++) {
        for (int h = 0; h < v[k].size(); h++) {
          if(j == h) continue;
          if (v[i][j] + v[k][j] == k) cout << s[j] << s[h];
          break;
        }
      }
    }
  }
}
