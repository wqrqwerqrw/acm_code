// Author : Wqr_
// Time : 2019年07月20日 星期六 19时14分30秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
map<char, bool> mapp;
stack<int> s_n, s_b;
bool ife, ifb;
int w, ans, ans_tmp;
void init(){
    mapp.clear();
    while(!s_n.empty()) s_n.pop();
    while(!s_b.empty()) s_n.pop();
    ife = 0, ifb = 0, ans = 0, ans_tmp = 0;
}
void f(){
    char i, x[5], y[5];
    cin >> i >> x >> y;
    if(mapp[i]) ife = 1;
    mapp[i] = 1;
    int x_int = 0, y_int = 0;
    if(isdigit(x[0])) sscanf(x, "%d", &x_int);
    if(isdigit(y[0])) sscanf(y, "%d", &y_int);
    if(x[0] == 'n' && y[0] == 'n') ifb ? s_b.push(0) : s_n.push(0);
    if(x[0] == 'n' && y_int) ifb = 1, s_n.push(0);
    if(x_int && y[0] == 'n') ifb ? s_b.push(1) : s_n.push(1);
    if(x_int && y_int){
        if(x_int > y_int) ifb = 1, s_n.push(0);
        if(x_int <= y_int) ifb ? s_b.push(0) : s_n.push(0);
    }
}
void e(){
    if(!s_b.empty()) s_b.pop();
    else if(!s_n.empty()) ans_tmp += s_n.top(), s_n.pop();
    else ife = 1;
    if(s_b.empty() && s_n.empty()){
        mapp.clear();
        ifb = 0;
        ans = max(ans, ans_tmp);
        ans_tmp = 0;
    }
}
void solve(){
    init();
    int l;
    char o[10];
    char ope;
    scanf("%d %s", &l, o);
    if(o[2] == '1') w = 0;
    else sscanf(&o[4], "%d", &w);
    for(int i = 0; i < l; i++){
        cin >> ope;
        (ope == 'F') ? f() : e();
    }
    if(ife || !s_n.empty() || !s_b.empty()) printf("ERR\n");
    else (ans == w) ? printf("Yes\n") : printf("No\n");
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
