// Author : Wqr_
// Time : 2019年08月31日 星期六 15时26分45秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int main(){
    multiset<int> sett = {5, 4, 3, 2, 1};
    cout << *sett.rbegin();
    return 0;
}
