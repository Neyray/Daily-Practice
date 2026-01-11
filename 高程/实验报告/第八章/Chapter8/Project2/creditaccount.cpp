// creditaccount.cpp
#include "creditaccount.h"
#include <iostream>
using namespace std;

// 构造函数
CreditAccount::CreditAccount(const Date& date, const string& id,
    double credit, double rate, double fee)
    : Account(date, id), acc(date, 0), credit(credit), rate(rate), fee(fee) {
}

// 存款
void CreditAccount::deposit(const Date& date, double amount, const string& desc) {
    acc.change(date, getBalance());
    record(date, amount, desc);
    acc.change(date, getBalance());
}

// 取款
void CreditAccount::withdraw(const Date& date, double amount, const string& desc) {
    if (amount > getBalance() + credit) {
        error("not enough credit");
        return;
    }
    acc.change(date, getBalance());
    record(date, -amount, desc);
    acc.change(date, getBalance());
}

// 结算利息和年费（每月结算）
void CreditAccount::settle(const Date& date) {
    // 每月计算利息
    double interest = acc.getSum(date) * rate * 30;  // 假设每月30天
    if (interest != 0) {
        record(date, -interest, "interest");
    }

    // 每年一月扣年费
    if (date.getMonth() == 1 && date.getDay() == 1) {
        record(date, -fee, "annual fee");
    }

    acc.reset(date, getBalance());
}

// 显示账户信息
void CreditAccount::show() const {
    Account::show();
    cout << "\tAvailable credit: " << getAvailableCredit();
}