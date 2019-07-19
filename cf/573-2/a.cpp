// Author : Wqr_
// Time : 2019年07月14日 星期日 15时33分29秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int x;
int main(){
    cin >> x;
    int ans = x % 4;
    if(ans == 1){
        cout << 0 << " A" << endl;
    }else if(ans == 2){
        cout << 1 << " B" << endl;
    }else if(ans == 3){
        cout << 2 << " A" << endl;
    }else{
        cout << 1 << " A" << endl;
    }
    return 0;
}
