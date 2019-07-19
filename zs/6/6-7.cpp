// Author : Wqr_
// Time : 2019年07月14日 星期日 18时57分24秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 500;
const int root = 1;
int cnt;
int l[nmax];
int r[nmax];
int value[nmax];
bool hv[nmax];
bool fail = 0;
vector<int> ans;
void newtree(){
    l[root] = 0;
    r[root] = 0;
    hv[root] = 0;
    cnt = root;
}
int newnode(){
    ++cnt;
    l[cnt] = r[cnt] = 0;
    hv[cnt] = 0;
    return cnt;
}
void addnode(int v, string s){
    int u = root;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'L'){
            if(l[u] == 0) l[u] = newnode();
            u = l[u];
        }else if(s[i] == 'R'){
            if(r[u] == 0) r[u] = newnode();
            u = r[u];
        }
        if(hv[u]) fail = 1;
        value[u] = v;
        hv[u] = 1;
    }
}
bool bfs(){
    queue<int> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(!hv[u]) return false;
        ans.push_back(value[u]);
        if(l[u]) q.push(l[u]);
        if(r[u]) q.push(r[u]);
    }
    cout << "*******" << endl;
    return true;
}
void endd(){
    if(bfs() && !fail){
        for(int i = 0; i < ans.size(); i++){
            if(i) cout << " ";
            cout << ans[i];
        }
    }else{
        cout << "not complete" << endl;
    }
}
int main(){
    iofuck;
    char in[100];
    fail = 0;
    newtree();
    while(cin >> in){
        if(!strcmp(in, "()")){
            endd();
            fail = 0;
            newtree();
        }
        int v;
        sscanf(&in[1], "%d", &v);
        addnode(v, strchr(in, ',') + 1);
    }
    return 0;
}
