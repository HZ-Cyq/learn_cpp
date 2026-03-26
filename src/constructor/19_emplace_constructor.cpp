/**
 * 原地构造：如果一个类没有默认构造，如何申请该类的数组？
 */
#include <iostream>
using namespace std;
class A {
public:
    A() = delete;
    A(int data): data(data) {
        cout << "A constructor" << endl;
    }
    void output() {
        cout << data << ",";
    }
    ~A() {
        cout << "A destructor" << endl;
    }
private:
    int data;
};

int main() {
    A *p = (A*) malloc(sizeof(A) * 10);
    for(int i = 0; i < 10; i ++) {
        new(p + i) A(i);;
    }
    for(int i = 0; i < 10; i ++) {
        p[i].output();
    }
    for(int i = 0; i < 10; i++) {
        p[i].~A();
    }
    free(p);
    return 0;
}