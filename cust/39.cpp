/*************************************************************************
    > File Name: 39.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 26 09:57:54 2018
 ************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    bool flag = false;
    long long int num_z = 0;
    cin >> s;
    if (s[s.size() - 1] == '0') flag = true;
    if (flag) {
      for (int i = s.size() - 1;; i--) {
        if (s[i] != '0') break;
        num_z++;
      }
    }
    long long int zheng = 0;
    long long int dao = 0;
    for (int i = 0; i < s.size(); i++) {
      zheng += (s[i] - '0') * pow(10, s.size() - 1 - i);
    }
    for (int i = 0; i < s.size() - num_z; i++) {
      dao += (s[i] - '0') * pow(10, i);
    }
    if (zheng == dao) cout << "mdzz" << endl;
    if (zheng > dao) cout << "heiheihei" << endl;
    if (zheng < dao) cout << "papapa" << endl;
  }
}
