//设计日期类Date
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

//重点是：1.进行功能的分块，避免放一起而导致的无法处理；2.多种情况时用case简化
class Date {
private:
    int year, month, day;

    // 判断是否为闰年
    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 获取某个月的天数
    int getDaysInMonth() const {
        switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear() ? 29 : 28;
        default:
            return 0;
        }
    }

public:
    // 构造函数
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // 返回日期文字表达式
    string toText() {
        char buffer[1024];
        sprintf_s(buffer, "%d-%d-%d", year, month, day);
        return buffer;
    }

    // 返回后一天的日期
    Date nextDay() {
        int y = year, m = month, d = day + 1;

        if (d > getDaysInMonth()) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }

        return Date(y, m, d);
    }

    // 返回前一天的日期
    Date prevDay() {
        int y = year, m = month, d = day - 1;

        if (d < 1) {
            m--;
            if (m < 1) {
                m = 12;
                y--;
            }
            d = Date(y, m, 1).getDaysInMonth(); // 获取上个月的天数
        }

        return Date(y, m, d);
    }
};

int main() {
    int y, m, d;
    cin >> y >> m >> d;

    //注意类的使用方法
    Date date(y, m, d);
    Date next = date.nextDay();
    Date prev = date.prevDay();

    cout << "Date:" << date.toText()
        << ",Next Day:" << next.toText()
        << ",Prev Day:" << prev.toText() << endl;

    return 0;
}