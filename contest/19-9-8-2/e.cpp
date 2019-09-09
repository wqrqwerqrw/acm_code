// Author : Wqr_
// Time : 2019/9/8 12:16:56

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int qmax = 100 + 10;
const int nmax = 40000000 + 10;
int n, m, q, k[qmax];
int main(){
    int t;
    iofuck;
    cin >> t;
    while(t--){
        cin >> n >> m >> q;
        for(int i = 0; i < q; i++){
            cin >> k[i];
        }
    }
    return 0;
}
