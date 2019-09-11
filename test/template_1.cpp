// Author : Wqr_
// Time : 19/09/11
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
void print(){
    cout << "end" << endl;
}
template<typename head, typename ...T>
void print(head first, const T&... args){
    cout << first << endl;
    print(args...);
}
int main(){
    print(1, 2, 3, 4, "1000", 2000);
    return 0;
}