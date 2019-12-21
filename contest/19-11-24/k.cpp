/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/24
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int n, k;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(100);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(2);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    cout << "--------------" << endl;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vi a(n);
        for(auto &i : a) cin >> i;
        int ans = 0;
        unordered_map<int, int> mapp;
        for(int i = 0; i < n; i++){
            unordered_set<int> sett;
            sett.insert(a[i]);
            int j;
            for(j = i + 1; j < n; j++){
                if(sett.find(a[j]) != sett.end()) break;
                if(a[j] > a[i]) break;
                sett.insert(a[j]);
            }
            if(j != n && a[j] > a[i]) mapp[j] = i;
            j--;
            int lenmin = max(1, a[i] - k);
            int len = j - i + 1; 
            ans += max(0, len - lenmin + 1);
            cout << i << " " << j << " " << len - lenmin + 1 << endl;
        }
        cout << "wwwwwwwwww" << endl;
        for(auto cur : mapp){
            int i = cur.second, j = cur.first;
            int lenmin = max(1, a[j] - k);
            cout << lenmin << endl;
            int len = j - i + 1;
            ans += max(0, len - lenmin + 1);
            cout << i << " " << j << " " << len - lenmin + 1 << endl;
        }
        cout << ans << endl;
        cout << "MMMMMMMMMMMMMMM" << endl;
    }
    return 0;
}