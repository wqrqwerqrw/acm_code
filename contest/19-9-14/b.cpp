// Author : Wqr_
// Time : 19/09/14
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin >> T;
    cin.get();
    int chour, cmin;
    int uhour;
    int thour;
    int kase = 0;
    while(T--){
        scanf("%d:%d", &chour, &cmin);
        string ap;
        cin >> ap;
        cin.get();
        if(chour == 12 && ap[0] == 'A'){
            chour = 0;
        }
        if(ap[0] == 'P'){
            if(chour != 12){
                chour += 12;
            }
        }
        string a, b;
        cin >> a >> b;
        if(a[0] == 'B'){
            uhour = chour - 8;
        }else if(a[0] == 'W'){
            uhour = chour + 5;
        }else if(a[0] == 'L'){
            uhour = chour;
        }else if(a[0] == 'M'){
            uhour = chour - 3;
        }
        if (b[0] == 'B') {
            thour = uhour + 8;
        } else if (b[0] == 'W') {
            thour = uhour - 5;
        } else if (b[0] == 'L') {
            thour = uhour;
        } else if (b[0] == 'M') {
            thour = uhour + 3;
        }
        /*
        cout << "---" << endl;
        cout << chour << endl;
        cout << uhour << endl;
        cout << thour << endl;
        cout << "---" << endl;
        */
        int tt = thour;
        int time;
        int pmam;
        //
        if(tt >= 24){
            time = 1;
            tt -= 24;
        }else if (tt < 0){
            time = -1;
            tt += 24;
        }else {
            time = 0;
        }

        if(tt >= 12){
            pmam = 1;
            if(tt > 12){
                tt -= 12;
            }
        }else{
            pmam = 0;
        }
        /******************/
        // yes
        cout << "Case " << ++kase << ": ";
        if(time == -1){
            cout << "Yesterday ";
        }else if(time == 0){
            cout << "Today ";
        }else if(time == 1){
            cout << "Tomorrow ";
        }
        //hour
        if(tt == 0){
            cout << 12;
        }else if(tt == 12){
            cout << 12;
        }else{
            cout << tt;
        }
        cout << ":";
        //min
        if(cmin < 10) cout << 0 << cmin << " ";
        else cout << cmin << " ";
        if(pmam) cout << "PM";
        else cout << "AM";
        cout << endl;
    }
    return 0;
}