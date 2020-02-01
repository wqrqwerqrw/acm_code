// Author : Wqr_
// Time : 2019年07月19日 星期五 19时13分41秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<char, bool> mapp;
    stack<int> s_n;
    stack<int> s_b;
    int l;
    char o[50];
    int w;
    bool ife = 0;
    bool ifb = 0;
    int ans = 0;
    scanf("%d %s", &l, o);
    if (o[2] == '1')
      w = 0;
    else
      sscanf(&o[3], "%d", &w);
    char in;
    char a, b, c;
    for (int i = 0; i < l; i++) {
      cin >> in;
      if (in == 'F') {
        cin >> a >> b >> c;
        if (mapp[a]) {
          ife = 1;
        }
        mapp[a] = 1;
        if (b == 'n' && c == 'n') ifb ? s_b.push(0) : s_n.push(0);
        if (b == 'n' && isdigit(c)) ifb = 1;
        if (isdigit(b) && c == 'n') ifb ? s_b.push(1) : s_n.push(1);
        if (isdigit(b) && isdigit(c)) {
          int b_int = b - '0';
          int c_int = c - '0';
          if (b_int > c_int) ifb = 1;
          if (b_int <= c_int) ifb ? s_b.push(0) : s_n.push(0);
        }
      }
      if (in == 'E') {
        if (!s_b.empty()) {
          s_b.pop();
        } else if (!s_n.empty()) {
          ans += s_n.top();
          s_n.pop();
        } else {
          ife = 1;
        }
      }
    }
    //printf("%d---%d\n", ans, w);
    if (ife || !s_n.empty() || !s_b.empty())
      printf("ERR\n");
    else
      (ans == w) ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}
