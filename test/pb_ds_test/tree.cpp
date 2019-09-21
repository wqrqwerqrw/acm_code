// Author : Wqr_
// Time : 19/09/20
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bbt;
int n;
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    ll opt, k, ans;
    for(int i = 1; i <= n; i++){
        cin >> opt >> k;
        if(opt==1) bbt.insert((k<<20)+i);
        if(opt==2) bbt.erase(bbt.lower_bound(k<<20));
        if(opt==3) {
            cout << bbt.order_of_key(k << 20) + 1 << endl;
        }
        if(opt == 4){
            ans = *bbt.find_by_order(k-1);
            cout << (ans >> 20) << endl;
        }
        if(opt == 5){
            ans = *--bbt.lower_bound(k<<20);
            cout << (ans >> 20) << endl;
        }
        if(opt == 6){
            ans = *bbt.upper_bound((k<<20) + n);
            cout << (ans >> 20) << endl;
        }
    }
    return 0;
}
