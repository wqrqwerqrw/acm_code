#include <cctype>
#include <iostream>
#include <memory>
#include <sstream>
using namespace std;
template <class T>
class MyStack {
 public:
  MyStack() {
    data = new T[maxsize];
    topit = -1;
  }
  ~MyStack() { delete[] data; }
  void push(T val) {
    if (topit >= maxsize - 1) {
      cerr << "full" << endl;
      return;
    }
    data[++topit] = val;
  }
  void pop() {
    if (topit <= -1) {
      cerr << "empty" << endl;
      return;
    }
    topit--;
  }
  T top() { return data[topit]; }
  bool empty() { return topit <= -1; }

 private:
  T* data;
  int topit;
  const int maxsize = 1e5;
};

int main() {
  MyStack<char> charst;
  string tmp, in = "(";
  getline(cin, tmp);
  for (auto i: tmp)
    if (i != ' ') in.push_back(i);
  in.push_back(')');
  cout << in << endl;
  stringstream ss(in);
  while (ss.str().size()) {
    char chk = ss.peek();
    if (isdigit(chk)) {
      int num;
      ss >> num;
      cout << num << " ";
    } else {
      char in;
      ss >> in;
      if (in == ')') {
        char ch = charst.top();
        while (ch != '(') {
          cout << ch << " ";
          charst.pop();
          ch = charst.top();
        }
      } else {
        charst.push(in);
      }
    }
  }
  return 0;
}