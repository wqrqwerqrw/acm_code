// Author : Wqr_
// Time : 2019年07月18日 星期四 19时34分37秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];
void dfs(int x, int y){
    printf("%c(", buf[x][y]);
    if(x+1 < n && buf[x+1][y] == '|'){
        int i = y;
        while(i-1 >= 0 && buf[x+2][i-1] == '-') i--;
        while(buf[x+2][i] == '-' && buf[x+3][i] != '\0'){
            if(!isspace(buf[x+3][i])){
                dfs(x+3, i);
            }
            i++;
        }
    }
    printf(")");
}
void solve(){
    for(n = 0;;){
        fgets(buf[n], maxn, stdin);
        if(buf[n][0] == '#') break;
        else n++;
    }
    printf("(");
    if(n){
        for(int i = 0; i < strlen(buf[0]); i++){
            if(buf[0][i] != ' '){
                dfs(0, i);
                break;
            }
        }
    }
    printf(")\n");
}
int main(){
    int t;
    fgets(buf[0], maxn, stdin);
    sscanf(buf[0], "%d", &t);
    while(t--) solve();
    return 0;
}
