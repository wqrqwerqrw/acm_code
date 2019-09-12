// Author : Wqr_
// Time : 19/09/12
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
string str;
const int maxn = 100 + 10;
int n, dp[maxn][maxn];
auto match = [](char &a, char &b) {
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    return 0;
};
void pr(int i, int j) {
    if (i > j)
        return;
    if (i == j) {
        if (str[i] == '(' || str[i] == ')')
            cout << "()";
        else
            cout << "[]";
        return;
    }
    int &ans = dp[i][j];
    if (match(str[i], str[j]) && ans == dp[i + 1][j - 1]) {
        cout << str[i];
        pr(i + 1, j - 1);
        cout << str[j];
        return;
    }
    for (int k = i; k < j; k++) {
        if (ans == dp[i][k] + dp[k + 1][j]) {
            pr(i, k);
            pr(k + 1, j);
            return;
        }
    }
}
int main() {
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    string tmp;
    cin >> t;
    cin.get();
    getline(cin, tmp);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        getline(cin, str);
        getline(cin, tmp);
        n = str.length();
        for (int i = 0; i < n; i++) {
            dp[i + 1][i] = 0;
            dp[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = n;
                if (match(str[i], str[j]))
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        pr(0, n - 1);
        cout << endl;
        if(t) cout << endl;
    }
    return 0;
}