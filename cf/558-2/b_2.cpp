/*************************************************************************
    > File Name: b_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月13日 星期一 17时25分14秒
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
typedef pair<int, int> pa;
int n;
int a[100100];
map<int, int> mapp;
map<int, int> ci;
bool cmp(pa ina, pa inb) {
  return ina.second > inb.second;
}
int main() {
  cin >> n;
  int ans = 0;
  int maxn = -1;
  int minn = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (mapp[a[i]] != 0) {
      ci[mapp[a[i]]]--;
    }
    mapp[a[i]]++;
    ci[mapp[a[i]]]++;
    if (ci.size() > 2) continue;
    if (ci.size() == 1) {
      if (mapp[a[i]] == 1) {
        ans = i;
        continue;
      }
    }
    map<int, int> mark;
    for ()
    /*
        if(minn == 1 && (maxn == 1 || ci[1] == 1)) {
            ans = i;
        }
        if(ci[maxn] == 1 && maxn - minn == 1) {
            ans = i;
        }
        */
  }
  cout << ans + 1 << endl;
  /*
    for(int i = n - 1; i >= 0; i--){
        map<int, int> ci;
        int maxn = -1;
        int minn = 0x3f3f3f3f;
        bool tocon = 0;
        for(auto kkk : mapp){
            if(!kkk.second) continue;
            ci[kkk.second]++;
            if(ci.size() > 2) {
                tocon = 1;
                break;
            }
            maxn = max(maxn, kkk.second);
            minn = min(minn, kkk.second);
        }
        if(tocon) {
            mapp[a[i]]--;
            continue;
        }
        if(minn == 1 && (maxn == 1 || ci[1] == 1)) {
            cout << i + 1 << endl;
            break;
        }
        if(ci[maxn] == 1 && maxn - minn == 1) {
            cout << i + 1 << endl;
            break;
        }
        mapp[a[i]]--;
    }
    */
  return 0;
}
