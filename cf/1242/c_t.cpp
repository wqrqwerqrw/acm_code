/****************************************************************
# @Author:      miniLCT
# @DateTime:    2019-11-07 00:03:54
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
bool isprime(ll x){
  if(x == 1 || x == 2)return true;
  int m = sqrt(x + 0.5);
  for(int i = 2; i <= m;i++){
    if(x % i == 0)return false;
  }
  return true;
}
int p[maxn],c[maxn];
int m ;
void divide(int n){
  m = 0;
  int sqrtn = sqrt(n+0.5);
  for(int i = 2; i <= sqrtn; i++){
    if(n % i == 0){  //i是质数
      p[++m] = i;
      c[m] = 0;
      while(n % i == 0)n /= i,c[m]++; // 除掉所有的i
    }
  }
  if(n > 1)//n是质数
    p[++m] = n, c[m] = 1;
  /*for(int i = 1; i <= m; i++)
    cout << p[i] << '^' << c[i] <<endl;*/
}
int32_t main(){
    ll n;
    cin >> n;
    if(isprime(n)){
      cout << n << endl;
      return 0;
    }
    divide(n);
    if(m == 1)cout << p[1] <<endl;
    else cout << 1 << endl;
}
