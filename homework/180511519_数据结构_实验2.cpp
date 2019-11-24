#include <cctype>
#include <iostream>
using namespace std;
template <class T>
class SeqStack {
   public:
    SeqStack(int size = 1e5) {
        topit = -1;
        maxSize = size;
        ele = new T[maxSize];
    }
    void push(const T& x) { ele[++topit] = x; }
    bool pop() {
        if (empty()) return false;
        topit--;
        return true;
    }
    T top() {
        if (empty()) return -1e9 + 7;
        return ele[topit];
    }
    int size() { return topit + 1; }
    bool empty() { return topit == -1; }
    bool full() { return topit == maxSize - 1; }
    void clear() { top = -1; }
   private:
    T* ele;
    int topit;
    int maxSize;
};
int isp(char ch) {
    if (ch == '#') return 0;
    if (ch == '(') return 1;
    if (ch == '*' || ch == '/' || ch == '%') return 5;
    if (ch == '+' || ch == '-') return 3;
    if (ch == ')') return 6;
    return -1;
}
int icp(char ch) {
    if (ch == '#') return 0;
    if (ch == ')') return 1;
    if (ch == '+' || ch == '-') return 2;
    if (ch == '*' || ch == '/' || ch == '%') return 4;
    if (ch == '(') return 6;
    return -1;
}
void doit(string e) {
    SeqStack<char> s;
    char ch = '#', c, op;
    int i = 0;
    s.push(ch);
    ch = e[i++];
    while (!s.empty() || ch != '#') {
        if (isdigit(ch)) {
            cout << ch;
            ch = e[i++];
            if (!isdigit(ch)) cout << " ";
            continue;
        }
        c = s.top();
        if (isp(c) < icp(ch)) {
            s.push(ch);
            ch = e[i++];
            continue;
        }
        if (isp(c) > icp(ch)) {
            op = s.top();
            s.pop();
            cout << op << " ";
            continue;
        }
        if (isp(c) == icp(ch)) {
            op = s.top();
            s.pop();
            if (op == '(') {
                ch = e[i++];
            }
        }
    }
    cout << endl;
}

int main() {
    string str;
    cin >> str;
    doit(str + "#");
    return 0;
}