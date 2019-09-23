// Author : Wqr_
// Time : 19/09/22
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 10000;
struct Splay{
    struct node{
        int val, fa; // 节点值 父节点
        int ch[2]; // lson->0, rson->1
        int sum; // 自家+自己下级有多少节点, 根节点为1
        int recy; //自己被重复多少次 
    }ns[maxn];
    int& rn = ns[0].ch[1]; // 根节点
    int n, points; //使用储存数, 元素数量
    void update(int x){ //更新当前节点sum值
        ns[x].sum = ns[ns[x].ch[0]].sum + ns[ns[x].ch[1]].sum + ns[x].recy;
    }
    int id(int x) { return ns[ns[x].fa].ch[0] == x ? 0 : 1; }
    void con(int x, int f, int son){ //连接函数
        ns[x].fa = f;
        ns[f].ch[son] = x;
    } //作用：将x连接在f的下方。连接方向由son的值决定。
    void rotate(int cur) {  //旋转节点
        //将被指定的节点x向上移动一级,并将x父级节点作为x的儿子
        /*
        原顺序    R                                旋转后        R
                ↙ ↘                                           ↙ ↘ 
                  cur                                           cur
                  ↙ ↘    con(B, y)->con(y, x)->con(x, R);       ↙ ↘
                 x   C                                         A   y
                ↙ ↘                                               ↙ ↘
               A   B                                             B   C
        其中只有x, y, C的父子关系发生了改变 
        */
        int f = ns[cur].fa;
        int r = ns[f].fa;
        int Rson = id(f);
        int fson = id(cur);
        int B = ns[cur].ch[fson ^ 1];
        con(B, f, fson);
        con(f, cur, (fson ^ 1));
        con(cur, r, Rson);
        update(cur), update(f);
    }
    void splay(int nc, int to){
        int to = ns[nc].fa;
        while(ns[nc].fa != to){
            int nf = ns[nc].fa;
            if(ns[nf].fa == to) rotate(nc);
            else if(id(nc) == id(nf)){
                rotate(nf);
                rotate(nc);
            }else{
                rotate(nc);
                rotate(nc);
            }
        }
    }
};

int main() {
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}