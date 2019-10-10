#include <bits/stdc++.h>

using namespace std;

class node {
  public:
    pair<int, int> val;
    int tag;

    void apply(int l, int r, int v) {
        val.first += v;
        tag += v;
    }
};

class segtree {
  public:
    vector<node> tree;
    int n;

    node unite(const node &l, const node &r) {
        node res;
        res.val = min(l.val, r.val);
        return res;
    }

    segtree(int n) : n(n) {
        tree.resize(n * 2 - 1);
        build(0, 0, n - 1);
    }

    void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }

    void push(int x, int l, int r) {
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        if (tree[x].tag) {
            tree[x + 1].apply(l, y, tree[x].tag);
            tree[z].apply(y + 1, r, tree[x].tag);
            tree[x].tag = 0;
        }
    }

    void build(int x, int l, int r) {
        tree[x].val = make_pair(0, l);
        if (l != r) {
            int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
            build(x + 1, l, y);
            build(z, y + 1, r);
        }
    }

    template <typename... T>
    void modify(int x, int l, int r, int ll, int rr, const T &... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
        } else {
            int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
            push(x, l, r);
            if (ll <= y) {
                modify(x + 1, l, y, ll, rr, v...);
            }
            if (rr > y) {
                modify(z, y + 1, r, ll, rr, v...);
            }
            pull(x, z);
        }
    }

    node query(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        } else {
            int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
            push(x, l, r);
            if (rr <= y) {
                return query(x + 1, l, y, ll, rr);
            } else if (ll > y) {
                return query(z, y + 1, r, ll, rr);
            } else {
                return unite(query(x + 1, l, y, ll, rr),
                             query(z, y + 1, r, ll, rr));
            }
        }
    }

    template <typename... T> void modify(int l, int r, const T &... v) {
        modify(0, 0, n - 1, l, r, v...);
    }

    node query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

struct point {
    long long x, y;

    point(long long x = 0, long long y = 0) : x(x), y(y) {}

    point operator-(const point &o) const { return point(x - o.x, y - o.y); }

    long double slope() { return (long double)y / x; }
};

const int B = 500;
const int INF = (int)1e9;

int main() {
#ifdef Wqr_
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    vector<int> p(n, -1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        g[--p[i]].push_back(i);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> sa(n);
    vector<int> sb(n);
    vector<int> left(n);
    vector<int> right(n);
    int time = 0;
    function<void(int)> dfs = [&](int x) {
        left[x] = time++;
        sa[x] += a[x];
        sb[x] += b[x];
        for (auto y : g[x]) {
            sa[y] += sa[x];
            sb[y] += sb[x];
            dfs(y);
        }
        right[x] = time - 1;
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        a[left[i]] = sa[i];
        b[left[i]] = sb[i];
    }
    for (int i = 0; i < n; ++i) {
        b[i] = abs(b[i]);
    }
    vector<bool> pos(n);
    segtree seg(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            seg.modify(i, i, -a[i]);
        } else {
            seg.modify(i, i, INF);
            pos[i] = true;
        }
    }
    int m = (n - 1) / B + 1;
    vector<vector<point>> ch(m);
    vector<vector<int>> ord(m);
    vector<long long> mem(m);
    vector<int> off(m);
    auto extend = [&](vector<point> &v, point p) {
        if (!v.empty() && v.back().x == p.x) {
            if (v.back().y >= p.y) {
                return;
            } else {
                v.pop_back();
            }
        }
        while ((int)v.size() > 1 && (p - v[v.size() - 2]).slope() >=
                                        (v.back() - v[v.size() - 2]).slope()) {
            v.pop_back();
        }
        v.push_back(p);
    };
    auto build = [&](int u) {
        ch[u].clear();
        for (auto i : vector<int>(ord[u].rbegin(), ord[u].rend())) {
            if (!pos[i]) {
                extend(ch[u], point(-b[i], -(long long)a[i] * b[i]));
            }
        }
        for (auto i : ord[u]) {
            if (pos[i]) {
                extend(ch[u], point(b[i], (long long)a[i] * b[i]));
            }
        }
        mem[u] = -1;
    };
    auto init = [&](int u) {
        int l = u * B, r = min(n, (u + 1) * B);
        for (int i = l; i < r; ++i) {
            ord[u].push_back(i);
        }
        sort(ord[u].begin(), ord[u].end(),
             [&](int x, int y) { return b[x] < b[y]; });
        build(u);
    };
    auto get = [&](int p) { return (long long)abs(a[p] + off[p / B]) * b[p]; };
    auto query = [&](int u) {
        if (mem[u] != -1) {
            return mem[u];
        }
        int l = 0, r = ch[u].size() - 1, z = off[u];
        while (l < r) {
            int mid = (l + r) >> 1;
            long long foo = ch[u][mid].x * z + ch[u][mid].y;
            long long bar = ch[u][mid + 1].x * z + ch[u][mid + 1].y;
            if (foo <= bar) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return mem[u] = ch[u][r].x * z + ch[u][r].y;
    };
    auto flip = [&](int p) {
        pos[p] = true;
        seg.modify(p, p, INF);
        build(p / B);
    };
    auto modify = [&](int l, int r, int v) {
        seg.modify(l, r, -v);
        while (true) {
            node z = seg.query(l, r);
            if (z.val.first < 0) {
                flip(z.val.second);
            } else {
                break;
            }
        }
        int bl = l / B;
        int br = r / B;
        if (bl == br) {
            for (int i = l; i <= r; ++i) {
                a[i] += v;
            }
            build(bl);
        } else {
            for (int i = l; i / B == bl; ++i) {
                a[i] += v;
            }
            build(bl);
            for (int i = bl + 1; i < br; ++i) {
                off[i] += v;
            }
            for (int i = r; i / B == br; --i) {
                a[i] += v;
            }
            build(br);
        }
    };
    auto solve = [&](int l, int r) {
        long long ans = 0;
        int bl = l / B;
        int br = r / B;
        if (bl == br) {
            for (int i = l; i <= r; ++i) {
                ans = max(ans, get(i));
            }
        } else {
            for (int i = l; i / B == bl; ++i) {
                ans = max(ans, get(i));
            }
            for (int i = bl + 1; i < br; ++i) {
                ans = max(ans, query(i));
            }
            for (int i = r; i / B == br; --i) {
                ans = max(ans, get(i));
            }
        }
        return ans;
    };
    for (int i = 0; i < m; ++i) {
        init(i);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            --x;
            modify(left[x], right[x], y);
        } else {
            int x;
            cin >> x;
            --x;
            cout << solve(left[x], right[x]) << "\n";
        }
    }
    return 0;
}