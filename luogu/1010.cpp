// Author : Wqr_
// Time : 2019年07月22日 星期一 18时22分01秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
string dfs(int in){
    if(in == 0) return "0";
    string ans = "";
    int w = 0;
    while(in){
        if(in & 1)
            ans = ((w == 1) ? "2" : "2(" + dfs(w) + ")") + 
                ((ans == "") ? "" : "+") + ans;
        in >>= 1, w++;
    }
    return ans;
}
int main(){
    iofuck;
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}
