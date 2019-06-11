/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月10日 星期一 19时06分26秒
 ************************************************************************/

#include<iostream>
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int nmax = 5e5 + 5;
int n;
int a, b, c, d, e, f;
int main(){
    iofuck;
    cin >> n;
    int num;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == 4){
            a++;
        }else if(num == 8){
            if(a > 0){
                b++;
                a--;
            }
        }else if(num == 15){
            if(b > 0){
                c++;
                b--;
            }
        }else if(num == 16){
            if(c > 0){
                d++;
                c--;
            }
        }else if(num == 23){
            if(d > 0){
                e++;
                d--;
            }
        }else if(num == 42){
            if(e > 0){
                f++;
                e--;
            }
        }
    }
    cout << n - f * 6 << endl;;
    return 0;
}
