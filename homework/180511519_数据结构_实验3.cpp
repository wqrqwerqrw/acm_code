#include <iostream>
using namespace std;
template <class T>
class Squeue {
   public:
    Squeue(int len_ = 10) {
        if (len_ < 10) {
            len_ = 10;
        }
        arr = new T[len];
        head = 0;
        tail = 0;
        len = len_;
    }
    ~Squeue(){
        if(arr != nullptr) delete[] arr;
    }
    void push(T val) {
        if (full()) resize();
        arr[tail] = val;
        tail = (tail + 1) % len;
    }
    void pop() {
        if (empty()) return;
        head = (head + 1) % len;
    }
    T front(){
        return arr[head];
    }
    bool empty() { return head == tail; }
    bool full() { return (tail + 1) % len == head; }
    void resize() {
        int lentmp = len + len * 2;
        T* tmparr = new T[lentmp];
        for (int i = head, j = 0; i != tail; i = (i + 1) % len, j++) {
            tmparr[j] = arr[i];
        }
        if (arr != nullptr) delete[] arr;
        arr = tmparr;
        head = 0, tail = (len - 1), len = lentmp;
    }

   private:
    T* arr;
    int head;
    int tail;
    int len;
};
int main() {
    Squeue<int> manQ, womanQ, tmpManQ, tmpWomanQ;
    for(int i = 0; i < 4; i++) manQ.push(10000 + i + 1);
    for(int i = 0; i < 5; i++) womanQ.push(20000 + i + 1);
    int times;
    cin >> times;
    while(times--){
        while(!manQ.empty() && !womanQ.empty()){
            cout << manQ.front() << "-" << womanQ.front() << endl;
            tmpManQ.push(manQ.front());
            manQ.pop();
            tmpWomanQ.push(womanQ.front());
            womanQ.pop();
        }
        if(manQ.empty() && !womanQ.empty()){
            cout << "the first of next round is " << womanQ.front() << endl;
        }
        if(!manQ.empty() && womanQ.empty()){
            cout << "the first of next round is " << manQ.front() << endl;
        }
        cout << "------------------------" << endl;
        while(!tmpManQ.empty()){
            manQ.push(tmpManQ.front());
            tmpManQ.pop();
        }
        while(!tmpWomanQ.empty()){
            womanQ.push(tmpWomanQ.front());
            tmpWomanQ.pop();
        }
    }
    return 0;
}