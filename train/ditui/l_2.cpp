#include<stdio.h>
int main()
{
    int a[25];
    a[0]=1;
    a[1]=3;
    for(int i=2;i<=20;i++)
    {
            a[i]=2*a[i-1]+a[i-2];
    }
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}
