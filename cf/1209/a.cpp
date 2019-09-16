// Author : Wqr_
// Time : 19/09/15
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, a[110], ans[110];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int cur = 1;
    for(int i = 0; i < n; i++){
        if(ans[i] > 0) continue;
        bool flag = 0;
        for(int j = i; j < n; j++){
            if(ans[j] == 0){
                if(a[j] % a[i] == 0){
                    ans[j] = cur;
                    flag = 1;
                }
            }
        }
        if(flag) cur++;
    }
    cout << cur - 1 << endl;
    return 0;
}