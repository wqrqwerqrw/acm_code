/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 13时37分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        double maxn = -1;
        double in;
        for(int i = 0; i < num; i++){
            cin >> in;
            if(in > maxn){
                maxn = in;
            }
        }
        printf("%.2lf\n", maxn);
    }
    return 0;
}
