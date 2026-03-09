/*4. 设计日期类Date，输出后一天前一天等
【问题描述】

设计符合下述要求的日期类Date，编写代码根据输入的日期输出期望的格式

拥有数据成员year、month、day，分别存储年月日

构造函数接收年月日参数并初始化全部数据成员

公有成员函数toText()返回一个string对象，其为该日期对象的文字表达式，比如“2024-11-14”

公有成员函数nextDay()返回一个Date对象，表示该日期的后一天

公有成员函数prevDay()返回一个Date对象，表示该日期的前一天

【输入形式】

年 月 日，中间均空一格

【输出形式】

Date: 输入的日期, Next Day: 后一天, Prev Day:前一天

【样例输入】

1979 1 16

【样例输出】

Date:1979-1-16,Next Day:1979-1-17,Prev Day:1979-1-15

【样例说明】

要求实现日期类Date


其他：

 闰年：四年一闰，百年不闰，四百年又闰

 闰年二月份为29天，非闰年二月份为28天



#include <iostream>

#include <string>



string toText(){

        char buffer[1024];

        sprintf(buffer,"%d-%d-%d",year,month,day);

        return buffer;

}*/
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    //构造函数
    Date(int y, int m, int d) :year(y), month(m), day(d) {}

    string toText() {
        char buffer[1024];
        sprintf_s(buffer, "%d-%d-%d", year, month, day);
        return buffer;
    }

    Date nextDay();

    Date prevDay();
};

Date Date::nextDay() {
    switch (month) {
    case 1:case 3: case 5: case 7:case 8: case 10:
        if (day == 31) {
            day = 1;
            month++;
        }
        else {
            day++;
        }
        break;
    case 12:
        if (day == 31) {
            year++;
            month = 1;
            day = 1;
        }
        else {
            day++;
        }
        break;
    case 4:case 6:case 9:case 11:
        if (day == 30) {
            day = 1;
            month++;
        }
        else {
            day++;
        }
        break;
    case 2:
        //闰年
        if (((year % 100 == 0) && (year % 400 == 0)) || ((year % 100 != 0) && (year % 4 == 0))) {
            if (day == 29) {
                month++;
                day = 1;
            }
            else {
                day++;
            }
        }
        else {
            if (day == 28) {
                month++;
                day = 1;
            }
            else {
                day++;
            }
        }
        break;
    default:
        break;
    }
    return Date(year, month, day);
}

Date Date::prevDay() {
    switch (month) {
    case 2:case 4:case 6: case 8: case 9:case 11:
        if (day == 1) {
            day = 31;
            month--;
        }
        else {
            day--;
        }
        break;
    case 1:
        if (day == 1) {
            year--;
            month = 12;
            day = 31;
        }
        else {
            day--;
        }
        break;
    case 5:case 7:case 10:case 12:
        if (day == 1) {
            day = 30;
            month--;
        }
        else {
            day--;
        }
        break;
    case 3:
        //闰年
        if (((year % 100 == 0) && (year % 400 == 0)) || ((year % 100 != 0) && (year % 4 == 0))) {
            if (day == 1) {
                month--;
                day = 29;
            }
            else {
                day--;
            }
        }
        else {
            if (day == 1) {
                month--;
                day = 28;
            }
            else {
                day--;
            }
        }
        break;
    default:
        break;
    }
    return Date(year, month, day);
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    Date d(year, month, day);
    cout << "Date:" << d.toText() << ",";
    Date d1 = d.nextDay();


    Date b(year, month, day);
    Date b2 = b.prevDay();


    cout << "Next Day:" << d1.toText() << ","
        << "Prev Day:" << b2.toText() << endl;

    return 0;
}