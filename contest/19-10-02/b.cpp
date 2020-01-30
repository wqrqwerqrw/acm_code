// Author : Wqr_
// Time : 19/10/02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
string beg, to;
struct node{
    string v;
    int cur;
};
char roat(char in){
    if(in == 'F') return 'A';
    else return in + 1;
}
string opeA(string in, int pos){
    if (pos - 1 != -1) in[pos - 1] = roat(in[pos - 1]);
    if (pos + 1 != 8) in[pos + 1] = roat(in[pos + 1]);
    return in;
}
string opeB(string in, int pos){
    if(pos == 0 || pos == 7) return in;
    else in[pos + 1] = in[pos - 1];
    return in;
}
string opeC(string in, int pos){
    in[8 - pos] = roat(in[8 - pos]);
    return in;
}
string opeD(string in, int pos){
    if(pos == 0 || pos == 7) return in;
    if (pos <= 3)
        for (int i = 0; i < pos; i++) in[i] = roat(in[i]);
    else
        for(int i = pos + 1; i < 8; i++) in[i] = roat(in[i]);
    return in;
}
string opeE(string in, int pos){
    if(pos == 0 || pos == 7) return in;
    if(pos <= 3){
        in[0] = roat(in[0]);
        in[pos * 2] = roat(in[pos * 2]);
    }else{
        in[7] = roat(in[7]);
        int ch = pos - (7 - pos);
        in[ch] = roat(in[ch]);
    }
    return in;
}
string opeF(string in, int pos){
    int ch;
    if(pos % 2) ch = pos / 2;
    else ch = (pos + 8) / 2;
    in[ch] = roat(in[ch]);
    return in;
}
unordered_map<string, bool> flag;
void bfs(){
    queue<node> q;
    node fir;
    fir.v = beg;
    fir.cur = 0;
    q.push(fir);
    while(q.size()){
        node tmp = q.front();
        q.pop();
        cout << tmp.v << endl;
        flag[tmp.v] = 1;
        cout << tmp.cur;
        if(tmp.v == to){
            cout << tmp.cur << endl;
            break;
        }
        string next;
        for(int i = 0; i < 8; i++){
            switch(tmp.v[i]){
                case 'A':
                    next = opeA(tmp.v, i);
                    break;
                case 'B':
                    next = opeB(tmp.v, i);
                    break;
                case 'C':
                    next = opeC(tmp.v, i);
                    break;
                case 'D':
                    next = opeD(tmp.v, i);
                    break;
                case 'E':
                    next = opeE(tmp.v, i);
                    break;
                case 'F':
                    next = opeF(tmp.v, i);
            }
            if(flag[next]) continue;
            node nextnode;
            nextnode.v = next;
            nextnode.cur = tmp.cur + 1;
            q.push(nextnode);
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> beg >> to;
    bfs();
    //cout << opeF("ABCDEFCD", 4) << endl;
    return 0;
}