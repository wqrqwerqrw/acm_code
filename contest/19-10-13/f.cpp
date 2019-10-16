/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/13
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
bool isf(char in){
    return (in == '+' || in == '-' ||in == '*' ||in == '/' ||in == '%');
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    iofuck;
    string rin, in;
    getline(cin, rin);
    in.push_back('(');
    for(auto i : rin){
        if(i != ' '){
            in.push_back(i);
        }
    }
    in.push_back(')');
    stack<char> st;
    bool ifproper = 1, iferror = 0;

    // error
    for(int i = 1; i < in.length(); i++){
        if(isalpha(in[i]) && isalpha(in[i-1])) iferror = 1;
        if(isf(in[i]) && isf(in[i-1])) iferror = 1;
    }
    if(iferror) {
        cout << "error" << endl;
        return 0;
    }

    // pro for ()
    int l = 0, r = 0, ch = 0;
    for(auto i : in){
        if(isalpha(i)) ch++;
        if(i == '(') l++;
        if(i == ')') r++;
    }
    if(l != r){
        cout << "error" << endl;
        return 0;
    }
    if(l != ch-1 || r != ch-1){
        ifproper = 0;
    }

    l = 0, r = 0, ch = 0;
    int mc = 0;
    for(auto i : in){
        st.push(i);
        if(i == ')'){
            while(st.top() != '('){
                char tmp = st.top();
                st.pop();
                if(isalpha(tmp)) ch++;
                if(isf(tmp)) mc++;
            }
            st.pop();
            if(mc != (ch - 1)){
                cout << "error" << endl;
                return 0;
            }
            if(ch != 2 || mc != 1){
                ifproper = 0;
            }
            ch = 0, mc = 0;

            st.push('b');
        }
    }

    /*
    while(!st.empty()){
        cout << st.top() << "";
        st.pop();
    }
    */
    if(ifproper) cout << "proper" << endl;
    else cout << "improper" << endl;
    return 0;
}