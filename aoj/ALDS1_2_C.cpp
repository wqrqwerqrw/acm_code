/*************************************************************************
    > File Name: ALDS1_2_C.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov 12 15:42:36 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct card{
    char suit, value;
};
void bubble(struct card C1[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            if(C1[j].value < C1[j-1].value){
                card s = C1[j];
                C1[j] = C1[j-1];
                C1[j-1] = s;
            }
        }
    }
}
void select(struct card C2[], int n){
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(C2[j].value < C2[minj].value)
                minj = j;
        }
        card s = C2[i];
        C2[i] = C2[minj];
        C2[minj] = s;
    }
}
void print(struct card A[], int n){
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}
bool ifStable(struct card C1[], struct card C2[], int n){
    for(int i = 0 ; i < n; i++){
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    card C1[100], C2[100];
    for(int i = 0; i < n; i++){
        cin >> C1[i].suit >> C1[i].value;
        C2[i].suit = C1[i].suit;
        C2[i].value = C1[i].value;
    }
    bubble(C1, n);
    select(C2, n);
    print(C1, n);
    cout << "Stable" << endl;
    print(C2, n);
    if(ifStable(C1, C2, n)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    return 0;
}
