#include <iostream>
#include <memory>
using namespace std;

template <class T>
class MyList {
 public:
  MyList() {
    head = make_shared<node>();
    //head =  node;
    head->next = nullptr;
    back = make_shared<node>(head);
    //back = head;
    length = 0;
  }
  void push_back(T val) {
    auto cur = make_shared<node>(val);
    back->next = cur;
    back = cur;
    back->next = nullptr;
    length++;
  }
  void create_list(int n) {
    for (int i = 0; i < n; i++) {
      T cur;
      cin >> cur;
      push_back(cur);
      length++;
    }
  }
  void insert(int n, T val) {
    if (n > length) {
      cout << "输入错误" << endl;
      return;
    }
    if (n == length) {
      push_back(val);
      return;
    }
    shared_ptr<node> cur;
    shared_ptr<node> it;
    //node* cur =  node(val);
    //node* it = head;
    for (int i = 0; i < n; i++) it = it->next;
    cur->next = it->next;
    it->next = cur;
    //cur->next = it->next;
    //it->next = cur;
  }
  void del(int n) {
    if (n >= length) {
      cout << "输入错误" << endl;
      return;
    }
    auto it = make_shared<node>(head);
    //node* it = head;
    for (int i = 0; i < n; i++) it = it->next;
    it->next = it->next->next;
  }
  void show_list() {
    for (auto it = make_shared<node>(head->next); it != nullptr; it = it->next) {
      cout << it->val << " ";
    }
    cout << endl;
  }

 private:
  class node {
   public:
    T val;
    node() {}
    node(T in) { val = in; }
    shared_ptr<node> next;
    //node* next;
  };

  shared_ptr<node> head;
  shared_ptr<node> back;
  //node *head;
  //node *back;
  int length;
};

int main() {
  MyList<int> a;
  MyList<int> b;
  int num;
  cin >> num;
  a.create_list(num);
  a.insert(2, 100);
  a.insert(2, 100);
  a.del(2);
  a.show_list();
  return 0;
}