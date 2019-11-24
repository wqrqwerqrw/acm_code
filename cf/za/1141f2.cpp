/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/17
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int n;
int main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vi a(n);
    for (auto &i : a) cin >> i;
    map<int, vector<pii>> mapp;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            mapp[sum].push_back(make_pair(i, j));
        }
    }
    vector<pii> ans;
    int max = -1;
    for (auto &i : mapp) {
        sort(i.second.begin(), i.second.end(), [](pii &a, pii &b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });
        vector<pii> anstmp;
        int num = 0;
        int r = -1;
        for(auto j : i.second){
            if(j.first > r){
                r = j.second;
                num++;
                anstmp.push_back(j);
            }
        }
        if(num > max){
            ans = anstmp;
            max = num;
        }
    }
    cout << max << endl;
    for(auto i : ans){
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
    return 0;
}