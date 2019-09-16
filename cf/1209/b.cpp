// Author : Wqr_
// Time : 19/09/15
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool beg[110];
int a[110], b[110];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            beg[i] = 1;
            cur++;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int ans = cur;
    for(int i = 0; i < 1e5 + 1e4; i++){
        for(int j = 0; j < n; j++){
            if(i >= b[j]){
                if(i == b[j]){
                    beg[j] = !beg[j];
                    if(beg[j] == 1) cur++;
                    else cur--;
                }else if(i >= b[j] + a[j]){
                    if((i - b[j]) % a[j] == 0){
                        beg[j] = !beg[j];
                        if (beg[j] == 1)
                            cur++;
                        else
                            cur--;
                    }
                }
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}