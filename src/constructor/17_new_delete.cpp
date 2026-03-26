#include <iostream>
using namespace std;
/**
 * 为什么一定要用new和delete
 * malloc和new的根本区别是malloc只开辟了空间，没有调用构造和析构函数。
 */
class A {
public:
    A(string msg) {
        cout << msg << " A constructor" << endl;
    }
    ~A() {
        cout << "A destructor" << endl;
    }
};

int main() {
    A *malloc_a = (A*)malloc(sizeof(A));
    free(malloc_a);

    A *a = new A("a");
    delete a;

    return 0;
}