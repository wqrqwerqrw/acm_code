/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/15
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char re(char in){
    if(in == 'W') return 'B';
    else return 'W';
}
bool ch(string in){
    unordered_set<char> sett;
    for(auto i : in){
        sett.insert(i);
    }
    return sett.size() == 2;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string in;
    cin >> in;
    int len = in.length();
    int ope = 0;
    int ba = 0;
    bool flag = 0;
    vector<int> ans;
    unordered_set<char> sett;
    for(auto i: in){
        sett.insert(i);
    }
    if(sett.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    while(ch(in)){
        int curope = ope;
        for(int i = len - 1; i > ba; i--){
            if(in[i] == 'B'){
                ope++;
                ans.push_back(i);
                in[i] = re(in[i]);
                in[i-1] = re(in[i-1]);
                // cout << ope << " : " << in << endl;
                if (ope > 3 * len) {
                    flag = 1;
                    break;
                }
            }
        }
        if(ope == curope) {
            flag = 1;
            break;
        }
        ba++;
        if(flag) break;
    }
    if(flag) cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}