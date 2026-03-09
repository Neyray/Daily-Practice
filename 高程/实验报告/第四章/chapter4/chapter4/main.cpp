// main.cpp
#include "date.h"

int main()
{
    Date date1;
    Date date2(2005);
    Date date3(2006, 12, 15);

    cout << "date1:"; date1.ShowDate();
    cout << "date2:"; date2.ShowDate();
    cout << "date3:"; date3.ShowDate();

    return 0;
}
