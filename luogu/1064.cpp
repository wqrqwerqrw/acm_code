// Wqr_
// Time : 20/01/22
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N = 32000 + 100;
int n, m;
int v[N], p[N], q[N], f[N], t[N];
signed main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    // dbg(n, m);
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q[i];
        p[i] *= v[i];
    }
    for (int i = 1; i <= m; i++) {
        if (!q[i]) {
            for (int j = 1; j < v[i]; j++) t[j] = 0;
            for (int j = v[i]; j <= n; j++) t[j] = f[j - v[i]] + p[i];
            for (int j = 1; j <= m; j++)
                if (q[j] == i)
                    for (int k = n; k >= v[i] + v[j]; k--) t[k] = max(t[k], t[k - v[j]] + p[j]);
            for (int j = v[i]; j <= n; j++) f[j] = max(f[j], t[j]);
        }
    }
    // for(int i = 1; i <= n; i++) dbg(f[i]);
    cout << f[n] << endl;
    return 0;
}