/*************************************************************************
    > File Name: liuqi1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月31日 星期日 19时05分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int fun(char *s1, char *s2){
    for(int i = 0; i < strlen(s1); i++){
        bool flag = true;
        for(int j = 0; j < strlen(s2); j++){
            if(s1[i + j] != s2[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}
int main(){
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    /*
    printf("%s\n", s1);
    printf("%s\n", s2);
    */
    printf("%d", fun(s1, s2));
    return 0;
}
