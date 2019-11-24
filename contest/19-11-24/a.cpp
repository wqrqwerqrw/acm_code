#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
double a[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        double ans = 0;
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lf", &a[i]);
            ans = max(ans, a[i]);
        }
        printf("%.10f\n", ans);
    }


    return 0;
}