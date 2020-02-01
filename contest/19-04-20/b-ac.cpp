/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 13时33分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  getchar();
  while (n--) {
    string in;
    getline(cin, in);
    for (int i = in.length() - 1; i >= 0; i--) {
      cout << in[i];
    }
    cout << endl;
  }
  return 0;
}
