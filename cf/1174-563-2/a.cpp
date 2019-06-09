/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 21时55分16秒
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
const int nmax = 1000 + 5;
int n;
int a[nmax * 2];
int main(){
    iofuck;
    cin >> n;
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i];
    }
    for(int i = n; i < 2 * n; i++){
        sum2 += a[i];
    }
    if(sum1 != sum2){
        for(int i = 0; i < 2 * n; i++){
            cout << a[i] << " ";
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}
