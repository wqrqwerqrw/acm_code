#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
   解题思路：合法格子数和方法数有一种映射关系 
   当涂第n个格子时第n-1个格子有两种状态
   1.和第一个格子相同颜色,不合法
   则n-2个格子和第n-1个格子颜色不同，n-2个格子合法.则f[n] =2f[n-2]； 
   2和第一个格子不同颜色，合法 
   则f[n]只有一种颜色机会f[n]=f[n-1]；
   参考大佬的：https://blog.csdn.net/lsgqjh/article/details/44968881 
   */
int main(int argc, char *argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF){
        double f[100]={0,3,6,6};//不能用int ，数会越界？ 
        int i;
        for(i=4;i<=50;++i){
            f[i]=2*f[i-2]+f[i-1];//f是合法函数 
        }
        printf("%.lf\n",f[n]);//.lf行。0lf却不行？ 
    }
    return 0;
}
