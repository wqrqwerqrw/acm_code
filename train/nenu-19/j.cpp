// Author : Wqr_
// Time : 2019年07月22日 星期一 12时30分59秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n, s, t[2000 + 10];
int main(){
    iofuck;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t, t+n);
    int ans = t[n-1] * s;
    double ans_d = ans / 1000.0;
    double ans_i = (int)ans_d;
    if(ans_d - ans_i > 0) cout << ans_i + 1 << endl;
    else cout << ans_i << endl;
    return 0;
}
