// savingsaccount.cpp
#include "savingsaccount.h"
#include <iostream>
using namespace std;

// 构造函数
SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
    : Account(date, id), acc(date, 0), rate(rate) {
}

// 存款
void SavingsAccount::deposit(const Date& date, double amount, const string& desc) {
    acc.change(date, getBalance());  // 更新累加器
    record(date, amount, desc);
    acc.change(date, getBalance());  // 存款后更新
}

// 取款
void SavingsAccount::withdraw(const Date& date, double amount, const string& desc) {
    if (amount > getBalance()) {
        error("not enough balance");
        return;
    }
    acc.change(date, getBalance());  // 更新累加器
    record(date, -amount, desc);
    acc.change(date, getBalance());  // 取款后更新
}

// 结算利息（每年1月结算）
void SavingsAccount::settle(const Date& date) {
    if (date.getMonth() == 1) {    // 每年的一月计算一次利息
        double interest = acc.getSum(date) * rate;
        if (interest != 0) {
            record(date, interest, "interest");
        }
        acc.reset(date, getBalance());
    }
}

// 显示账户信息
void SavingsAccount::show() const {
    Account::show();
    cout << "\tRate: " << rate;
}