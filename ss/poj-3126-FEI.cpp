/*************************************************************************
    > File Name: 3126.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 20:08:26 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool prime[10000];
int book[10000];
struct jie{
    int first;
    int second;
};
void ifPrime(){
    memset(prime, 1, sizeof(prime));
    prime[2] = 1;
    prime[3] = 1;
    for(int i = 2; i < 10000; i++){
        if(prime[i]){
            for(int j = 2; j * i < 10000; j++){
                prime[i * j] = 0;
            }
        }
    }
}
void bfs(int beg, int enda){
    memset(book, 0, sizeof(book));
    queue<jie> q;
    jie in;
    in.first = beg;
    in.second = 0;
    q.push(in);
    bool flag = true;
    int cn;
    while(!q.empty() && flag){
        jie t = q.front();
        //个
        cn = t.first / 10 * 10;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 1 * i;
            if(!book[tmp] && prime[tmp]){
                jie fuck;
                fuck.first = tmp;
                fuck.second = t.second + 1;
                book[tmp] = 1;
                q.push(fuck);
                if(tmp == enda){
                    flag = false;
                    break;
                }
            }
        }
        //十
        cn = t.first / 100 * 100 + t.first % 10;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 10 * i;
            if(!book[tmp] && prime[tmp]){
                book[tmp] = 1;
                jie fuck;
                fuck.first = tmp;
                fuck.second = t.second + 1;
                q.push(fuck);
                if(tmp == enda){
                    flag = false;
                    break;
                }
            }
        }
        //百
        cn = t.first / 1000 * 1000 + t.first % 100;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 100 * i;
            if(!book[tmp] && prime[tmp]){
                book[tmp] = 1;
                jie fuck;
                fuck.first = tmp;
                fuck.second = t.second + 1;
                q.push(fuck);
                if(tmp == enda){
                    flag = false;
                    break;
                }
            }
        }
        //千
        cn = t.first / 1000;
        for(int i = 1; i <= 9; i++){
            int tmp = cn + 1000 * i;
            if(!book[tmp] && prime[tmp]){
                book[tmp] = 1;
                jie fuck;
                fuck.first = tmp;
                fuck.second = t.second + 1;
                q.push(fuck);
                if(tmp == enda){
                    flag = false;
                    break;
                }
            }
        }
        q.pop();
    }
    if(flag) cout << "Impossible" << endl;
    else cout << q.back().second - 1 << endl;
}
int main(){
    ifPrime();
    int n;
    cin >> n;
    while(n--){
        int beg, enda;
        cin >> beg >> enda;
        bfs(beg, enda);
    }
    return 0;
}
