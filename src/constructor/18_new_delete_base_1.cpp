#include <iostream>
using namespace std;
class A {
public:
    A(): type("default"){
        cout << type << " constructor" <<  endl;
    };
    A(int): type("A(int)") {
        cout << type << " constructor" <<  endl;
    }
    A(int, int): type("A(int, int)") {
        cout << type << " constructor" <<  endl;
    }
    ~A() {
        cout << type << " destructor" << endl;
    }
private:
    string type;
};

int main() {
    int *p1 = new int;
    int *p2 = new int(10);
    int *p3 = new int[100];
    cout << "sizeof(p1):" << sizeof(*p1) << endl;
    cout << "p2:" << *p2 << endl;
    for(int i = 0; i < 100; i++) {
        p3[i] = i + 1;
    }
    for(int i = 0; i < 100; i++) {
        cout << p3[i] << ",";
        if(i == 99) {
            cout << endl;
        }
    }
    delete p1;
    delete p2;
    delete p3;

    A *a1 = new A;
    A *a2 = new A(1);
    A *a3 = new A(1, 1);
    delete a1;
    delete a2;
    delete a3;

    A *arrayA = new A[10];
    delete[] arrayA;
    return 0;
}