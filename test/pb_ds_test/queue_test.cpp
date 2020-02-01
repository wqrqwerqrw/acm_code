// Author : Wqr_
// Time : 19/09/20
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>  //用priority_queue
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> Q;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  Q.push(1);
  cout << Q.top() << endl;
  return 0;
}