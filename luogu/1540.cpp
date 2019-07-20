// Author : Wqr_
// Time : 2019年07月19日 星期五 18时49分54秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int m, n;
int main(){
    cin >> m >> n;
    list<int> l;
    int in;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> in;
        auto it = find(l.begin(), l.end(), in);
        if(it == l.end()){
            ans++;
            l.push_back(in);
            if(l.size() > m){
                l.pop_front();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
