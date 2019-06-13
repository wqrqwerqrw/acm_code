// Author : Wqr_
// Time : 2019年06月12日 星期三 16时58分38秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int main(){
    double n, i, m;
    cin >> n>> i >> m;
    double ans = n;
    for(int j = 0; j < m; j++){
        ans += ans * (i / 100);
    }
    cout << ans << endl;
    return 0;
}
