// Author : Wqr_
// Time : 2019/9/8 14:40:43

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 5000 + 10;
int v, e, s, k, chu;
int nor[nmax];
int d[nmax][nmax];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(d, INF, sizeof(d));
        cin >> v >> e >> s >> k >> chu;
        for(int i = 1; i <= k; i++){
            cin >> nor[i];
        }
        int a, b, c;
        for(int i = 1; i <= e; i++){
            cin >> a >> b >> c;
            if(c < d[a][b]){
                d[a][b] = c;
                d[b][a] = c;
            }
        }
        for(int i = 1; i <= v; i++){
            d[i][i] = 0;
        }
        for(int k = 1; k <= v; k++){
            for(int i = 1; i <= v; i++){
                for(int j = 1; j <= v; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int maxnor = -1;
        for(int i = 1; i <= k; i++){
            int minnor = INF;
            for(int j = 1; j <= v; j++){
                if(nor[i] == j) continue;
                if(d[nor[i]][j] >= INF) continue;
                minnor = min(minnor, d[nor[i]][j]);
            }
            if(minnor <= INF)
                maxnor = max(maxnor, minnor);
        }
        int maxher = -1;
        for(int i = 1; i <= v; i++){
            maxher = max(maxher, d[s][i]);
        }
        if(maxher <= maxnor * chu) cout << maxher << endl;
        else cout << maxnor << endl;
    }
    return 0;
}
