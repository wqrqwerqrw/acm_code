/*************************************************************************
    > File Name: g.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 14时49分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string a[110];
string b[110];
typedef pair<string, string> pai;
int n;
pai str[110];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str[i].second >> str[i].first;
    str[i].first[0] = tolower(str[i].first[0]);
    str[i].second[0] = tolower(str[i].second[0]);
  }
  sort(str, str + n);
  for (int i = 0; i < n; i++) {
    str[i].first[0] = toupper(str[i].first[0]);
    str[i].second[0] = toupper(str[i].second[0]);
  }
  for (int i = 0; i < n; i++) {
    cout << str[i].second << " " << str[i].first << endl;
  }
  return 0;
}
