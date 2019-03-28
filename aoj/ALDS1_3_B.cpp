/*************************************************************************
    > File Name: ALDS1_3_B.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov 12 19:07:15 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define LEN 10005
using namespace std;
struct p{
    char name[100];
    int t;
};
p p[LEN];
int head, tail, n;
void enqueue(p in){
    p[tail] = in;
    tail = (tail + 1) % LEN;
}
p dequeue(){
    p x = p[head];
    head = (head + 1) % LEN;
    return x;
}
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int time = 0;
    int c;
    int i, q;
    p u;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> p[i].name;
        cin >> p[i].t;
    }
    head = 0;
    tail = n;

    while(head != tail){
        u = dequeue();
        c = min(q, u.t);
        u.t -= c;
        time += c;
        if(u.t > 0) enqueue(u);
        else {
            cout << u.name << time;
        }
    }
    return 0;
}
