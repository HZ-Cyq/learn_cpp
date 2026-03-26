#include <iostream>
using namespace std;
class A {
public:
    A(): data(new int[10]) {
        cout << this << " default constructor 222" << endl;
    }
    ~A() {
        cout << this << " destructor" << endl;
        delete[] data;
    }
private:
    int *data;    
};

int main() {
    cout << "hello world2" << endl;
    A a, *pa = new A();
    cout << "a: " << &a << endl;
    cout << "pa: " << pa << endl;
    delete pa;
    return 0;
}