// Author : Wqr_
// Time : 19/09/24
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttt cout << "<><><>" << endl;
using namespace std;
typedef long long ll;
const int nmax = 32000 + 10, mmax = 60 + 5;
int n, m;
struct node{
    int v, p, q;
};
vector<node> ns(nmax);
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> ns[i].v >> ns[i].p >> ns[i].q;
        ns[i].p *= ns[i].v;
    }
    return 0;
}