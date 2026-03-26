#include <iostream>
#include <crtdbg.h>
using namespace std;
class A {
public:
    A(string msg) {
        cout << msg << " constructor" << endl;
    }
    ~A() {
        cout << " destructor " << endl;
    }
};
int main() {
    // 1. 设置调试标志
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // 2. 将泄漏报告重定向到标准错误输出（控制台可见）
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);

    A *a = new A("11");
    delete a; // 故意注释掉以测试泄漏

    // 3. 手动触发检查
    _CrtDumpMemoryLeaks();
    
    return 0;
}