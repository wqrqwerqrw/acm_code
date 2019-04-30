/*************************************************************************
    > File Name: 二进制集合.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月29日 星期一 19时10分44秒
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
using namespace std;
// 空集 0
// 只有第i个元素的集合{i}...................1<<i
// 含有所有n个元素的集合....................(n<<i) - 1;
// 判断第i个元素是否属于集合S...............if (S>>i&i)
// 向集合中加入第i个元素....................S|1<<i
// 从集合中去除第i个元素....................S&~(1<<i)
// 集合S和T的并集...........................S|T
// 集合S和T的交集...........................S&T


