#include <bits/stdc++.h>
using namespace std;
string run(int x, int i = 0, string s = string("")) {
  if (x == 0) return string("0");
  do
    if (x & 1) s = (i == 1 ? "2" : "2(" + run(i) + ")") + (s == "" ? "" : "+") + s;
  while (++i, x >>= 1);
  return s;
}
int main() {
  int x;
  cin >> x;
  cout << run(x) << endl;
}
