/*************************************************************************
    > File Name: 45.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 25 19:37:29 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int in;
    int num = 0;
    bool ifz = false;
    for (int i = 0; i < n; i++) {
      cin >> in;
      if (in == 300) num++;
      if (in == 0) ifz = true;
    }
    float per = (float)num / n;
    bool flag = false;
    if ((per >= 0.89999) || (per > 0.8 && (ifz != true))) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
