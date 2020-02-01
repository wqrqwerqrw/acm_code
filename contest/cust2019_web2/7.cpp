/*************************************************************************
    > File Name: 7.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 15时39分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int d, n, m, h;
char mapp[101][101][101];
char opes[3][300];
void c1(int num, char tu) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      mapp[i][num][j] = tu;
    }
  }
}
void c2(int num, char tu) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      mapp[i][j][num] = tu;
    }
  }
}
void c3(int num, char tu) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mapp[num][i][j] = tu;
    }
  }
}
void pr() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (mapp[i][j][k] != '*')
          printf("%c", mapp[i][j][k]);
        else
          printf(" ");
        printf(" ");
      }
      printf("\n");
    }
    printf("\n");
  }
}
int main() {
  cin >> d >> n >> m >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        mapp[i][j][k] = '*';
      }
    }
  }
  char tu;
  int num, ope;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 100; j++) {
      opes[i][j] = '*';
    }
  }
  for (int i = 0; i < d; i++) {
    cin >> tu >> ope >> num;
    ope--;
    num--;
    opes[ope][num] = tu;
  }
  /*
    for(int i = 0; i < d; i++){
        getchar();
        scanf("%c", &tu);
        scanf("%d %d", &ope, &num);
        //cin >> tu >> ope >> num;
        num--;
        switch(ope){
            case 1:
                c1(num, tu);
                break;
            case 2:
                c2(num, tu);
                break;
            case 3:
                c3(num, tu);
        }
    }
    */
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 100; j++) {
      if (opes[i][j] == '*') continue;
      switch (i) {
        case 0:
          c1(j, opes[i][j]);
          break;
        case 1:
          c2(j, opes[i][j]);
          break;
        case 3:
          c3(j, opes[i][j]);
          break;
      }
    }
  }
  pr();
  return 0;
}
