/*************************************************************************
    > File Name: c.carrarr
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 23时04分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int nmax = 3 * 100000;
typedef pair<int, int>  P;
vector<P> v;
int n;
int arr[nmax];
int ans = 0;
void ss(int a, int b){
    if(a == b) return;
    swap(arr[a], arr[b]);
    int n2 = n / 2;
    if(a < n2 && b < n2){
        //同左侧
        v.push_back(P(b, n - 1));
        v.push_back(P(a, n - 1));
        v.push_back(P(b, n - 1));
        ans += 3;
    }else if(a >= n2 && b >= n2){
        //同右侧
        v.push_back(P(0, a));
        v.push_back(P(0, b));
        v.push_back(P(0, a));
        ans += 3;
    }else{
        //差异侧
        if(b - a >= n2) {
            v.push_back(P(a, b));
            ans++;
        }else{
            v.push_back(P(a, n - 1));
            v.push_back(P(0, b));
            v.push_back(P(0, n - 1));
            v.push_back(P(a, n - 1));
            v.push_back(P(0, b));
            ans += 5;
        }
    }
}
int getPartion(int low, int high)
{
    int key = arr[low];
    while (low < high)
    {
        while (low < high && key <= arr[high]) //如果array[high]大于键值，那么本就应该在键值右边
            high--;  //因此将high下标向前移动，直至找到比键值小的值，此时交换这两个值
        ss(low, high);

        while (low < high && key >= arr[low])
            low++;
        ss(low, high);
    }
    return low;//返回key值的下标
}



void QuitSort(int low,int high)
{
    if (low < high)
    {
        int key = getPartion(low, high);

        QuitSort(low, key - 1);
        QuitSort(key + 1, high);
    }
}

int main(){
    iofuck;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    QuitSort(0, n - 1);
    cout << ans << endl;
    for(int i = 0; i < ans; i++){
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    }
    return 0;
}
