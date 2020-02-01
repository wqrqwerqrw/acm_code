/*************************************************************************
    > File Name: 120.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 28 17:40:18 2018
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int in[n];
    int fu[n];
    bool flag = false;
    for (int i = 0; i < n; i++) {
      in[i] = 0;
      fu[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cin >> in[i];
      if (in[i] >= 0) flag = true;
      if (in[i] < 0) {
        fu[i] = in[i];
        in[i] = 1001;
      }
    }
    sort(fu, fu + n);
    sort(in, in + n);
    if (flag) {
      for (int i = n - 1; i >= 0; i--) {
        if (fu[i] == 0) continue;
        cout << fu[i];
        cout << " ";
      }
    } else {
      for (int i = n - 1; i >= 0; i--) {
        cout << fu[i];
        if (i != 0) cout << " ";
      }
    }
    for (int i = 0; in[i] != 1001 && i < n; i++) {
      if (i != 0) cout << " ";
      cout << in[i];
    }
    cout << endl;
  }
  return 0;
}
