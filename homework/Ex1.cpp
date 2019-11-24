#include <iostream>
using namespace std;
const int maxsize = 1e5;

template<class T>
class SqList{
   public:
    SqList(){
        base = new T[maxsize];
        length = 0;
    }
    ~SqList(){
        delete[] base;
    }
    void create_SqList(int n){
        if(n < 0) cout << "输入个数有误" << endl;
        else{
            for(int i = 0; i < n; i++) cin >> base[i];
            length = n;
        }
    }
    void traverse_SqList(){
        for(int i = 0; i < length; i++) cout << base[i] << " ";
        cout << endl;
    }
    T get_elem_by_index(int i){
        return base[i];
    }
    void insert_SqList(int n, T in){
        if(n < 0 || n >= length) cout << "不合法" << endl;
        else if(length >= maxsize) cout << "已是最大长度" << endl;
        else{
            for(int i = length; i >= n; i--) base[i + 1] = base[i];
            base[n] = in;
            length++;
        }
    }
    void delete_elem(int n){
        if(n < 0 || n >= length) cout << "不合法" << endl;
        else{
            for (int i = n; i < length - 1; i++) base[i] = base[i + 1];
            length--;
        }
    }

   private:
    T* base;
    int length;
};
int main(){
    SqList<int> sq;
    int len;
    cin >> len;
    sq.create_SqList(len);
    sq.traverse_SqList();
    cout << sq.get_elem_by_index(1) << endl;
    sq.insert_SqList(2, 100);
    sq.traverse_SqList();
    sq.delete_elem(2);
    sq.traverse_SqList();
    return 0;
}