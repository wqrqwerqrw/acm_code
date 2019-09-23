// Author : Wqr_
// Time : 19/09/20
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define tttt cout << "<><><><><><><><><>" << endl;
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
tree<ll, null_type, less<ll>, splay_tree_tag, tree_order_statistics_node_update> bbt;
int n;
int main() {
    iofuck;
    bbt.insert(1000);
    bbt.insert(2000);
    bbt.insert(3000);
    bbt.insert(3000);
    bbt.insert(3000);
    bbt.insert(3000);
    bbt.insert(4000);
    bbt.insert(4000);
    for(auto v : bbt){
        cout << v << " ";
    }
    return 0;
}