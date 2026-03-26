#include <iostream>
using namespace std;
class A {
public:
    A(string name):name(name) { 
        cout << name << " constructor" << endl;
    }
    ~A() { 
        cout << name << " destructor" << endl;
     }
private:
    string name;
};

int main() {
    A a{"a"}, b{"b"};
    return 0;
}