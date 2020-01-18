#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree : tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mem0(a) memset((a), 0, sizeof(a))
#define mem(a, b) memset((a), (b), sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;

const int N = 110;

char a[N][N];
map<pii, int> mp;
map<pii, int> mp2;
queue<pii> q;
int dy[8] = {-1, -1, 1, 1, 2, 2, -2, -2};
int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int n, m;
void bfs() {
    while (!q.empty()) {
        pii tp = q.front();
        q.pop();
        mp[tp]++;
        for (int i = 0; i < 8; i++) {
            int xx = tp.fi + dx[i], yy = tp.se + dy[i];
            if (xx >= 1 && yy >= 1 && xx <= n && yy <= m) {
                if (mp[{xx, yy}]) continue;
                if (dy[i] == -2 && a[tp.fi][tp.se - 1] == 'X')
                    continue;
                else if (dy[i] == 2 && a[tp.fi][tp.se + 1] == 'X')
                    continue;
                else if (dx[i] == -2 && a[tp.fi - 1][tp.se] == 'X')
                    continue;
                else if (dx[i] == 2 && a[tp.fi + 1][tp.se] == 'X')
                    continue;
                q.push({xx, yy});
                mp[{xx, yy}]++;
                mp2[{xx, yy}] = mp2[tp] + 1;
            }
        }
    }
}

int main() {
    IOS;
    cin >> n >> m;
    pii st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] + 1;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'M') st.fi = i, st.se = j;
    }
    q.push(st);
    mp2[st] = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == st.fi && j == st.se) {
                cout << 0;
                if (j != m) cout << ' ';
                continue;
            }
            if (mp2[{i, j}])
                cout << mp2[{i, j}];
            else
                cout << -1;
            if (j != m) cout << ' ';
        }
        if (i != n) cout << endl;
    }
    return 0;
}
