// Author : Wqr_
// Time : 2019年07月21日 星期日 13时08分51秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int main(){
    iofuck;
    int n;
    int a[100000 + 10];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << a[i];
    }
    return 0;
}
