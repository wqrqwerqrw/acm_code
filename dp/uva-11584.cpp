// Author : Wqr_
// Time : 19/09/10
// 60ms with lambda
// 50ms with normal way
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 1000 + 10;
int p[nmax][nmax], dp[nmax], kase = 0;
bool vis[nmax][nmax];
string str;
bool isp(int l, int r){
    if (l >= r)
        return 1;
    if (str[l] != str[r])
        return 0;
    if (vis[l][r] == kase)
        return p[l][r];
    vis[l][r] = kase;
    p[l][r] = isp(l + 1, r - 1);
    return p[l][r];
}


int main()
{
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        kase++;
        cin >> str;
        str = " " + str;
        dp[0] = 0;
        for (int i = 1; i < str.length(); i++)
        {
            dp[i] = i + 1;
            for (int j = 0; j < i; j++)
            {
                if (isp(j + 1, i))
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        cout << dp[str.length() - 1] << endl;
    }
    return 0;
}