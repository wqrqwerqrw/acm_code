// Author : Wqr_
// Time : 2019/9/8 8:43:18

#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 50 + 10;
string str[nmax];
bool book[nmax];
int maxans = -1;
vector<string> ansstr;
int n, l;
void dfs(string s) {
  if (s.length() >= l) {
    ansstr.push_back(s);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (book[i]) continue;
    if (*s.rbegin() == *str[i].begin()) {
      book[i] = 1;
      string tmp = str[i];
      tmp.erase(tmp.begin());
      //cout << "--" << str[i] << " "<< tmp << endl;
      dfs(s + tmp);
      book[i] = 0;
    }
  }
}
int main() {
  iofuck;
  while (cin >> n >> l) {
    memset(book, 0, sizeof(book));
    ansstr.clear();
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    for (int i = 0; i < n; i++) {
      book[i] = 1;
      dfs(str[i]);
      book[i] = 0;
    }
    sort(ansstr.begin(), ansstr.end());
    if (ansstr.size()) {
      cout << ansstr[0] << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
