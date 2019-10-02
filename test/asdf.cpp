#include<cstdio>
#include<cctype>
typedef long long LL;
int n,k,md,pre[5000005],suf[5000005],a[5000005];
char buf[(int)1e8],*ss=buf;
//inline int init(){buf[fread(buf,1,(int)1e8-1,stdin)]='\n';fclose(stdin);return 0;}
//const int __START__=init();
inline int readint(){
    int d=0;
    while(!isdigit(*ss))++ss;
    while(isdigit(*ss))d=d*10+(*ss++^'0');
    return d;
}
inline int Inv(const int p){
    if(p==1)return 1;
    return((LL)(md-md/p)*Inv(md%p)%md);
}
int main(){
    n=readint(),md=readint(),k=readint();
    int ans=0;
    for(register int i=*pre=suf[n+1]=1;i<=n;++i)
    pre[i]=(LL)pre[i-1]*(a[i]=readint())%md;
    for(register int i=n;i;--i)
    suf[i]=(LL)suf[i+1]*a[i]%md;
    for(register int i=1,j=k;i<=n;++i,j=(LL)j*k%md)
    ans=(ans+(LL)j*pre[i-1]%md*suf[i+1])%md;
    printf("%lld",ans*(LL)Inv(pre[n])%md);
    return 0;
}
