/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月16日 星期四 10时18分14秒
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
int sum12, sum23, sum34, sum45;
int ans[6];
int nums[6] = {4, 8, 15, 16, 23, 42};
int book[6];
int main(){
    cout << "? 1 2" << endl;
    cin >> sum12;
    cout << "? 2 3" << endl;
    cin >> sum23;
    cout << "? 3 4" << endl;
    cin >> sum34;
    cout << "? 4 5" << endl;
    cin >> sum45;
    for(int i = 0; i < 6; i++){
        bool flag = 0;
        for(int j = 0; j < 6; j++){
            if(nums[i] * nums[j] == sum12){
                flag = 1;
                book[i]++;
                book[j]++;
                break;
            }
        }
        if(flag) break;
    }
    for(int i = 0; i < 6; i++){
        bool flag = 0;
        for(int j = 0; j < 6; j++){
            if(nums[i] * nums[j] == sum23){
                flag = 1;
                book[i]++;
                book[j]++;
                break;
            }
        }
        if(flag) break;
    }
    for(int i = 0; i < 6; i++){
        if(book[i] == 2){
            ans[1] = nums[i];
        }
    }
    ans[0] = sum12 / ans[1];
    ans[2] = sum23 / ans[1];
    ans[3] = sum34 / ans[2];
    ans[4] = sum45 / ans[3];
    ans[5] = 4 + 8 + 15 + 16 + 23 + 42 - ans[0] - ans[1] - ans[2] - ans[3] - ans[4];
    cout << "! ";
    for(int i = 0; i < 6; i++){
        cout << ans[i] <<  " ";
    }
    cout << endl;
    return 0;
}
