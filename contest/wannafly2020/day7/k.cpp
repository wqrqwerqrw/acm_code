// Wqr_
// Time : 20/01/18
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define int long long
typedef long long ll;
using namespace std;
const int N = 1000 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int a1, a2, n, b1[N], b2[N];
signed main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a1 >> a2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b1[i] >> b2[i];
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        //当前纵坐标
        int ta1 = a1;
        int ta2 = a2;
        int tmpa1;
        int tmpa2;
        int cur1 = 0;
        int cur2 = 0;
        int d1, d2;

        tmpa1 = ta1 + 1;
        tmpa2 = ta2 + 1;
        if (ta1 != 0)
            d1 = ceil(b1[i] / double(ta1));
        else
            d1 = inf;
        if (ta2 != 0)
            d2 = ceil(b2[i] / double(ta2));
        else
            d2 = inf;

        if (d1 == d2) {
            int td1 = ceil((b1[i] - cur1) / double(tmpa1));
            int td2 = ceil((b2[i] - cur2) / double(tmpa2));
            if (td1 > td2)
                ta1++;
            else
                ta2++;
        } else if (d1 > d2)
            ta1++;
        else
            ta2++;

        cur1 += ta1;
        cur2 += ta2;
        int day = 1;
        // cerr << ddd(cur1) << ddd(cur2) << endl;
        // cerr << ddd(ta1) << ddd(ta2) << endl;
        while (cur1 < b1[i] || cur2 < b2[i]) {
            day++;
            if (ta1 != 0)
                d1 = ceil((b1[i] - cur1) / double(ta1));
            else
                d1 = inf;
            if (ta2 != 0)
                d2 = ceil((b2[i] - cur2) / double(ta2));
            else
                d2 = inf;
            if (d1 == d2) {
                int td1 = ceil((b1[i] - cur1) / double(tmpa1));
                int td2 = ceil((b2[i] - cur2) / double(tmpa2));
                if (td1 > td2)
                    ta1++;
                else
                    ta2++;
            } else if (d1 > d2)
                ta1++;
            else
                ta2++;

            cur1 += ta1;
            cur2 += ta2;
            // cerr << ddd(cur1) << ddd(cur2) << endl;
            // cerr << ddd(ta1) << ddd(ta2) << endl;
        }
        // cout << "-"<<endl;
        ans = min(ans, day);
    }
    cout << ans << endl;
    return 0;
}