// Author : Wqr_
// Time : 2019年06月19日 星期三 23时16分40秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n, m;
int t1[1000];
int t2[1000];
int main(){
    //iofuck;
    cin >> n >> m;
    int past = 0;
    for(int i = 0; i < n; i++){
        cin >> t1[i];
        past += t1[i];
        int ans = 0;
        if(past > m){
            sort(t1, t1 + i, greater<int>());
            int tmp = past;
            for(int j = 0; tmp > m && j < i; j++){
                tmp -= t1[j];
                ans++;
            }
        }
        cout << ans << " ";
    }
    return 0;
}
