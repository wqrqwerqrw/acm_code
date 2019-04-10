/*************************************************************************
    > File Name: f.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 18时44分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct point{
    int x, y;
};
int n;
point a, b;
unsigned long long int getdis(point in1, point in2){
    return (in1.x - in2.x) * (in1.x - in2.x) + (in1.y - in2.y) * (in1.y - in2.y);
}
unsigned long long int maxa = 0, maxb = 0;
int main(){
    cin >> n;
    scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
    for(int i = 0; i < n; i++){
        point in;
        scanf("%d %d", &in.x, &in.y);
        unsigned long long int disa = getdis(in, a), disb = getdis(in, b);
        if(disa <= maxa || disb <= maxb) continue;
        if(disa >= disb){
            if(disb > maxb) maxb = disb;
        }else{
            if(disa > maxa) maxa = disa;
        }
    }
    cout << maxa + maxb;
    return 0;
}
