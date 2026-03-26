#include <iostream>
using namespace std;
class A {
public:
    A():p(new int()) {
        cout << "default constructor" << endl;        
    }
    A(int a): p(new int(a)) {
        cout << "A(int) constructor" << endl;
    }
    // 拷贝构造
    A(const A& a):p(new int(*a.p)) {
        cout << "copy constructor" << endl;
    }
    // 移动构造    
    A(A&& a):p(a.p) {
        cout << "move constructor" << endl;
        a.p = nullptr;
    }
    // 拷贝赋值
    A& operator=(const A& a) {
        cout << "copy assign" << endl;
        delete p;
        p = new int(*a.p);
        return *this;
    }
    // // 移动赋值
    A& operator=(A&& a) {
        cout << "move assign" << endl;
        delete p;
        p = a.p;
        a.p = nullptr;
        return *this;
    }
    
    // 统一赋值（copy + move 都走这里）👉 最核心技巧 
    // 这样写的好处是比较简单，坏处是拷贝赋值的时候会多一次构造
    // 如果是右值，会多一次移动构造，如果是左值，会多一次拷贝构造
    // A& operator=(A other) {  // 注意：传值！
    //     cout << "copy/move assign (copy-swap)" << endl;
    //     swap(p, other.p);    // 交换资源
    //     return *this;
    // }

    ~A() {
        cout << "destructor" << endl;
        delete p;
    }
private:
    int *p;
};

void testIntClass() {
    // 默认构造
    A a;
    // 拷贝构造
    A b = a;
    // 移动构造
    A c = std::move(a);
    A d;
    A e,f;
    cout << "l value" << endl;
    // 拷贝赋值
    e = d;
    cout << "r value" << endl;
    // 移动赋值
    f = std::move(d);    
}

int main() {
    cout << "start-----------------------------------------------------" << endl;
    // 1. 设置调试标志
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // 2. 将泄漏报告重定向到标准错误输出（控制台可见）
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    
    testIntClass();
    
    _CrtDumpMemoryLeaks();
    cout << "end-------------------------------------------------------" << endl;
    return 0;
}