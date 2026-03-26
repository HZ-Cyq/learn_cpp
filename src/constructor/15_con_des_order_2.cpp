#include <iostream>
using namespace std;

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
    B(A &a, string name): a(a),name(name) {
        cout << name << " B constructor" << endl;
        if(a.name == "c") {
            data = new int[10];
        } else {
            data = new int();
        }
    }
    ~B() {
        if(a.name == "c") {
            cout << name << " B destructor []" << endl;
            delete[] data;
        } else {
            cout << name << " B destructor" << endl;
            delete data;
        }
    }
private:
    A &a;
    int *data;
    string name;
};

A c{"c"}, d{"d"};
int main() {

    B a{c, "a"};
    B b{d, "b"};
    return 0;
}