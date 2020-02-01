/*************************************************************************
    > File Name: i.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 16时04分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int a[3];
int b[3];
int main() {
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  sort(a, a + 3);
  sort(b, b + 3);
  if (a[0] * a[0] + a[1] * a[1] != a[2] * a[2]) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (a[i] != b[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
