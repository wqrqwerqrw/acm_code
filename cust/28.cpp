/*************************************************************************
    > File Name: 28.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Oct 25 07:43:23 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int move(int now, int aim, int* guiJi, int* bushu) {
  *bushu++;
  guiJi[*bushu] = now;
  if (now > aim * 5) {
    return 0;
  }
  if (now == aim) {
    return 1;
  }
  move(now * 2, aim, guiJi, bushu);
  move(now * 10 + 1, aim, guiJi, bushu);
}
int main() {
  int now, aim;
  cin >> now >> aim;
  int guiJi[1000];
  guiJi[0] = now;
  int* bushu;
  *bushu = 0;
  int flag = move(now, aim, guiJi, bushu);
  if (flag) {
    cout << "YES" << endl;
    cout << *bushu;
    for (int i = 0; i < *bushu; i++) {
      if (i) cout << " ";
      cout << guiJi[i];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
