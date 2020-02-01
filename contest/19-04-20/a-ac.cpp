/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 13时27分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
  string in;
  while (getline(cin, in)) {
    for (int i = 0; i < in.length(); i++) {
      if (isalpha(in[i]))
        cout << (char)tolower(in[i]);
      else
        cout << (char)in[i];
    }
    cout << endl;
  }
  return 0;
}
