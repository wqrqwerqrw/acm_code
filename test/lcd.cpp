/*************************************************************************
    > File Name: lcd.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月28日 星期四 19时19分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int lcd(int a, int b, int h){
    return (a * (b / h));
}
int main(){
    int a, b;
    while(cin >> a >> b){
        int h = __gcd(a, b);
        int l = lcd(a, b, h);
        cout << l << endl;
    }
    return 0;
}
