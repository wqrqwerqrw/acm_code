// Author : Wqr_
// Time : 19/09/24
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
vector<string> ss(22);
vector<int> flag(22, 0);
vector<vector<int> > ch(22, vector<int>(22, 0) );
char fir;
int ans = -1;
int bi(string& a, string& b){
    int la = a.length(), lb = b.length();
    int ret = 0, ita = max(la - lb, 0), itb = 0;
    while(ita < la){
        if(a[ita] == b[itb]) ita++, itb++, ret++;
        else ita++, itb = 0, ret = 0;
    }
    if(ret == la || ret == lb) return 0;
    return ret;
}
void dfs(int in, int num){
    flag[in]++;
    ans = max(ans, num);
    for(int i = 0; i < n; i++){
        if(flag[i] < 2 && ch[in][i] > 0){
            dfs(i, num + ss[i].length() - ch[in][i]);
        }
    }
    flag[in]--;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ss[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ch[i][j] = bi(ss[i], ss[j]);
        }
    }
    cin >> fir;
    for(int i = 0; i < n; i++){
        if(ss[i][0] == fir){
            dfs(i, ss[i].length());
        }
    }
    cout << ans << endl;
    return 0;
}