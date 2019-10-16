/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/10
//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vll;
#define inf 0x3f3f3f3f
const int nmax = 1e3 + 10;
int n;
int in[nmax][nmax], s[nmax][nmax];
int main(){
    //freopen("in.txt","r",stdin);
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> in[i][j];
            s[i][j] = (j == 0 ? in[i][j] : s[i][j - 1] + in[i][j]);
        }
    }
    int sum, ans = -inf;
    for(int l = 0; l < n; l++){
        for(int j = 0; j + l < n; j++){
            sum = 0;
            for(int i = 0; i < n; i++){
                if(j == 0) sum += s[i][j + l];
                else sum += s[i][j+l] - s[i][j-1];
                if(sum < 0) sum = 0;
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}