// Author : Wqr_
// Time : 2019年07月21日 星期日 10时50分32秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int p1, p2, p3;
void pr(char in) {
  for (int i = 0; i < p2; i++) {
    switch (p1) {
      case 1:
        cout << (char)tolower(in);
        break;
      case 2:
        cout << (char)toupper(in);
        break;
      case 3:
        cout << "*";
        break;
    }
  }
}
void tian(char a, char b) {
  if ((int)a >= (int)b) {
    cout << "-";
    return;
  }
  if (p3 == 1) {
    for (int i = a + 1; i < b; i++) pr((char)i);
  } else {
    for (int i = b - 1; i > a; i--) pr((char)i);
  }
}
auto pan = [](char a, char b) -> bool {
  if (isalpha(a) && isalpha(b)) return 1;
  if (isdigit(a) && isdigit(b)) return 1;
  return 0;
};
int main() {
  cin >> p1 >> p2 >> p3;
  string in;
  cin >> in;
  for (int i = 0; i < in.length(); i++) {
    if (in[i] == '-' && pan(in[i - 1], in[i + 1]))
      tian(in[i - 1], in[i + 1]);
    else
      cout << in[i];
  }
  return 0;
}
