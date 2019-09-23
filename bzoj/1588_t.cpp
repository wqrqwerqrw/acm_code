// Author : Wqr_
// Time : 19/09/20
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define tttt cout << "<><><><><><><><><>" << endl;
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> bbt;
int n;
int main() {
    iofuck;
    bbt.insert((100 << 20) + 1);
    bbt.insert((200 << 20) + 2);
    bbt.insert((300 << 20) + 3);
    bbt.insert((400 << 20) + 4);
    for(auto v : bbt){
        cout << (v >> 20) << " ";
    }
    tttt
    auto itl = bbt.lower_bound((150 << 20));
    auto itr = bbt.upper_bound((50 << 20));
    cout << (*itl >> 20) << endl;
    cout << (*itr >> 20) << endl;
    return 0;
}