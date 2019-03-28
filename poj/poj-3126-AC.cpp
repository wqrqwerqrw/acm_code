/*************************************************************************
    > File Name: 3126.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 21:42:55 2019
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
    int num;
    int step;
};
void ifPrime(){
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    prime[2] = 0;
    prime[2] = 1;
    prime[3] = 1;
    for(int i = 2; i < 10000; i++){
        if(prime[i]){
            for(int j = 2; j * i < 10000; j++){
                prime[i * j] = 0;
            }
        }
    }
    if(prime[1763]) cout << "yes";
}
void bfs(int a, int b){
    memset(book, 0, sizeof(book));
    queue<jie> q;
    jie in;
    in.num = a;
    in.step = 0;
    book[a] = 1;
    q.push(in);
    bool flag = true;
    int cn;
    while(!q.empty() && flag){
        if(q.back().num == b){
            flag = false;
            break;
        }
        jie t = q.front();
        cn = t.num / 10 * 10;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 1 * i;
            if(!book[tmp] && prime[tmp]){
                jie fuck;
                fuck.num = tmp;
                fuck.step = t.step + 1;
                book[tmp] = 1;
                q.push(fuck);
                if(tmp == b){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
        cn = t.num / 100 * 100 + t.num % 10;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 10 * i;
            if(!book[tmp] && prime[tmp]){
                jie fuck;
                fuck.num = tmp;
                fuck.step = t.step + 1;
                book[tmp] = 1;
                q.push(fuck);
                if(tmp == b){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
        cn = t.num / 1000 * 1000 + t.num % 100;
        for(int i = 0; i <= 9; i++){
            int tmp = cn + 100 * i;
            if(!book[tmp] && prime[tmp]){
                jie fuck;
                fuck.num = tmp;
                fuck.step = t.step + 1;
                book[tmp] = 1;
                q.push(fuck);
                if(tmp == b){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
        cn = t.num % 1000;
        for(int i = 1; i <= 9; i++){
            int tmp = cn + 1000 * i;
            if(!book[tmp] && prime[tmp]){
                jie fuck;
                fuck.num = tmp;
                fuck.step = t.step + 1;
                book[tmp] = 1;
                q.push(fuck);
                if(tmp == b){
                    flag = false;
                    break;
                }
            }
        }
        q.pop();
    }
    if(flag) cout << "Impossible" << endl;
    else cout << q.back().step << endl;
}
int main(){
    ifPrime();
    int n;
    int a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        bfs(a, b);
    }
    return 0;
}
