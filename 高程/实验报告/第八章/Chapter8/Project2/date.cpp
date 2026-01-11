// date.cpp
#include "date.h"
#include <iostream>
using namespace std;

// 辅助函数：计算某年某月的天数
int getDaysInMonth(int year, int month) {
    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2) {
        // 闰年2月29天
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
    }
    return days[month];
}

// 计算从公元元年1月1日到指定日期的总天数
int calculateTotalDays(int year, int month, int day) {
    int total = 0;
    // 加之前年份的天数
    for (int y = 1; y < year; y++) {
        total += ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
    }
    // 加当前年份之前月份的天数
    for (int m = 1; m < month; m++) {
        total += getDaysInMonth(year, m);
    }
    // 加当前月的天数
    total += day;
    return total;
}

// 构造函数
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    totalDays = calculateTotalDays(year, month, day);
}

// 获取当月最大天数
int Date::getMaxDay() const {
    return getDaysInMonth(year, month);
}

// 显示日期
void Date::show() const {
    cout << year << "-"
        << (month < 10 ? "0" : "") << month << "-"
        << (day < 10 ? "0" : "") << day;
}