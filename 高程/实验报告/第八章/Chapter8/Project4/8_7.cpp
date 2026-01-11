#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    // 构造函数
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 获取坐标
    int getX() const { return x; }
    int getY() const { return y; }

    // 前缀 ++（先自增再使用）
    Point& operator++() {
        ++x;
        ++y;
        return *this;  // 返回自增后的对象引用
    }

    // 后缀 ++（先使用再自增）
    Point operator++(int) {
        Point temp = *this;  // 保存原始值
        ++(*this);          // 调用前缀++进行自增
        return temp;        // 返回原始值
    }

    // 前缀 --（先自减再使用）
    Point& operator--() {
        --x;
        --y;
        return *this;  // 返回自减后的对象引用
    }

    // 后缀 --（先使用再自减）
    Point operator--(int) {
        Point temp = *this;  // 保存原始值
        --(*this);          // 调用前缀--进行自减
        return temp;        // 返回原始值
    }

    // 显示坐标
    void show() const {
        cout << "(" << x << ", " << y << ")";
    }

    // 输出运算符重载（便于直接输出Point对象）
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// 测试主函数
int main() {
    cout << "========== Point类运算符重载测试程序 ==========" << endl;

    // 测试1：前缀++和后缀++的区别
    cout << "\n1. 测试前缀++和后缀++的区别：" << endl;

    Point p1(3, 4);
    cout << "初始点 p1: " << p1 << endl;

    // 前缀++
    cout << "前缀++p1: " << ++p1 << endl;
    cout << "执行后 p1: " << p1 << endl;

    // 后缀++
    Point p2(10, 20);
    cout << "\n初始点 p2: " << p2 << endl;
    cout << "后缀p2++: " << p2++ << endl;  // 返回原值
    cout << "执行后 p2: " << p2 << endl;   // 实际已自增




    // 测试2：前缀--和后缀--的区别
    cout << "\n\n2. 测试前缀--和后缀--的区别：" << endl;

    Point p3(15, 25);
    cout << "初始点 p3: " << p3 << endl;

    // 前缀--
    cout << "前缀--p3: " << --p3 << endl;
    cout << "执行后 p3: " << p3 << endl;

    // 后缀--
    Point p4(30, 40);
    cout << "\n初始点 p4: " << p4 << endl;
    cout << "后缀p4--: " << p4-- << endl;  // 返回原值
    cout << "执行后 p4: " << p4 << endl;   // 实际已自减




    // 测试3：连续操作
    cout << "\n\n3. 测试连续操作：" << endl;

    Point p5(1, 1);
    cout << "初始点 p5: " << p5 << endl;

    // 混合操作
    cout << "++p5: " << ++p5 << endl;      // (2, 2)
    cout << "p5++: " << p5++ << endl;      // 显示(2, 2)，实际变为(3, 3)
    cout << "现在 p5: " << p5 << endl;     // (3, 3)

    cout << "--p5: " << --p5 << endl;      // (2, 2)
    cout << "p5--: " << p5-- << endl;      // 显示(2, 2)，实际变为(1, 1)
    cout << "最终 p5: " << p5 << endl;     // (1, 1)





    // 测试4：在表达式中使用
    cout << "\n\n4. 测试在表达式中的使用：" << endl;

    Point p6(5, 5);
    Point p7(8, 8);

    cout << "p6: " << p6 << ", p7: " << p7 << endl;

    // 前缀++在赋值中
    Point p8 = ++p6;
    cout << "执行 Point p8 = ++p6 后：" << endl;
    cout << "p6: " << p6 << ", p8: " << p8 << endl;

    // 后缀++在赋值中
    Point p9 = p7++;
    cout << "执行 Point p9 = p7++ 后：" << endl;
    cout << "p7: " << p7 << ", p9: " << p9 << endl;





    // 测试5：链式操作
    cout << "\n\n5. 测试链式操作（仅前缀运算符支持）：" << endl;

    Point p10(0, 0);
    cout << "初始 p10: " << p10 << endl;

    // 前缀运算符可以链式调用，因为返回引用
    ++++p10;  // 连续两次前缀++
    cout << "执行 ++++p10 后: " << p10 << endl;

    // 后缀运算符不支持链式调用，因为返回临时对象
    // p10++++;  // 错误：表达式必须是可修改的左值

    cout << "\n========== 测试结束 ==========" << endl;

    return 0;
}