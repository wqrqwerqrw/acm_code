#include <iostream>
#include <memory>
using namespace std;

template <class T>
class MyList {
 public:
  MyList() {
    head = new node();
    head->next = nullptr;
    back = head;
    length = 0;
  }
  void push_back(T val) {
    node* cur = new node(val);
    back->next = cur;
    back = cur;
    back->next = nullptr;
    length++;
  }
  void pop_back() {
    if (length == 0) return;
    node* it;
    node* tmp = back;
    for (it = head->next; it->next != back; it = it->next) {
    }
    it->next = nullptr;
    back = it;
    length--;
    delete tmp;
  }
  void create_list(int n) {
    for (int i = 0; i < n; i++) {
      T val;
      cin >> val;
      push_back(val);
    }
  }
  void insert(int n, T val) {
    if (n > length) {
      cout << "错误" << endl;
      return;
    }
    if (n == length) {
      push_back(val);
      return;
    }
    node* cur = new node(val);
    node* it = head;
    for (int i = 0; i < n; i++) it = it->next;
    cur->next = it->next;
    it->next = cur;
    length++;
  }
  void del(int n) {
    if (n >= length) {
      cout << "输入错误" << endl;
      return;
    }
    if (n == length - 1) {
      pop_back();
      return;
    }
    node* it = head;
    for (int i = 0; i < n; i++) it = it->next;
    node* todel = it->next;
    it->next = it->next->next;
    length--;
    delete todel;
  }
  void show_list() {
    for (auto it = head->next; it != nullptr; it = it->next)
      cout << it->val << " ";
    cout << endl;
  }
  void add(MyList<T> b) {
    back->next = b.rbegin()->next;
    length += b.length;
    back = b.rend();
  }
  void pop_sort() {
    for (int i = 0; i < length; i++) {
      for (auto it = ittmp; it->next != nullptr; it = it->next) {
        if (it->val < it->next->val) swap(it->val, it->next->val);
      }
    }
  }
  int size() { return length; }
  auto rbegin() { return head; }
  auto rend() { return back; }

 private:
  class node {
   public:
    T val;
    node() {}
    node(T in) { val = in; }
    node* next;
  };
  node* head;
  node* back;
  int length;
};

int main() {
  MyList<int> a;
  MyList<int> b;
  int num;
  cout << "输入第一个链表的元素个数和元素" << endl;
  cin >> num;
  a.create_list(num);
  cout << "输入第二个链表的元素个数和元素" << endl;
  cin >> num;
  b.create_list(num);
  cout << "合并到a" << endl;
  a.add(b);
  a.show_list();
  cout << "排序" << endl;
  a.pop_sort();
  a.show_list();
  cout << a.size() << endl;
  a.del(0);
  a.show_list();
  cout << a.size() << endl;
  return 0;
}