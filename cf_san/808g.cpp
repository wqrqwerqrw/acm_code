/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/11
#include <bits/stdc++.h>
#define first fi
#define second se
using namespace std;
typedef long long ll;
bool equ(const char& a, const char& b){
    if(a == '#' || b == '#') return false;
    if(a == '?' || b == '?') return true;
    return a == b;
}
vector<int> prefix_function(string s) {
  int l = (int)s.length();
  vector<int> pi(l);
  for (int i = 1; i < l; i++) {
    int j = pi[i - 1];
    while(j > 0 && !equ(s[i], s[j])) j = pi[j - 1];
    // while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if(equ(s[i], s[j])) j++;
    // if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    b += "#" + a;
    int ln = b.length();
    auto v = prefix_function(b);
    // cout << b << endl;
    // for(auto i : b) cout << i << " ";
    // cout << endl;
    // for(auto i : v) cout << i << " ";
    int ans = 0;
    for(int i = lb; i < ln; i++){
        if(v[i] == lb) ans++;
    }
    cout << ans << endl;
    return 0;
}