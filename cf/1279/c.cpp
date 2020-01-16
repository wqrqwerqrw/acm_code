/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/27
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    int n, m;
    while(t--){
        cin >> n >> m;
        queue<int> q;
        vector<int> a(n);
        vector<int> b(m);
        set<int> sett;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            q.push(a[i]);
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            if(sett.find(b[i]) != sett.end()){
                ans++;
                sett.erase(b[i]);
                continue;
            }
            while(q.front() != b[i]){
                sett.insert(q.front());
                q.pop();
            }
            q.pop();
            ans += sett.size() * 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}