/*
【问题描述】
编写一个程序，定义一个时间类Time，包含三个属性：hour, minute 和 second

要求通过运算符重载实现如下功能：
- 时间输入输出(>>, <<);
- 时间增加/减少某个时间(+=, -=)，例：Time& operator+=(const Time&); Time& operator-=(const Time&);
- 时间前、后自增/减少1秒(++, --)，前自增例：Time& operator++(); 后自增例：Time operator++(int);

【输入形式】
- 输入应至为两个Time实例(time1, time2)每个实例占一行；
- Time实例输入格式为：hour minute second.

【输出形式】
- Time实例输出格式为：hour:minute:second;
- 每个输出实例占一行。
- 依次输出以下表达式的值
- time1 += (time2++)
- time1 -= time2
- ++time2
- time2 += (time1--)
- --time1
- time2 -= time1
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (second < 0) {
            int borrowMinutes = (-second + 59) / 60;
            minute -= borrowMinutes;
            second += borrowMinutes * 60;
        }

        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        if (minute < 0) {
            int borrowHours = (-minute + 59) / 60;
            hour -= borrowHours;
            minute += borrowHours * 60;
        }

        if (hour >= 24) {
            hour %= 24;
        }
        if (hour < 0) {
            hour = (hour % 24 + 24) % 24;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        normalize();
    }

    // 输入运算符
    friend istream& operator>>(istream& in, Time& t) {
        in >> t.hour >> t.minute >> t.second;
        t.normalize();
        return in;
    }

    //一定要加友元吗？作用是什么？
    // 答：需要加友元。因为运算符重载函数需要访问Time类的私有成员（hour, minute, second），
    // 而该函数不是Time类的成员函数（它的第一个参数是istream&，不是Time&）。
    // 友元声明允许这个函数访问Time类的私有成员。

    // 输出运算符
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << setfill('0') << setw(2) << t.hour << ":"
            << setw(2) << t.minute << ":"
            << setw(2) << t.second;
        return out;
    }

    // +=运算符
    Time& operator+=(const Time& t) {
        hour += t.hour;
        minute += t.minute;
        second += t.second;
        normalize();
        return *this;
    }

    // -=运算符
    Time& operator-=(const Time& t) {
        hour -= t.hour;
        minute -= t.minute;
        second -= t.second;
        normalize();
        return *this;
    }

    // 前置++
    Time& operator++() {
        second++;
        normalize();
        return *this;
    }

    // 后置++
    Time operator++(int) {
        Time temp = *this;  // 保存原来的值
        second++;           // 修改当前对象
        normalize();        // 标准化
        return temp;        // 返回原来的值
    }

    // 前置--
    Time& operator--() {
        second--;
        normalize();
        return *this;
    }

    //这里的后置是怎么实现的？
    // 答：后置--的实现原理：
    // 1. 通过int参数区分前置和后置（这个参数没有名称，只是用于区分）
    // 2. 先保存当前对象的副本（temp）
    // 3. 修改当前对象的值（second--）
    // 4. 对修改后的值进行标准化
    // 5. 返回之前保存的副本（即修改前的值）

    // 后置--
    Time operator--(int) {
        Time temp = *this;  // 1. 保存原来的值
        second--;           // 2. 修改当前对象
        normalize();        // 3. 标准化
        return temp;        // 4. 返回原来的值
    }
};

int main() {
    Time time1, time2;
    //这里的输入格式怎么确定？
    // 答：输入格式为两行，每行包含三个整数：hour minute second
    // 例如：12 30 45
    //       1 15 20
    // 输入运算符>>会按照"hour minute second"的顺序读取
    cin >> time1 >> time2;

    cout << (time1 += (time2++)) << endl;
    cout << (time1 -= time2) << endl;
    cout << (++time2) << endl;
    cout << (time2 += (time1--)) << endl;
    cout << (--time1) << endl;
    cout << (time2 -= time1) << endl;

    return 0;
}