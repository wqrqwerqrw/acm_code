/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/06
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
bool isPrime(ll num) {
    if (num == 2 || num == 3)
        return 1;
    if (num % 6 != 1 && num % 6 != 5)
        return 0;
    ll tmp = sqrt(num);
    for (ll i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    return 1;
}

bool isPrime_2( ll num )
{
     ll tmp =sqrt( num);
     for(int i= 2;i <=tmp; i++)
        if(num %i== 0)
          return 0 ;
     return 1 ;
}
int32_t main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    while (cin >> n) {
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 0) {
            cout << 2 << endl;
            continue;
        }
        if (isPrime_2(n)) {
            cout << n << endl;
            continue;
        }
        ll sq = sqrt(n);
        for (ll i = 2; i <= sq; i++) {
            if (n % i == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}