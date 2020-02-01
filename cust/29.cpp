/*************************************************************************
    > File Name: 29.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 26 14:34:29 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int kase = 0;
  int n;
  while (cin >> n) {
    kase++;
    cout << "Case #" << kase << ":"
         << endl;
    string s;
    cin >> s;
    bool flag[s.size()];
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '0')
        flag[i] = true;
      else
        flag[i] = false;
    int meizi = 0;
    int dalao = 0;
    int bushu;
    cout << 0 << " " << 0 << endl;
    for (int i = 0; i < s.size(); i++) {
      cin >> bushu;
      if (flag[i])
        meizi += bushu;
      else
        dalao++;
      if (dalao >= n) dalao = n;
      if (meizi >= n) meizi = n;
      cout << meizi << " " << dalao << endl;
    }
    if (dalao >= n || meizi >= n)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    cout << endl;
  }
  return 0;
}
