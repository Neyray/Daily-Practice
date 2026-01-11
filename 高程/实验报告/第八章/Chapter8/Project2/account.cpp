// account.cpp
#include "account.h"
#include <iostream>
using namespace std;

// 初始化静态成员
double Account::total = 0;

// Account 构造函数
Account::Account(const Date& date, const string& id)
    : id(id), balance(0) {
    cout << date.getYear() << "-"
        << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << "-"
        << (date.getDay() < 10 ? "0" : "") << date.getDay()
        << "\t#" << id << " created" << endl;
}

// 记录交易
void Account::record(const Date& date, double amount, const string& desc) {
    balance += amount;
    total += amount;
    cout << date.getYear() << "-"
        << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << "-"
        << (date.getDay() < 10 ? "0" : "") << date.getDay()
        << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

// 显示账户信息（基类实现）
void Account::show() const {
    cout << id << "\tBalance: " << balance;
}

// 错误处理
void Account::error(const string& msg) const {
    cout << "Error: " << msg << endl;
}