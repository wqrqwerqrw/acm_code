// Author : Wqr_
// Time : 19/09/09
// 50ms
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define IN freopen("in.txt", "r", stdin);
using namespace std;
typedef long long ll;
const int nmax = 1000 + 10;
struct light
{
    int v, k, c, l;
} ls[nmax];
int n;
int dp[nmax], s[nmax];
int main()
{
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> ls[i].v >> ls[i].k >> ls[i].c >> ls[i].l;
        }
        sort(ls + 1, ls + 1 + n, [](light &a, light &b) { return a.v < b.v; });
        s[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + ls[i].l;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = s[i] * ls[i].c + ls[i].k;
            for (int j = 1; j <= i; j++)
            {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * ls[i].c + ls[i].k);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}