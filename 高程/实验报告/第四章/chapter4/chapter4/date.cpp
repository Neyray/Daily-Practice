// date.cpp
#include "date.h"

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    cout << "constructing…" << endl;
}

void Date::ShowDate()
{
    cout << "Date：" << year << "." << month << "." << day << endl;
}
