// Author : Wqr_
// Time : 19/09/23
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
typedef vector<int> tree;
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    int ans = 0;
    int in;
    tree tr;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(!i){
            ans += in;
            tr.insert(upper_bound(tr.begin(), tr.end(), in), in);
            continue;
        }
        tree::iterator it = upper_bound(tr.begin(), tr.end(), in);
        tree::iterator itl = it, itr = it;
        itl--;
        int a = *itl, b = *itr;
        if(it == tr.begin()) ans += abs(in-b);
        else if(it == tr.end()) ans += abs(in-a);
        else ans += min(abs(in-a), abs(in-b));
        tr.insert(it, in);
    }
    cout << ans << endl;
    return 0;
}