// main.cpp
#include "date.h"

int main()
{
    Date date1(1999, 4, 20);
    cout << "date1:" << endl;
    date1.ShowDate();

    Date date2(2004, 10, 15);
    cout << "date2:" << endl;
    date2.ShowDate();

    return 0;
}
