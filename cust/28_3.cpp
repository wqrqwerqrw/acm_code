/*************************************************************************
    > File Name: 28_3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Oct 25 10:21:12 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool flag(int now, int aim, int* step, int* arr) {
  int n = 0;
  do {
    if (aim % 10 == 1) {
      arr[n] = aim;
      aim = (aim - 1) / 10;
      n++;
    } else if (aim % 2 == 0) {
      arr[n] = aim;
      aim /= 2;
      n++;
    } else {
      return false;
    }
  } while (aim > now);
  *step = n;
  if (aim == now) {
    return true;
  }
  return false;
}
int main() {
  int now, aim;
  while (cin >> now >> aim) {
    int arr[1000];
    int* step;
    step = new int;
    *step = 0;
    if (flag(now, aim, step, arr)) {
      cout << "YES" << endl;
      int n = *step;
      cout << n + 1 << endl;
      cout << now;
      for (int i = n - 1; i >= 0; i--) {
        if (i != *step) cout << " ";
        if (arr[i] == 0) continue;
        cout << arr[i];
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
    delete step;
    cout << endl;
  }
  return 0;
}
