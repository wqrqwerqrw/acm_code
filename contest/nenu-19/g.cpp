// Author : Wqr_
// Time : _20_19年07月_2_2日 星期一 _1_2时55分04秒
#include<cmath>
#include<iostream>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
struct point{
    int x, y;
}li, f1, f2, f3, f4;
int x, y, x_1, y_1, x_2, y_2;
double getdis(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(){
    cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;
    li.x = x, li.y = y;
    f4.x = x_1, f4.y = y_1;
    f2.x = x_2, f2.y = y_2;
    f1.x = x_1, f1.y = y_2;
    f3.x = x_2, f3.y = y_1;
    if(x >= x_1 && x <= x_2){
        if(y >= y_2) printf("%.3f", (double)(y - y_2));
        if(y <= y_1) printf("%.3f", (double)(y_1 - y));
    }
    if(y >= y_1 && y <= y_2){
        if(x >= x_2) printf("%.3f", (double)(x - x_2));
        if(x <= x_1) printf("%.3f", (double)(x_1 - x));
    }
    if(x > x_2 && y > y_2) printf("%.3f", getdis(li, f2));
    if(x > x_2 && y < y_1) printf("%.3f", getdis(li, f3));
    if(x < x_1 && y > y_2) printf("%.3f", getdis(li, f1));
    if(x < x_1 && y < y_1) printf("%.3f", getdis(li, f4));
    return 0;
}
