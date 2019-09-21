// Author : Wqr_
// Time : 19/09/20
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 6e5 + 10;
struct node{
    int l, r, id, bl;
}ns[nmax];
int n, m, a[nmax], ans[nmax], cnt[1000000 + 100], block;
int ret = 0;
bool cmp(node& a, node& b) {
    return (a.bl ^ b.bl) ? a.l < b.l : (((a.bl) & 1) ? a.r < b.r : a.r > b.r);
    /*
    if(a.bl == b.bl){
        if(a.bl % 2) return a.r < b.r;
        else return a.r > b.r;
    }else{
        return a.l < b.l;
    }
    */
}
void add(int x){
    if(!cnt[a[x]]) ret++;
    cnt[a[x]]++;
}
void del(int x){
    cnt[a[x]]--;
    if(!cnt[a[x]]) ret--;
}
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    block=n/sqrt(m*2/3);
    for(int i = 0; i < m; i++){
        cin >> ns[i].l >> ns[i].r;
        ns[i].l--, ns[i].r--;
        ns[i].id = i;
        ns[i].bl = ns[i].l / block;
    }
    sort(ns, ns + m, cmp);
    for(int i = 0; i < m; i++){
        //cout << ns[i].l << "<->" << ns[i].r << endl;
    }
    int l = 0, r = 1;
    add(l), add(r);
    for(int i = 0; i < m; i++){
        int ql = ns[i].l, qr = ns[i].r;
        while(l < ql) del(l++);
        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(r > qr) del(r--);
        ans[ns[i].id] = ret;
    }
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
    return 0;
}