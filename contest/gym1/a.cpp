// Author : Wqr_
// Time : 2019/9/7 12:29:41

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 50;
int n;
int arr[nmax];
int dis[nmax];
stack<int> st;
int main(){
    iofuck;
    cin >> n;
    memset(dis, -1, sizeof(dis));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(!st.empty()){
            while(!st.empty() && arr[i] > arr[st.top()]){
                dis[st.top()] = i;
                st.pop();
            }
        }
        st.push(i);
    }

    /*
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;
    */

    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        if(dis[i] == -1){
            cout << min(arr[i], n - i - 1);
        }else{
            if(dis[i] > arr[i] + i) {
                //cout << arr[i] - i;
                cout << arr[i];
            }else{
                cout << dis[i] - i - 1;
            }
        }
    }
    return 0;
}
