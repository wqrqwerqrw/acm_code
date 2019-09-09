// Author : Wqr_
// Time : 2019年07月22日 星期一 13时38分40秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
bool ifsu[1000000 + ];
void shai(){

}
bool issu(int in){
    for(int i = 2; i < sqrt(in) + 1; i++){
        if(in % i == 0){
            return 0;
        }
    }
    return 1;
}
int getnum(int in){
    int ans = 0;
    for(int i = 2; i < in && in >= 4; i++) if(issu(i) && issu(in-i)){
        in = (in-i) - i; 
        ans++;
        i = 2;
    }
    return ans;
}
int main(){
    int in;
    cin >> in;
    cout << getnum(in) << endl;
    /*
    for(int i = 4; i <= 1000000; i+=2){
        printf("ans[%d] = %d;\n", i, getnum(i));
        //cout << i << " : ";
        //cout << getnum(i) << endl;
    }
    */
    return 0;
}
