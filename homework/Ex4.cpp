#include <iostream>
using namespace std;
struct node {
  int data;
  node *lc;
  node *rc;
  node()
      : data(0), lc(nullptr), rc(nullptr) {
  }
};
class bstree {
 public:
  bstree()
      : root(nullptr), size(0) {
  }
  void insert_node(int data) {
    if (size == maxsize) {
      cout << "达到了最大容积" << endl;
      return;
    }
    root = insert(root, data);
  }
  void pre_order() {
    pre_order_traverse(root);
  }
  void in_order() {
    in_order_traverse(root);
  }
  void post_order() {
    post_order_traverse(root);
  }

 private:
  void pre_order_traverse(node *cur) {
    if (nullptr != cur) {
      cout << cur->data << ", ";
      pre_order_traverse(cur->lc);
      pre_order_traverse(cur->rc);
    }
  }
  void in_order_traverse(node *cur) {
    if (nullptr != cur) {
      in_order_traverse(cur->lc);
      cout << cur->data << ", ";
      in_order_traverse(cur->rc);
    }
  }
  void post_order_traverse(node *cur) {
    if (nullptr != cur) {
      post_order_traverse(cur->lc);
      post_order_traverse(cur->rc);
      cout << cur->data << ", ";
    }
  }
  node *insert(node *cur, int data) {
    if (nullptr == cur) {
      node *new_node = new node;
      if (nullptr != new_node) {
        new_node->data = data;
        cur = new_node;
        size++;
      }
      return cur;
    }
    if (cur->data > data)
      cur->lc = insert(cur->lc, data);
    else if (cur->data < data)
      cur->rc = insert(cur->rc, data);
    return cur;
  }

 private:
  node *root;
  int size;
  int maxsize = 10000;
};
int main() {
  bstree tree;
  int t;
  cin >> t;
  while (t--) {
    int i;
    cin >> i;
    tree.insert_node(i);
  }
  cout << "前序遍历" << endl;
  tree.pre_order();
  cout << endl;
  cout << "中序遍历" << endl;
  tree.in_order();
  cout << endl;
  cout << "后序遍历" << endl;
  tree.post_order();
  cout << endl;
  return 0;
}