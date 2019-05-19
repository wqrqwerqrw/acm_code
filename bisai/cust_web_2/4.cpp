/*************************************************************************
    > File Name: 4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 15时14分09秒
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
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    char in[1000100];
    while(t--){
        scanf("%s", in);
        int num = 0;
        int len = strlen(in);
        if(len >= 2){
            num = (in[len - 1] - '0') * 1 + (in[len - 2] - '0') * 10;
        }else if(len == 1){
            num = in[0] - '0';
        }
        int ans = num % 4;
        if(ans == 0) cout << 0 << endl;
        if(ans == 1) cout << 1 << endl;
        if(ans == 2) cout << 0 << endl;
        if(ans == 3) cout << -1 << endl;
    }
    return 0;
}
