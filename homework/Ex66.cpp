#include <bits/stdc++.h>
#define INF 1 << 28
using namespace std;
struct road {
    int to, cost;
};
// first为最短距离, second为编号
typedef pair<int, int> P;
int n, t;
vector<road> G[1010];
int d[1010];
int per[1010];

void dij(int f) {
    //优先队列 首先按照pair.first进行排序, first相同时按照second进行排序
    priority_queue<P, vector<P>, greater<P> > q;
    fill(d, d + n + 1, INF);
    d[f] = 0;
    q.push(P(0, f));
    while (!q.empty()) {
        //每次选择出距离f最近的点为v
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        // 以v为跳板更新其他边的最小距离
        for (int i = 0; i < G[v].size(); i++) {
            road e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
                per[e.to] = v;
            }
        }
    }
}
int main() {
    // t条边 n个节点
    cin >> t >> n;
    int a, b, c;
    // 邻接表的输入
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        road tmp;
        tmp.to = b;
        tmp.cost = c;
        //将各个边push进G[a]
        G[a].push_back(tmp);
        tmp.to = a;
        tmp.cost = c;
        //将各个边push进G[b]
        G[b].push_back(tmp);
    }
    dij(1);
    for(int i = 2; i <= n; i++){
        cout << d[i] << endl;
        int j = i;
        vector<int> pat;
        pat.push_back(i);
        for(int j = i; j >= 2; j--){
            pat.push_back(per[j]);
        }
        for(int j = pat.size() - 1; j >= 0; j--) cout << pat[j] << ' ';
        cout << endl;
    }
    return 0;
}

/*
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
*/