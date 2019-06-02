/*************************************************************************
    > File Name: c_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月02日 星期日 11时46分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
vector<P> v;
const int nmax = 3e5 + 5;
int a[nmax], pos[nmax];
int n, ans = 0;
void swp(int i, int j){
    v.push_back(P(i, j));
    swap(pos[a[i]], pos[a[j]]);
    swap(a[i], a[j]);
    /*
    for(int k = 1; k <= n; k++){
        cout << a[k] << " - ";
    }
    */
    cout << endl;
}
int main(){
    iofuck;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 2; i < n; i++){
        if(a[i] == i) continue;
        int p = pos[i];
        if(abs(p - i) >= n / 2){
            ans++;
            swp(i, p);
        }else{
            if(i <= n / 2 && p <= n / 2){
                ans += 2;
                swp(p, n);
                swp(i, n);
            }else if(i <= n / 2 && p > n / 2){
                ans += 3;
                swp(1, p);
                swp(1, n);
                swp(i, n);
            }else{
                ans += 2;
                swp(1, p);
                swp(1, i);
            }
        }
    }
    if(a[1] != 1) swp(1, n), ans++;
    cout << ans << endl;
    for(auto tmp : v){
        cout << tmp.first << " " << tmp.second << endl;
    }
    return 0;
}
