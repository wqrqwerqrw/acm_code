/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/10
#include<vector>
#include<iostream>
#define first fi
#define second se
using namespace std;
typedef long long ll;
int n, m;

vector<int> prefix_function(vector<int> s) {
  int len = s.size();
  vector<int> pi(len);
  for (int i = 1; i < len; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    int T;scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        vector<int> t(n);
        vector<int> s(m);
        for(auto &i : t) scanf("%d", &i);
        for(auto &i : s) scanf("%d", &i);
        s.push_back(-1000000 - 7);
        for(auto &i : t) s.push_back(i);
        auto pi = prefix_function(s);
        vector<int> ans;
        for(int i = m + 1; i < n + m + 1; i++){
            if(pi[i] == m) ans.push_back(i - 2 * m);
        }
        if(ans.size()) printf("%d\n", ans[0] + 1);
        else printf("-1\n");
    }
    return 0;
}