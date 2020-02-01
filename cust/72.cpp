/*************************************************************************
  > File Name: 72.cpp
  > Author: Wqr_
  > Mail: xueduanwei@126.com 
  > Created Time: Sun Sep 23 10:28:17 2018
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
  int c;
  bool q = true;
  int num = 0;
  while ((c = getchar()) != EOF) {
    bool ifis = true;
    if (c == '(') {
      q = !q;
    }
    if (c == '!') {
      q = !q;
    }
    if (c == '?') {
      q = !q;
    }
    if (c == '.') {
      q = !q;
    }
    if (c == ',') {
      q = !q;
    }
    if (c == '"') {
      q = !q;
    }
    if (c == ':') {
      q = !q;
    }
    if (c == ';') {
      q = !q;
    }
    if (c == ' ') {
      q = !q;
    }
    if (c == '\n') {
      q = !q;
    }
    if (c == ')' && q == false) {
      num++;
      q = !q;
    }
    if (c == ')' && q == true) {
      q = !q;
    }
  }
  cout << num;
  return 0;
}
