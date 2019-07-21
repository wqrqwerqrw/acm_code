// Author : Wqr_
// Time : 2019年07月21日 星期日 14时41分48秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n, r, q;
const int maxn = 1e5 + 10;
struct stu{
    int s, w, id;
}m[maxn*2], w[maxn], l[maxn];
auto cmp = [](stu &a, stu &b){
    if(a.s == b.s) return a.id < b.id;
    else return a.s > b.s;
};
int main(){
    iofuck;
    cin >> n >> r >> q;
    for(int i = 0; i < 2*n; i++) cin >> m[i].s, m[i].id = i+1;
    for(int i = 0; i < 2*n; i++) cin >> m[i].w;
    sort(m, m+2*n, cmp);
    for(int i = 0; i < r; i++){
        int win = 0, lose = 0;
        for(int j = 0; j < 2*n; j += 2){
            if(m[j].w > m[j+1].w){
                w[win++] = m[j];
                w[win-1].s++;
                l[lose++] = m[j+1];
            }else{
                w[win++] = m[j+1];
                w[win-1].s++;
                l[lose++] = m[j];
            }
        }
        merge(w, w+win, l, l+lose, m, cmp);
    }
    cout << m[q-1].id << endl;
    return 0;
}
