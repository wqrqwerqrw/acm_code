// Author : Wqr_
// Time : 2019年07月21日 星期日 18时56分18秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  vector<int> nums;
  string in;
  while (cin >> in) {
    if (in[0] == '.') break;
    if (in == "zero") nums.push_back(0);
    if (in == "one") nums.push_back(1);
    if (in == "two") nums.push_back(2);
    if (in == "three") nums.push_back(3);
    if (in == "four") nums.push_back(4);
    if (in == "five") nums.push_back(5);
    if (in == "six") nums.push_back(6);
    if (in == "seven") nums.push_back(7);
    if (in == "eight") nums.push_back(8);
    if (in == "nine") nums.push_back(9);
    if (in == "ten") nums.push_back(10);
    if (in == "eleven") nums.push_back(11);
    if (in == "twelve") nums.push_back(12);
    if (in == "thirteen") nums.push_back(13);
    if (in == "fourteen") nums.push_back(14);
    if (in == "fifteen") nums.push_back(15);
    if (in == "sixteen") nums.push_back(16);
    if (in == "seventeen") nums.push_back(17);
    if (in == "eighteen") nums.push_back(18);
    if (in == "nineteen") nums.push_back(19);
    if (in == "a") nums.push_back(1);
    if (in == "both") nums.push_back(2);
    if (in == "another") nums.push_back(1);
    if (in == "first") nums.push_back(1);
    if (in == "second") nums.push_back(2);
    if (in == "third") nums.push_back(3);
  }
  for (int i = 0; i < nums.size(); i++) nums[i] = (nums[i] * nums[i]) % 100;
  sort(nums.begin(), nums.end());
  bool beg = 1;
  if (!nums.size()) cout << 0;
  for (auto i: nums) {
    if (beg) {
      if (i == 0)
        continue;
      else
        cout << i, beg = 0;
    } else
      (i < 10) ? cout << '0' << i : cout << i;
  }
  return 0;
}
