// Author : Wqr_
// Time : 19/09/28
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
const int nmax = 5e5 + 500;
struct rec{
    int x1, y1, x2, y2, col, vis;
    rec(){col = vis = 0;}
}rs[nmax];
vector<int> G[nmax];
int n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        rec& cur = rs[i];
        cin >> cur.x1 >> cur.y1 >> cur.x2 >> cur.y2;
    }
    return 0;
}