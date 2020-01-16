/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/05
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> jipos;
    vector<int> oupos;
    vector<int> pos;
    int jinum = 0;
    int ounum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2)
            jinum++;
        else
            ounum++;
    }
    int ttt1 = 0, ttt2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == 0) continue;
        if (p[i] % 2) {
            ttt1++;
            jinum--;
            p[i] = 1;
            jipos.push_back(i);
            pos.push_back(i);
        } else {
            ttt2++;
            ounum--;
            p[i] = 2;
            oupos.push_back(i);
            pos.push_back(i);
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1000000;
    vector<int> ptmp = p;
    int jitmp = jinum;
    int outmp = ounum;
    int anstmp = 0;
    for (int i = 0; i < pos.size(); i++) {
        if (i < pos.size() - 1) {
            if (pos[i] == pos[i + 1]) {
                for (int j = pos[i] + 1; j < n; j++) {
                    if (jitmp == 0) break;
                    if (outmp == 0) break;
                    if (p[j]) break;
                    if (ptmp[j]) break;
                    ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
                }
            }
        }
        for (int j = pos[i] + 1; j < n; j++) {
            if (jitmp == 0) break;
            if (outmp == 0) break;
            if (p[j]) break;
            if (ptmp[j]) break;
            ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
        }
        for (int j = pos[i] - 1; j >= 0; j--) {
            if (jitmp == 0) break;
            if (outmp == 0) break;
            if (p[j]) break;
            if (ptmp[j]) break;
            ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ptmp[i] == 0) {
            if (outmp) ptmp[i] = 2;
            if (jitmp) ptmp[i] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (ptmp[i] != ptmp[i + 1]) {
            anstmp++;
        }
    }
    ans = min(ans, anstmp);

    ptmp = p;
    jitmp = jinum;
    outmp = ounum;
    anstmp = 0;
    for(int i = 0; i < pos.size(); i++){
        if(i < pos.size() - 1){
            if(pos[i] == pos[i+1]){
                for(int j = pos[i] + 1; j < n; j++){
                    if(jitmp == 0) break;
                    if(outmp == 0) break;
                    if(p[j]) break;
                    if(ptmp[j]) break;
                    ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
                }
            }
        }
        for (int j = pos[i] - 1; j >= 0; j--) {
            if (jitmp == 0) break;
            if (outmp == 0) break;
            if (p[j]) break;
            if (ptmp[j]) break;
            ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
        }
        for (int j = pos[i] + 1; j < n; j++) {
            if (jitmp == 0) break;
            if (outmp == 0) break;
            if (p[j]) break;
                    if(ptmp[j]) break;
            ptmp[j] = ptmp[pos[i]];
                    if (ptmp[pos[i]] == 2) outmp--;
                    if (ptmp[pos[i]] == 1) jitmp--;
        }
    }
    for(int i = 0; i < n; i++){
        if(ptmp[i] == 0){
            if(outmp) ptmp[i] = 2;
            if(jitmp) ptmp[i] = 1;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(ptmp[i] != ptmp[i+1]){
            anstmp++;
        }
    }
    ans = min(ans, anstmp);
    ptmp = p;
    jitmp = jinum;
    outmp = ounum;
    anstmp = 0;
    for(int i = 0; i < jipos.size(); i++){
        int pos = jipos[i];
        if(jitmp == 0) break;
        if(jipos[i-1] == pos-1){

        }
        if(jipos[i+1] == pos+1)
        for(int i = pos - 1; i >= 0 && jitmp > 0; i--){
            if(ptmp[i] != 0) break;
            ptmp[i] = 1;
            jitmp--;
        }
        for(int i = pos + 1; i < n && jitmp > 0; i++){
            if(ptmp[i] != 0) break;
            ptmp[i] = 1;
            jitmp--;
        }
    }
    for(auto pos : oupos){
        if(outmp == 0) break;
        for(int i = pos - 1; i >= 0 && outmp > 0; i--){
            if (ptmp[i] != 0) break;
            ptmp[i] = 2;
            outmp--;
        }
        for(int i = pos + 1; i < n && outmp > 0; i++){
            if (ptmp[i] != 0) break;
            ptmp[i] = 2;
            outmp--;
        }
    }
    for(int i = 0; i < n; i++){
        if(ptmp[i] == 0){
            if(outmp) ptmp[i] = 2;
            if(jitmp) ptmp[i] = 1;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(ptmp[i] != ptmp[i+1]){
            anstmp++;
        }
    }
///////////////////////////////////
    ans = min(ans, anstmp);
    ptmp = p;
    jitmp = jinum;
    outmp = ounum;
    anstmp = 0;
    for(auto pos : oupos){
        if(outmp == 0) break;
        for(int i = pos - 1; i >= 0 && outmp > 0; i--){
            if (ptmp[i] != 0) break;
            ptmp[i] = 2;
            outmp--;
        }
        for(int i = pos + 1; i < n && outmp > 0; i++){
            if (ptmp[i] != 0) break;
            ptmp[i] = 2;
            outmp--;
        }
    }
    for(auto pos : jipos){
        if(jitmp == 0) break;
        for(int i = pos - 1; i >= 0 && jitmp > 0; i--){
            if(ptmp[i] != 0) break;
            ptmp[i] = 1;
            jitmp--;
        }
        for(int i = pos + 1; i < n && jitmp > 0; i++){
            if(ptmp[i] != 0) break;
            ptmp[i] = 1;
            jitmp--;
        }
    }
    for(int i = 0; i < n; i++){
        if(ptmp[i] == 0){
            if(outmp) ptmp[i] = 2;
            if(jitmp) ptmp[i] = 1;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(ptmp[i] != ptmp[i+1]){
            anstmp++;
        }
    }
    ans = min(ans, anstmp);
    cout << ans << endl;
    return 0;
}