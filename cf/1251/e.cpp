/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/26
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    //std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n, ans = 0, t = 0;
        cin >> n;
        //vector<pii> a(n);
        pii a[n];
        //for(auto &i : a) cin >> i.first >> i.second;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a[i].first, &a[i].second);
            //cin >> a[i].first >> a[i].second;
        }
        //sort(a.begin(), a.end());
        sort(a, a + n);
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = n - 1; i >= 0; i--){
            pq.push(a[i].second);
            if(a[i].first > t + i){
                ans += pq.top();
                pq.pop();
                t++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}