/*************************************************************************
  > File Name: 32_2.cpp
  > Author: Wqr_
  > Mail: xueduanwei@126.com 
  > Created Time: Wed Sep 26 15:58:02 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int in1 = 0, in2 = 0;
    char f = 0;
    bool flag = false;
    scanf("%d", &in1);
    for (;;) {
      f = getchar();
      if (f == '\n') break;
      scanf("%d", &in2);
      switch (f) {
        case '+':
          in1 += in2;
          break;
        case '-':
          in1 -= in2;
          break;
        case '*':
          in1 *= in2;
          break;
        case '/':
          in1 /= in2;
          break;
      }
    }
    cout << in1 << endl;
  }
  return 0;
}
