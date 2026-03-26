/**
 * 正确的书写一个类，正确的实现拷贝构造、移动构造、拷贝赋值、移动赋值和析构。
 * rule of 5:如果自定义了拷贝构造、移动构造、拷贝赋值、移动赋值、析构中的任意一个函数，
 * 其他的四个函数也要有相对应的实现
 */
#include <iostream>
using namespace std;
class INT {
public:
    // 默认构造
    INT(): p(new int(0)) {
        cout << "INT default constructor" << endl;
    }
    INT(int n): p(new int(n)) {
        cout << "INT(int) constructor" << endl;
    }
    // 拷贝构造
    INT(const INT &a): p(new int(a.val())) {
        cout << "INT copy constructor" << endl;
    }
    // 移动构造
    INT(INT &&a): p(a.p) {
        cout << "INT move constructor" << endl;
        a.p = nullptr;
    }
    // 拷贝赋值
    INT& operator= (const INT & n) {
        if(this == &n) {
            return *this;
        }
        cout << "copy assign" << endl;
        delete p;
        p = new int(n.val());
        return *this;
    }   
    // 移动赋值
    INT& operator= (INT && n) {
        cout << "move assign" << endl;
        if(this == &n) {
            return *this;
        }
        delete p;
        p = n.p;
        n.p = nullptr;
        return *this;
    }
    // 析构
    ~INT() {
        if(p == nullptr) {
            cout << "INT destructor p is nullptr" << endl;
        } else {
            cout << "INT destructor " << *p << endl;
        }
        delete p;
    }
    void set(int val) {
        *p = val;
    }

    int val() const {
        return *p;
    }

private:
    int *p;
};

/**
 * 测试INT类
 */
void testIntClass() {
    INT a(10);
    // // 拷贝构造
    INT b = a;
    b.set(11);
    // 移动构造
    INT c = std::move(a); 
    INT d(12);
    INT e,f;
    // 拷贝赋值
    e = d;
    // 移动赋值
    f = std::move(d);
}


int main() {
    cout << "start" << endl;
    // 1. 设置调试标志
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // 2. 将泄漏报告重定向到标准错误输出（控制台可见）
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    
    testIntClass();
    
    _CrtDumpMemoryLeaks();
    cout << "end" << endl;
    return 0;
}