/*************************************************************************
    > File Name: 3414.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Mar 12 18:26:50 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct node{
    int step; 
    int a;
    int b;
    int mark;
    int front;
    int opera;
};
int maxa;
int maxb;
node full(node in, int i){
    in.opera;
    if(i == 1) in.a = maxa; 
    else in.b = maxb;
    in.step += 1;
    return in;
}
node drop(node in, int i){
    if(i == 1) in.a = 0;
    else in.b = 0;
    in.step += 1;
    return in;
}
node pour(node in, int i, int j){
    if(i == 1){
        for(int m = 0; ; m++){
            if(in.b == maxb || in.a == 0) break;
            in.a--;
            in.b++;
        }
    }else{
        for(int m = 0; ; m++){
            if(in.a == maxa || in.b == 0) break;
            in.a++;
            in.b--;
        }
    }
    in.step += 1;
    return in;
}
void bfs(int a, int b, int c){
    int marknum = 0;
    map<int, node> mark;
    queue<node> q;
    node first;
    node null;
    first.a = a;
    first.b = b;
    first.mark = 0;
    mark[marknum++] = first;
    first.mark = marknum;
    q.push(first);
    bool flag = true;
    while(!q.empty() && flag){
        node get = q.front();
        node tmp;
        for(int i = 1; i < 3; i++){
            // pull
            tmp = full(get, i);
            mark[marknum++] = tmp;
            tmp.front = first.mark;
            tmp.mark = marknum;
            tmp.opera = 1;
            q.push(tmp);
            if(tmp.a == c || tmp.b == c){
                flag = false;
                break;
            }

            // drop
            tmp = drop(get, i);
            mark[marknum++] = tmp;
            tmp.front = first.mark;
            tmp.mark = marknum;
            tmp.opera = 2;
            q.push(tmp);
            if(tmp.a == c || tmp.b == c){
                flag = false;
                break;
            }

            //pour
            if(i == 1) tmp = pour(get, 1, 2);
            else tmp = pour(get, 2, 1);
            mark[marknum++] = tmp;
            tmp.front = first.mark;
            tmp.mark = marknum;
            tmp.opera = 3;
            q.push(tmp);
            if(tmp.a == c || tmp.b == c){
                flag = false;
                break;
            }
            cout << 1 << endl;
        }
        q.pop();
        if(flag) break;
    }
    if(!flag){
        cout << q.back().step << endl;
        node tmp = q.back();
    }
    else{
        cout << "impossible" << endl;
    }
}
int main(){
    int c;
    cin >> maxa >> maxb >> c;
    bool flag = true;
    if(c > maxa && c > maxb)
        bfs(0, 0, c);
    else 
        cout << "impossible";
    return 0;
}
