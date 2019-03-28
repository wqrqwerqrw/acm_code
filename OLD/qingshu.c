#include<stdio.h>
#include<math.h>
int main(){
    for(float y = 1.6; y > -1.6; y-=0.05){
        for(float x = 1.6; x > -1.6; x-=0.05){
            if(pow(x*x+y*y-1,3)<x*x*y*y*y)printf("*");
            else printf(" ");
            printf(" ");}
        printf("\n");}
    return 0;
}
