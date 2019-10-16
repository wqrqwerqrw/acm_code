/*
About: Max_flow ISAP struct STL+BFS 
Auther: kongse_qi
Date: 2017/04/30
*/
#include <bits/stdc++.h>

#define maxn 10005
#define maxm 200005
#define INF 0x3f3f3f
using namespace std;
char *X, *Buffer, c;
int in;
typedef vector<int>::iterator vit;
struct edge {
    int st, en, weight;
    edge() {}
    edge(int s, int e, int w) : st(s), en(e), weight(w) {}
};
struct Isap {
    int st, en, tot, n, m;
    int max_flow;
    int num[maxn];
    int dis[maxn];
    int cur[maxn];
    int pre[maxn];
    vector<int> arc[maxn];
    edge eg[maxm];
    void Init(int st, int en, int n, int m) {
        tot = -1;
        this->st = st;
        this->en = en;
        this->n = n;
        this->m = m;
        for (int i = 1; i != n + 1; ++i) {
            arc[i].clear();
        }
        max_flow = 0;
        memset(cur, 0, sizeof cur);
        memset(num, 0, sizeof num);
        return;
    }
    void add(int s, int e, int w) {
        eg[++tot] = edge(s, e, w);
        eg[++tot] = edge(e, s, 0);
        arc[s].push_back(tot - 1);
        arc[e].push_back(tot);
        return;
    }
    bool Bfs() {
        bool vis[maxn];
        memset(vis, 0, sizeof vis);
        queue<int> q;
        q.push(en);
        vis[en] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (vit i = arc[cur].begin(); i != arc[cur].end(); ++i) {
                edge& ne = eg[*i];
                if (vis[ne.en] == false) {
                    dis[ne.en] = dis[cur] + 1;
                    q.push(ne.en);
                    vis[ne.en] = true;
                }
            }
        }
        if (vis[st] == false) return false;
        return true;
    }
    int Augment(int x) {
        int minn = INF;
        while (x != st) {
            edge& e = eg[pre[x]];
            minn = min(minn, e.weight);
            x = e.st;
        }
        x = en;
        while (x != st) {
            int curr = pre[x];
            eg[curr].weight -= minn;
            eg[curr ^ 1].weight += minn;
            x = eg[curr].st;
        }
        return minn;
    }
    void Advance(int x) {
        while (dis[st] < n) {
            bool vis = false;
            for (int& i = cur[x]; i != arc[x].size(); ++i) {
                edge& e = eg[arc[x][i]];
                if (e.weight > 0 && dis[x] == dis[e.en] + 1) {
                    vis = true;
                    pre[e.en] = arc[x][i];
                    x = e.en;
                    break;
                }
            }
            if (vis == false) {
                int m = n - 1;
                for (vit i = arc[x].begin(); i != arc[x].end(); ++i) {
                    edge& e = eg[*i];
                    if (e.weight > 0) {
                        m = min(m, dis[e.en]);
                    }
                }
                if (--num[dis[x]] == 0) return;
                ++num[dis[x] = m + 1];
                cur[x] = 0;
                if (x != st) x = eg[pre[x]].st;
            }
            if (x == en) {
                max_flow += Augment(en);
                x = st;
            }
        }
        return;
    }
    int Max_flow() {
        Bfs();
        for (int i = 1; i != n + 1; ++i) ++num[dis[i]];
        Advance(st);
        return max_flow;
    }
} doit;

int main() {
    int a, b, c, n, m, st, en;
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &st, &en);
    doit.Init(st, en, n, m);
    for (int i = 0; i != m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        doit.add(a, b, c);
    }
    printf("%d\n", doit.Max_flow());
    return 0;
}