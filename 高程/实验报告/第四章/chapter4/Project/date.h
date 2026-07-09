#pragma once
// 日期类的定义。
// date.h
#include <iostream>
using namespace std;

class Date // 定义日期类Date
{
public:
    Date(int y = 2011, int m = 1, int d = 1);
    ~Date();
    void ShowDate();

private:
    int year;
    int month;
    int day;
};
