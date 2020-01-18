#include<bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree: tree<T,null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>{};
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
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

int a[110];
VI v[2];

int main(){
    IOS;
    for(int i=1;i<=20;i++)a[i]=i;
    for(int i=1;i<=18;i++) {
        for(int j=1;j<=i;j++)a[j]=j;
        ll s=0;
        do {
            bool F=0;
            for(int j=0;j<=(1LL<<i)-1;j++){
                v[0].clear();
                v[1].clear();
                for(int z=1;z<=i;z++){
                    if(j&(1LL<<(z-1)))v[0].eb(a[z]);
                    else v[1].eb(a[z]);
                }
                bool f=0;
                if((!sz(v[0]))||(!sz(v[1])))f=1;
                int maxi=0,mini=inf;
                for(int zz=0;zz<sz(v[0]);zz++){
                    if(v[0][zz]<maxi){f=1;break;}
                    maxi=max(maxi,v[0][zz]);
                }
                for(int zz=0;zz<sz(v[1]);zz++){
                    if(v[1][zz]>mini){f=1; break;}
                    mini=min(mini,v[1][zz]);
                }
                if(!f){F=1;break;}
            }
            if(F)s++;
        } while (next_permutation(a+1,a+1+i));
        cerr << debug(i) << debug(s) << endl;
    }
    return 0;
}
