#include <stdio.h>
#include <stdlib.h>
#define MAXN 20004
typedef struct node {
    int date[MAXN];
    int last;
} st;
st *l;
st *makeempty()  //顺序表的初始化
{
    l = (st *)malloc(sizeof(st));
    l->last = -1;
    return l;
}
st *build(st *l)  //顺序表内元素的建立
{
    int i;
    for (i = 0; i <= l->last; i++) {
        scanf("%d", &l->date[i]);
    }
    return l;
}
int search(st *l, int left, int right, int ans)  //通过二分法在有序顺序表中查询
{
    int mid = (left + right) / 2;
    if (ans < l->date[left] || ans > l->date[right]) {
        return -1;
    }
    if (ans == l->date[mid]) {
        return (mid + 1);
    }
    if (ans > l->date[mid]) {
        left = mid + 1;
    }
    if (ans < l->date[mid]) {
        right = mid - 1;
    }
    return search(l, left, right, ans);
}
int main() {
    int n, T, x, y;
    l = makeempty();  //调用顺序表初始化函数
    scanf("%d", &n);
    l->last = n - 1;
    l = build(l);  //调用顺序表元素建立函数
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        y = search(l, 0, n - 1, x);  //调用有序顺序表二分法查找函数
        if (y != -1) {
            printf("%d\n", y);
        } else if (y == -1) {
            printf("No Found!\n");
        }
    }
    return 0;
}