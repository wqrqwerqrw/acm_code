/************************************************************************* > File Name: q_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月09日 星期四 08时54分56秒
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
int a[5];
bool flag = 0;
int main(){
    while(scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3])){
        if(!a[0] && !a[1] && !a[2] && !a[3]) break;
        if(flag) cout << endl;
        flag = 1;
        bool mark = 1;
        int tmp;
        do{
            if(a[0] == 0) continue;
            if(mark){
                printf("%d%d%d%d", a[0], a[1], a[2], a[3]);
                mark = 0;
            }else if(tmp == a[0]){
                printf(" %d%d%d%d", a[0], a[1], a[2], a[3]);
            }else{
                printf("\n%d%d%d%d", a[0], a[1], a[2], a[3]);
            }
            tmp = a[0];
        }while(next_permutation(a, a + 4));
        cout << endl;
    }
    return 0;
}
