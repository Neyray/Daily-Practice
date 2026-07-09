#include <iostream>
using namespace std;

// 1. 声明异常类 Cexception，包含成员函数 Reason()
class Cexception {
public:
    // 成员函数 Reason()，显示异常的类型
    void Reason() {
        cout << "Cexception 类型异常被触发！" << endl;
    }
};

// 2. 子函数 fn1()，用于触发异常
void fn1() {
    cout << "在 fn1() 函数中，即将触发异常..." << endl;
    throw Cexception();  // 触发异常，抛出一个 Cexception 对象
}

int main() {
    cout << "程序开始执行..." << endl;

    // 3. 在主函数的 try 模块中调用 fn1()
    try {
        cout << "进入 try 块..." << endl;
        fn1();
        cout << "这一行不会被执行，因为 fn1() 抛出了异常" << endl;
    }
    // 4. 在 catch 模块中捕获异常
    catch (Cexception e) {
        cout << "捕获到 Cexception 异常！" << endl;
        e.Reason();  // 调用异常对象的 Reason 方法显示异常类型
    }

    cout << "程序执行结束。" << endl;
    return 0;
}