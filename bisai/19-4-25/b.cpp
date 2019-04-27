/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 19时56分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int a[2200];
int q[2200];
int book[2200];
int num;
bool mark[2200];
void dfs(int i){
    num++;
    if(i - 1 >= 0 && !mark[i-1] && !book[a[i-1]]){
        mark[i-1] = 1;
        dfs(i - 1);
    }
    if(i + 1 < n && !mark[i+1] && !book[a[i+1]]){
        mark[i+1] = 1;
        dfs(i + 1);
    }
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        q[i] = a[i];
    }
    sort(q, q + n, greater<int>());
    int sum = 0;
    for(int i = 0; i < k; i++){
        book[q[i]]++;
        sum += q[i];
    }
    bool kong = 0;
    cout << sum << endl;
    //memset(mark, 0, sizeof(mark));
    if(k == 1){
        cout << n << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            if(book[a[i]]){
                num = 0;
                mark[i] = 1;
                dfs(i);
                book[a[i]]--;
                cout << num << " ";
            }
        }
    }
    return 0;
}
