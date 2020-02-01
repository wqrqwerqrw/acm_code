// Author : Wqr_
// Time : 2019年07月21日 星期日 13时49分06秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int n, all = 0;
struct stu {
  string name;
  int id;
  int money;
  int ps, bs, lnum;
  bool ifg, ifx;
  int setmoney() {
    money = 0;
    if (ps > 80 && lnum >= 1) money += 8000;
    if (ps > 85 && bs > 80) money += 4000;
    if (ps > 90) money += 2000;
    if (ps > 85 && ifx) money += 1000;
    if (ifg && bs > 80) money += 850;
    return money;
  }
} stus[100 + 10];
void input() {
  string name;
  char ifg_s, ifx_s;
  int ps, bs, lnum;
  bool ifg, ifx;
  for (int i = 0; i < n; i++) {
    cin >> name >> ps >> bs >> ifg_s >> ifx_s >> lnum;
    (ifg_s == 'Y') ? ifg = 1 : ifg = 0;
    (ifx_s == 'Y') ? ifx = 1 : ifx = 0;
    stus[i].id = i;
    stus[i].name = name;
    stus[i].ps = ps;
    stus[i].bs = bs;
    stus[i].lnum = lnum;
    stus[i].ifg = ifg;
    stus[i].ifx = ifx;
    all += stus[i].setmoney();
  }
}
int main() {
  iofuck;
  cin >> n;
  input();
  sort(stus, stus + n, [](stu &a, stu &b) {
    if (a.money == b.money)
      return a.id < b.id;
    else
      return a.money > b.money;
  });
  cout << stus[0].name << endl
       << stus[0].money << endl
       << all << endl;
  return 0;
}
