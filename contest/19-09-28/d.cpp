// Author : Wqr_
// Time : 19/09/28
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
int main(){
    int n;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    string in;
    for(int i = 0; i < n; i++){
        cin >> in;
        int cs = 0;
        int di = 0;
        int sy = 0;
        int l = in.length();
        for(int i = 0; i < l; i++){
            if(isalpha(in[i])) cs++;
            if(isdigit(in[i])) di++;
            if(ispunct(in[i])) sy++;
        }
        if(cs < 4){
            cout << "The last character must be a letter." << endl;
        }else if(di < 4){
            cout << "The last character must be a digit." << endl;
        }else if(sy < 2){
            cout << "The last character must be a symbol." << endl;
        }else{
            cout << "The last character can be any type." << endl;
        }
        cs = 0;
        di = 0;
        sy = 0;
    }
    return 0;
}