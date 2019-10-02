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
const int nmax = 1e5 + 10;
int n;
int a[nmax];
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1){
            bbt.insert(a[i] << 20);
            cout << -1 << endl;
            continue;
        }
        int cnt = (*bbt.rbegin() >> 20);
        if(cnt < a[i]) cout << -1 << endl;
        else cout << cnt << endl;
        bbt.insert(a[i] << 20);
    }
    return 0;
}
