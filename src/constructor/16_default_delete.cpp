#include <iostream>
using namespace std;
/**
 * 在构造函数中,defalut和delete起到提醒的作用
 */
class A {
public:
    // A() {

    // }
    /**
     * 等于 A(){}，保留默认构造。
     */
    A() = default;
    ~A() = default;
    // 删除A类的拷贝构造，如果此时调用A b{a}就会报错
    A(const A &) = delete;
    A(int a) {

    }
private:

};

int main() {
    A a;
    // 拷贝构造 
    // A b{a};    
    return 0;
}