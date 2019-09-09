/*************************************************************************
    > File Name: e.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 14时31分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int lnum = (int)'z' - (int)'a';
int book[3000];
int main(){
    string in;
    cin >> in;
    int num = 0;
    for(int i = 0; i < in.length(); i++){
        if(!book[(int)in[i]]) num++;
        book[(int)in[i]]++;
    }
    sort(book, book + 3000);
    int ans = 0;
    int mark = 0;
    if(num > 2){
        for(int i = 0; i < 3000; i++){
            if(book[i]){
                ans+= book[i];
                mark++;
                if(mark == num - 2){
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
