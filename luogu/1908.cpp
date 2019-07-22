// Author : Wqr_
// Time : 2019年07月22日 星期一 18时57分34秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 5e5 + 10;
ll ans = 0;
int a[nmax], b[nmax];
void msort(int l, int r){
    if(l == r) return ;
    int mid = (l + r) / 2, i = l, j = mid + 1, k = l;
    msort(l, mid), msort(mid + 1, r);
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], ans += mid - i + 1;
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = b[i];
}
int main(){
    iofuck;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    msort(0, n-1);
    cout << ans;
    return 0;
}
