// Author : Wqr_
// Time : 2019/9/2 19:34:51

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n;
string ss[10][10];
map<int, char> ans;
int main(){
    bool ifyes = 1;
    string tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ss[i][j];
        }
    }

    // find 0
    bool iffind0 = 0;
    for(int i = 1; i < n; i++){
        bool iiz = 1;
        for(int j = 1; j < n; j++){
            if(ss[i][j][0] != ss[0][j][0]){
                iiz = 0;
                break;
            }
        }
        if(iiz){
            ans[0] = ss[i][0][0];
            iffind0 = 1;
            break;
        }
    }
    if(!iffind0) {
        cout << "ERROR!" << endl;
        return 0;
    }

    for(int i = 1; i < n; i++){
        //find i
        for(int j = 1; j < n; j++){
            for(int k = 1; k < n; k++){

            }
        }
    }
    return 0;
}
