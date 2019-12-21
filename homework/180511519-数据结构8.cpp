#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int help[100];
    int i = 0;
    int lIndex = l;
    int rIndex = mid + 1;
    while (lIndex <= mid && rIndex <= r) {
        help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++] : arr[rIndex++];
    }
    while (lIndex <= mid) {
        help[i++] = arr[lIndex++];
    }
    while (rIndex <= r) {
        help[i++] = arr[rIndex++];
    }
    for (i = 0; i < r - l + 1; i++) {
        arr[l + i] = help[i];
    }
}

static void mergeSort(int arr[], int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void mergeSort(int arr[], int n) {
    if (arr == NULL || n < 2) {
        return;
    }
    mergeSort(arr, 0, n - 1);
}

void adjust_heap(int* a, int node, int size) {
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int max = node;
    if (left < size && a[left] > a[max])
        max = left;
    if (right < size && a[right] > a[max])
        max = right;
    if (max != node) {
        swap(a[max], a[node]);
        adjust_heap(a, max, size);
    }
}

void heap_sort(int* a, int len) {
    for (int i = len / 2 - 1; i >= 0; --i)
        adjust_heap(a, i, len);

    for (int i = len - 1; i >= 0; i--) {
        swap(a[0], a[i]);      // 将当前最大的放置到数组末尾
        adjust_heap(a, 0, i);  // 将未完成排序的部分继续进行堆排序
    }
}

int main() {
    int arr[] = {5, 5, 3, 1, 2};
    mergeSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int arrb[] = {5, 5, 3, 1, 2};
    heap_sort(arrb, 5);
    for (int i = 0; i < 5; i++) {
        cout << arrb[i] << " ";
    }
    cout << endl;
    return 0;
}