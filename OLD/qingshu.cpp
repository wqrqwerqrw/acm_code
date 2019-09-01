#include<stdio.h>
#include<math.h>
int main(){
    for(float y = 1.6; y > -1.6; y-=0.05){
        for(float x = 1.6; x > -1.6; x-=0.05){
            double x1 = x * 1.1;
            double y1 = y * 1.1;
            double x2 = x * 2;
            double y2 = y * 2;
            double x3 = x * 2.4;
            double y3 = y * 2.4;
            double a = pow(x*x+y*y-1,3)-x*x*y*y*y;
            double b = pow(x1*x1+y1*y1-1,3)-x1*x1*y1*y1*y1;
            double c = pow(x2*x2+y2*y2-1,3)-x2*x2*y2*y2*y2;
            double d = pow(x3*x3+y3*y3-1,3)-x3*x3*y3*y3*y3;
            if((a < 0 && b > 0) || (c < 0 && d > 0))
                printf("*");
            else 
                printf(" ");
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
