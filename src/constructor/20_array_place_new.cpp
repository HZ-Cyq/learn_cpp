#include <iostream>
using namespace std;

class A {
public:
    A(int x) {
        cout << "constructor: " << x << endl;
    }
    void output() {
        cout << "output" << endl;   
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

void test() { 
    // 1️⃣ 准备一块“原始内存”（还不是对象）
    void* buffer = malloc(sizeof(A));

    // 2️⃣ 在这块内存上构造对象（⭐核心）
    A* p = new (buffer) A(10);

    // 3️⃣ 正常使用
    // ...

    // 4️⃣ 手动调用析构函数（⭐必须）
    p->~A();

    // 5️⃣ 释放内存
    free(buffer);
}

void test2() {
    // 通过malloc申请一块内存
    A* p = (A*)malloc(sizeof(A));
    // 在该内存上构造A
    new (p) A(10);
    p->output();    
    p->~A();
    free(p);
}

int main() {
    cout << "start" << endl;
    // 1. 设置调试标志
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // 2. 将泄漏报告重定向到标准错误输出（控制台可见）
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    
    test2();
    
    _CrtDumpMemoryLeaks();
    cout << "end" << endl;
    return 0;
}