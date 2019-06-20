// Author : Wqr_
// Time : 2019年06月16日 星期日 16时43分06秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int main(){
    double a, b;
    while(cin >> a >> b){
        double l = b - a;
        double ans = (80 * 80 - l * l ) / (4 * 80);
        cout << ans << endl;
    }
    return 0;
}
