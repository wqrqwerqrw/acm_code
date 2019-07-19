// Author : Wqr_
// Time : 2019年06月19日 星期三 22时49分59秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n;
int main(){
    iofuck;
    cin >> n;
    string a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(b.size() < a.size()) {
            cout << "NO" << endl;
            continue;
        }
        int na = 0, nb = 0;
        bool flag = 1;
        for(;na < a.size(), nb < b.size();){
            if(a[na] == b[nb]){
                if(a[na] == a[na + 1]){
                    na++, nb++;
                }else{
                    while(b[nb] == a[na]){
                        nb++;
                    }
                    na++;
                }
            }else{
                flag = 0;
                break;
            }
        }
        if(na == a.size() && nb == b.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
