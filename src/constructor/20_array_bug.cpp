#include <iostream>
using namespace std;
class INT {
public:
    INT(): p(new int(0)){
        cout << "INT () constructor" << endl;
    }
    INT(int i): p(new int(i)) {
        cout << "INT (int i) constructor" << endl;
    }

    INT(INT &&a ):p(a.p) {
        cout << "INT move constructor" << endl;
        a.p = nullptr;
    }

    INT(const INT &a): p(new int(0)) {
        cout << "INT copy constructor" << endl;   
        *p = *a.p;
    }
    
    void set(int num) {
        *p = num;
    }

    int val() {
        return *p;
    }

    int* getP() {
        return p;
    }

    ~INT() {
        cout << "INT destructor" << endl;
        delete p;
    }
private:
    int *p;
};

class Array {
public:

    Array():num(5),data((INT*) malloc(sizeof(INT) * 5)) {
        cout << "Array constructor" << endl;
        for(int i = 0; i < 5; i++) {
            new (data + i) INT(i);
        }
    }

    Array(int num):num(num),data((INT*) malloc(sizeof(INT) * num)) {
        cout << "Array constructor" << endl;
        for(int i = 0; i < num; i++) {
            new(data + i) INT();
        }
    }

    Array(const Array &array):num(array.num), data((INT*)malloc(sizeof(INT) * num)) {
        cout << "Array copy constructor" << endl;
        for(int i = 0;i < num; i++) {
            new(data + i) INT(array.data[i]);
        }
    }

    Array(Array &&array): num(array.num),data(array.data) {
        cout << "Array move constructor" << endl;
        array.num = 0;
        array.data = nullptr;
    }
    
    void output() {
        for(int i = 0; i < num; i++) {
            cout << data[i].val() << ",";
        }
        cout << endl;
    }

    ~Array() {
        cout << "Array destructor" << endl;
        for(int i = 0; i < num; i++) {
            data[i].~INT();
        }
        free(data);
    }
    void set(int index, int num) {
        data[index].set(num);
    }
private:
    int num;
    INT* data;
};

int main() {
    // cout << "hello world start" << endl;
    // Array a;
    // a.output();
    // Array b = a;
    // b.output();
    // Array c = std::move(a);
    // c.output();
    // cout << "hello world end" << endl;
    INT i1;
    cout << i1.val() << endl;
    INT i2 = i1;
    cout << i2.val() << endl;
    i1.set(10);
    cout << i1.val() << endl;
    cout << i2.val() << endl;
    return 0;
}