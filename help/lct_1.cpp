 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-18 14:43:51
 # @Description: You build it.You run it
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
typedef long long ll;
const int maxn = 5000;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int s[maxn],c[maxn];
int ans;
int n ;
int flag2,flag1,cnt1,cnt2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ans = INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int j = 2; j <= n - 1; j++) {
        flag1 = 0, flag2 = 0;
        cnt1 = c[j];
        for (int i = 1; i < j; i++) {
            if (s[i] < s[j]) {
                if (flag1 == 0)
                    flag1 = 1, cnt1 += c[i];
                else
                    cnt1 = min(c[i] + c[j], cnt1);
            }
        }
        cnt2 = cnt1;
        for (int k = j + 1; k <= n; k++) {
            if (s[j] < s[k]) {
                if (flag2 == 0) {
                    flag2 = 1, cnt2 += c[k];
                    ans = min(cnt2, ans);
                } else {
                    cnt2 = min(cnt1 + c[k], cnt2);
                    ans = min(ans, cnt2);
                }
            }
        }
    }
    if (ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}
