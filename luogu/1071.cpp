// Author : Wqr_
// Time : 2019年07月22日 星期一 11时31分00秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int main(){
    iofuck;
    string a, b, c;
    map<char, char> mapp;
    bool iff = 0;
    cin >> a >> b >> c;
    if(a.length() != b.length()) iff = 1;
    for(int i = 0; i < a.length(); i++){
        auto it = mapp.find(a[i]);
        if(it != mapp.end()) mapp[a[i]] = b[i];
        else iff = 1;
    }
    if(iff) cout << "Failed" << endl;
    else{
        for(int i = 0; i < c.length(); i++) cout << mapp[c[i]];
    }
    cout << endl;
    return 0;
}
