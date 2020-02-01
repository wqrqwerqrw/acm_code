/*************************************************************************
    > File Name: 47.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 26 14:16:35 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string in;
    while (cin >> in) {
      for (int i = 0; i < in.size(); i++) {
        if (in[i] >= 'a' && in[i] <= 'c') cout << 2;
        if (in[i] >= 'd' && in[i] <= 'f') cout << 3;
        if (in[i] >= 'g' && in[i] <= 'i') cout << 4;
        if (in[i] >= 'j' && in[i] <= 'l') cout << 5;
        if (in[i] >= 'm' && in[i] <= 'o') cout << 6;
        if (in[i] >= 'p' && in[i] <= 's') cout << 7;
        if (in[i] >= 't' && in[i] <= 'v') cout << 8;
        if (in[i] >= 'w' && in[i] <= 'z') cout << 9;
      }
      cout << endl;
    }
    return 0;
  }
}
