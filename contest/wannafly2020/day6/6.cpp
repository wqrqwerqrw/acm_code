// Wqr_
// Time : 20/01/17
#include <stdio.h>
int n, a, b, c, p, d, ans;
int main(){
    // freopen("in.txt","r",stdin);
    scanf("%d", &n);
    scanf("%d%d%d%d%d", &a, &b, &c, &p, &d);
    int i, j, k;
    bool ta, tb, tc;
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            for(k = j + 1; k <= n; k++){
                ta = (a*(i+j)*(i+j)+b*(i-j)*(i-j)+c)%p>d;
                tb = (a*(i+k)*(i+k)+b*(i-k)*(i-k)+c)%p>d;
                tc = (a*(k+j)*(k+j)+b*(k-j)*(k-j)+c)%p>d;
                if(ta == tb && tb == tc) ++ans;
            }
        }
    }
    printf("%d", ans);
    return 0;
}