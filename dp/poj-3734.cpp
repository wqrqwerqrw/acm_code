// Author : Wqr_
// Time : 19/09/13
#include<iostream>
#include<vector>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector< ll > vec;
typedef vector< vec > mat;
mat dp(3, vec(3));
const int mod = 10007;
int N;
mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            for(int k = 0; k < B[0].size(); k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}
mat pow_m(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
void solve(){
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int t;
    cin >> t;
    dp[0][0] = 2, dp[0][1] = 1, dp[0][2] = 0;
    dp[1][0] = 2, dp[1][1] = 2, dp[1][2] = 2;
    dp[2][0] = 0, dp[2][1] = 1, dp[2][2] = 2;
    while(t--){
        cin >> N;
        mat tmp = pow_m(dp, N);
        cout << tmp[0][0] % mod << endl;
    }
    return 0;
}