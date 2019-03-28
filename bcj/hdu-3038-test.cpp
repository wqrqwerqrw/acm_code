#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N =200010;
int father[N];
int sum[N];  ///记录当前结点到根结点的距离

int _find(int x){
    if(x!=father[x]){
        int t = father[x];
        father[x] = _find(father[x]);
        sum[x]+=sum[t];
    }
    return father[x];
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<=n;i++){
            father[i] = i;
            sum[i] = 0;
        }
        int ans = 0;
        while(m--){
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            a--;
            int roota = _find(a);
            int rootb = _find(b);
            if(roota==rootb){
                if(sum[a]-sum[b]!=v) ans++;  ///精华部分1
            }
            else{
                father[roota] = rootb;
                sum[roota] = -sum[a]+sum[b]+v; ///精华部分2
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
