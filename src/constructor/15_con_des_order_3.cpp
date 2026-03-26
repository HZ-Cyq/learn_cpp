#include <iostream>
using namespace std;
/**
 * 对象与属性的构造和析构顺序
 * 先构造属性，再构造对象，先析构对象，再析构属性
 */
class A {
public:
    A(string name):name(name) { 
        cout << name << " A constructor" << endl;
    }
    ~A() { 
        cout << name << " A destructor" << endl;
     }
    string name;
};

class B {
public:
    B(string name): name(name), c(name + ".c"), d(name + ".d") {
        cout << name << " B constructor" << endl;
    }
    ~B() {
        cout << name << " B destructor" << endl;
    }
private:
    A c,d;
    string name;
};

int main() {
    B b("b");
    return 0;
}