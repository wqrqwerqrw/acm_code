/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 14时43分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
  char in[1000100];
  while (scanf("%s", in) != EOF) {
    for (int i = 0; i < strlen(in); i++) {
      if (in[i] == 'z')
        printf("a");
      else {
        printf("%c", (char)((int)in[i] + 1));
      }
    }
    cout << endl;
  }
  return 0;
}
