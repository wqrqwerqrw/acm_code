/*************************************************************************
    > File Name: 1034.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com
    > Created Time: Thu Mar 14 19:47:22 2019
 ************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
bool book[400000];
int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int in[9], curx;
struct node {
    int num[9];
    int cur;
    int cantor;
    vector<char> step;
};
int Cantor(int* in) {
    int ans = 1;
    for (int i = 0; i < 9; i++) {
        int k = 0;
        for (int j = i + 1; j < 9; j++) {
            if (in[j] < in[i]) k++;
        }
        ans += k * fac[9 - 1 - i];
    }
    return ans;
}
node opera(int ope, node nodein) {
    int t;
    switch (ope) {
        case 0:
            t = nodein.num[nodein.cur - 3];
            nodein.num[nodein.cur - 3] = nodein.num[nodein.cur];
            nodein.num[nodein.cur] = t;
            nodein.cur = nodein.cur - 3;
            nodein.step.push_back('u');
            break;
        case 1:
            t = nodein.num[nodein.cur + 3];
            nodein.num[nodein.cur + 3] = nodein.num[nodein.cur];
            nodein.num[nodein.cur] = t;
            nodein.cur = nodein.cur + 3;
            nodein.step.push_back('d');
            break;
        case 2:
            t = nodein.num[nodein.cur - 1];
            nodein.num[nodein.cur - 1] = nodein.num[nodein.cur];
            nodein.num[nodein.cur] = t;
            nodein.cur = nodein.cur - 1;
            nodein.step.push_back('l');
            break;
        case 3:
            t = nodein.num[nodein.cur + 1];
            nodein.num[nodein.cur + 1] = nodein.num[nodein.cur];
            nodein.num[nodein.cur] = t;
            nodein.cur = nodein.cur + 1;
            nodein.step.push_back('r');
    }
    nodein.cantor = Cantor(nodein.num);
    return nodein;
}
void bfs() {
    memset(book, 0, sizeof(book));
    node first;
    for (int i = 0; i < 9; i++) first.num[i] = in[i];
    first.cantor = Cantor(first.num);
    first.cur = curx;
    book[first.cantor] = 1;
    queue<node> q;
    q.push(first);
    bool flag = true;
    while (!q.empty() && flag) {
        node get = q.front();
        node tmp;
        // u, d, l, r
        int curg = get.cur;
        if (get.cantor == 46234) {
            q.back().step.push_back('l');
            q.back().step.push_back('r');
            flag = false;
            break;
        }
        for (int i = 0; i < 4; i++) {
            if (i == 0 && curg - 3 < 0) continue;
            if (i == 1 && curg + 3 > 8) continue;
            if (i == 2) {
                if (curg - 1 == -1 || curg - 1 == 2 || curg - 1 == 5) continue;
            }
            if (i == 3) {
                if (curg + 1 == 3 || curg + 1 == 6 || curg + 1 == 9) continue;
            }
            tmp = opera(i, get);
            if (book[tmp.cantor]) continue;
            q.push(tmp);
            book[tmp.cantor] = 1;
            if (tmp.cantor == 46234) {
                flag = false;
                break;
            }
        }
        q.pop();
    }
    if (flag)
        cout << "unsolvable" << endl;
    else {
        node out = q.back();
        for(int i = 0; i < out.step.size(); i++){
            cout << out.step[i];
        }
        cout << endl;
    }
}
int main() {
    char charin;
    int i = 0;
    while (cin >> charin) {
        if (charin == 'x') {
            in[i] = 0;
            curx = i;
        } else
            in[i] = charin - '0';
        i++;
        if (i == 9) {
            bfs();
            i = 0;
        }
    }
    return 0;
}
