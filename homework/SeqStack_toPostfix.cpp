#include <iostream>
#include<cctype>
#include<queue>

using namespace std;
template <typename T>
class SeqStack {
   public:
    SeqStack(int sz = 50);
    ~SeqStack() { delete[] element; }
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x) const;
    int getSize() const { return top + 1; }
    bool isEmpty() const { return top == -1;}
    bool isFull() const { return top == maxSize - 1;}
    void makeEmpty() {top = -1;}
   private:
    T *element;
    int top;
    int maxSize;
};

template <typename T>
SeqStack<T>::SeqStack(int sz) {
    top = -1;
    maxSize = sz;
    element = new T[maxSize];
}

template <typename T>
void SeqStack<T>::Push(const T &x) {
    element[++top] = x;
}

template <typename T>
bool SeqStack<T>::Pop(T &x) {
    if (isEmpty()) return false;
    x = element[top--];
    return true;
}

template <typename T>
bool SeqStack<T>::getTop(T &x) const {
    if (isFull()) return false;
    x = element[top];
    return true;
}
//in_stack_priority
int isp(char ch) {
    if (ch == '#') return 0;
    if (ch == '(') return 1;
    if (ch == '*' || ch == '/' || ch == '%') return 5;
    if (ch == '+' || ch == '-') return 3;
    if (ch == ')') return 6;
    return -1;
}

//in_coming_priority
int icp(char ch) {
    if (ch == '#') return 0;
    if (ch == '(') return 6;
    if (ch == '*' || ch == '/' || ch == '%') return 4;
    if (ch == '+' || ch == '-') return 2;
    if (ch == ')') return 1;
    return -1;
}
bool isNum(char ch) { 
    return isdigit(ch);
}
void toPostfix(string e) {
    SeqStack<char> s;
    char ch = '#', c, op;
    int i = 0;
    s.Push(ch);
    ch = e[i++];
    while (s.isEmpty() == false || ch != '#') {
        if (isNum(ch)) {
            cout << ch;
            ch = e[i++];
            if (!isNum(ch)) cout << " ";
            continue;
        }
        s.getTop(c);
        if (isp(c) < icp(ch)) {
            s.Push(ch);
            ch = e[i++];
            continue;
        }
        if (isp(c) > icp(ch)) {
            s.Pop(op);
            cout << op << " ";
            continue;
        }
        if (isp(c) == icp(ch)) {
            s.Pop(op);
            if (op == '(') {
                ch = e[i++];
            }
        }
    }
    cout << endl;
}
int main() {
    string e;
    cin >> e;
    toPostfix(e + "#");
    system("pause");
    return 0;
}