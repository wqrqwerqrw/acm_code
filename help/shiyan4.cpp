// Author : Wqr_
// Time : 2019年06月16日 星期日 19时31分43秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
ll ns[10][10];
ll getping(int in){
    ll ans = 0;
    for(int i = 0; i < 5; i++){
        ans += ns[i][in];
    }
    return ans / 5;
}
int main(){
    ll a, b;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cin >> a >> b;
            ns[i][j] = a * 60 + b;
        }
    }
    for(int i = 0; i < 5; i++){
        ns[i][4] = abs(ns[i][0] - ns[i][2]);
    }
    for(int i = 0; i < 5; i++){
        ns[i][5] = abs(ns[i][1] - ns[i][3]);
    }
    for(int i = 0; i < 6; i++){
        for(int j = 4; j < 6; j++){
            ll out1 = ns[i][j] / 60;
            ll out2 = ns[i][j] % 60;
            if(out1 > 180){
                ns[i][j] = 360 * 60 - ns[i][j];
                out1 = ns[i][j] / 60;
                out2 = ns[i][j] % 60;
            }
        }
    }
    for(int i = 0; i < 6; i++){
        ns[5][i] = getping(i);
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ll out1 = ns[i][j] / 60;
            ll out2 = ns[i][j] % 60;
            cout << out1 << "-" << out2 << " ";
        }
        cout << endl;
    }
    ll f_ = (ns[5][4] + ns[5][5]) / 2;
    ll out1 = f_ / 60;
    ll out2 = f_ % 60;
    cout << out1 << "-" << out2 << endl;
    for(int i = 0; i < 4; i++){
        ll sum = 0;
        for(int j = 0; j < 5; j++){
            //sum += (ns[5][i]/60 - ns[j][i]/60) * (ns[5][i]/60 - ns[j][i]/60);
            sum += (ns[5][i] - ns[j][i]) * (ns[5][i] - ns[j][i]);
        }
        sum /= 20;
        ns[6][i] = pow(sum, 0.5);
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            /*
            if(i == 6) {
                cout << ns[i][j] << " ";
                continue;
            }
            */
            ll out1 = ns[i][j] / 60;
            ll out2 = ns[i][j] % 60;
            cout << out1 << "-" << out2 << " ";
        }
        cout << endl;
    }
    ll sum = 0;
    for(int i = 0; i < 4; i++){
        sum += ns[6][i] * ns[6][i];
    }
    sum = pow(sum, 0.5);
    cout << sum / 60 << " " << sum % 60 << endl;
    return 0;
}
