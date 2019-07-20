// Author : Wqr_
// Time : 2019年07月19日 星期五 17时57分16秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int x, y;
int n;
struct ope{
    int a, b, g, k;
};
queue<ope> q;
int main(){
    iofuck;
    cin >> n;
    int a, b, g, k;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> g >> k;
        q.push(ope{a, b, g, k});
    }
    cin >> x >> y;
    int ans = -1;
    int num = 0;
    while(!q.empty()){
        num++;
        ope tmp = q.front();
        q.pop();
        if(tmp.a <= x && tmp.b <= y && x <= (tmp.a + tmp.g) && y <= (tmp.b + tmp.k)){
            ans = num;
        }
    }
    cout << ans << endl;
    return 0;
}
