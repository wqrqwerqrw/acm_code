// Author : Wqr_
// Time : 2019年08月27日 星期二 18时43分45秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;
int main(){
    cin >> n;
    int in;
    vector<P> v;
    for(int i = 1; i <= n; i++){
        cin >> in;
        v.push_back(P(in, i));
    }
    sort(v.begin(), v.end(), [](P a, P b){return a.first < b.first;});
    double ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i].second;
        ans += v[i].first * (v.size() - i - 1);
    }
    ans /= v.size();
    cout << endl;
    printf("%.2f", ans);
    return 0;
}
