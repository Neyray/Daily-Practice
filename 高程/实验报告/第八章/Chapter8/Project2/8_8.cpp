// 8_8.cpp
#include "account.h"
#include <iostream>
using namespace std;

int main() {
    Date date(2008, 11, 1);    // 起始日期

    // 建立几个账户
    SavingsAccount sa1(date, "S3755217", 0.015);
    SavingsAccount sa2(date, "02342342", 0.015);
    CreditAccount ca(date, "C5392394", 10000, 0.0005, 50);

    // 使用基类指针数组管理所有账户
    Account* accounts[] = { &sa1, &sa2, &ca };
    const int n = sizeof(accounts) / sizeof(Account*); // 账户总数

    cout << "(d)deposit (w)withdraw (s)show (c)change day (n)next month (e)exit" << endl;

    char cmd;
    do {
        // 显示日期和总金额
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";

        int index, day;
        double amount;
        string desc;

        cin >> cmd;
        switch (cmd) {
            // ... 主函数代码已经在课件中给出，这里不再重复
            // 只需确保上面的类定义和实现完整
        }
    } while (cmd != 'e');

    return 0;
}