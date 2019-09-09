// Author : Wqr_
// Time : 2019/9/8 12:55:02

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int vmax = 2000 + 10;
const int kmax = 2000 + 10;
int v, e, s, k, chu;
int nor[kmax];
int d[vmax][vmax];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(d, INF, sizeof(d));
        cin >> v >> e >> s >> k >> chu;
        for(int i = 0; i < k; i++){
            cin >> nor[i];
            nor[i]--;
        }
        int a, b, c;
        for(int i = 0; i < e; i++){
            cin >> a >> b >> c;
            a--, b--;
            d[a][b] = d[b][a] = c;
            d[i][i] = 0;
        }
        for(int k = 0; k < v; k++){
            for(int i = 0; i < v; i++){
                for(int j = 0; j < v; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        int maxnor = -1;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < v; j++){
                if(d[nor[i]][j] >= INF) continue;
                maxnor = max(maxnor, d[nor[i]][j]);
            }
        }
        int maxher = -1;
        for(int i = 0; i < v; i++){
            maxher = max(maxher, d[s][i]);
        }
        double chuher = (double)maxher / chu;
        if(chuher < maxnor) cout << maxher << endl;
        else cout << maxnor << endl;
    }
    return 0;
}
