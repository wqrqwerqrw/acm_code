#include<cstdio>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bbt;
int n;ll k,ans;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
} 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=read();
    for(int i=1,opt;i<=n;i++){
        opt=read();k=read();
        if(opt==1) bbt.insert((k<<20)+i);
        if(opt==2) bbt.erase(bbt.lower_bound(k<<20));
        if(opt==3) printf("%d\n",bbt.order_of_key(k<<20)+1);
        if(opt==4) ans=*bbt.find_by_order(k-1),printf("%lld\n",ans>>20);
        if(opt==5) ans=*--bbt.lower_bound(k<<20),printf("%lld\n",ans>>20);
        if(opt==6) ans=*bbt.upper_bound((k<<20)+n),printf("%lld\n",ans>>20);
    }
    return 0;
}