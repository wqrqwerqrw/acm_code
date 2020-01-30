// Author : Wqr_
// Time : 19/09/21
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll a[100000];
ll sum[100000];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("out.txt","w",stdout);
    #endif
    iofuck;
    a[1] = 1;
    sum[1] = 1;
    for(int i = 2; i < 1000; i++){
        a[i] = a[i-1];
        ll tmp = a[i-1];
        while(tmp){
            a[i] += tmp % 10;
            tmp /= 10;
        }
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i < 1000; i++){
        cout << a[i] << "<->" << sum[i] << endl;
    }
    return 0;
}