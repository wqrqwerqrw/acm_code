// Author : Wqr_
// Time : 2019/9/8 9:32:00

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int nmax = 200 + 10;
struct per{
    int a, b, num, place;
}ps[nmax], psa[nmax], psb[nmax];
vector<per> ans;
int n;
int main(){
    iofuck;
    while(cin >> n && n){
        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            ps[i].num = i + 1;
            ps[i].a = a;
            ps[i].b = b;
            psa[i] = ps[i];
            psb[i] = ps[i];
        }
        sort(psa, psa + n, [](per &p1, per &p2){return p1.a > p2.a;});
        sort(psb, psb + n, [](per &p1, per &p2){return p1.b > p2.b;});
        int anum = 0, bnum = 0;
        int ansnum = 0;
        for(int i = 0 ; anum < 8; i++){
            bool iffind = 0;
            for(int j = 0; j < 8; j++){
                if(psb[j].num == psa[i].num){
                    iffind = 1;
                }
            }
            if(!iffind){
                per tmp = psa[i];
                tmp.place = 1;
                ans.push_back(tmp);
                anum++;
                ansnum += tmp.a;
            }else{
                if(psa[i].a >= psa[i].b){
                    per tmp = psa[i];
                    tmp.place = 1;
                    ans.push_back(tmp);
                    anum++;
                    ansnum += tmp.a;
                }
            }
        }
        for(int i = 0 ; bnum < 8; i++){
            bool iffind = 0;
            for(int j = 0; j < 8; j++){
                if(psb[i].num == psa[j].num){
                    iffind = 1;
                }
            }
            if(!iffind){
                per tmp = psb[i];
                tmp.place = 2;
                ans.push_back(tmp);
                bnum++;
                ansnum += tmp.b;
            }else{
                if(psb[i].b > psa[i].a){
                    per tmp = psb[i];
                    tmp.place = 2;
                    ans.push_back(tmp);
                    bnum++;
                    ansnum += tmp.b;
                }
            }
        }
        sort(ans.begin(), ans.end(), [](per &a, per &b){return a.num < b.num;});
        cout << ansnum << endl;
        for(auto i : ans){
            cout << i.num << " " << i.a << " " << i.b << " " << i.place << endl;
        }
    }
    return 0;
}
