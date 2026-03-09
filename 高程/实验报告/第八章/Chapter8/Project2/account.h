// account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "date.h"
#include "accumulator.h"
#include <string>
#include <iostream>

class Account {
private:
    std::string id;    // 帐号
    double balance;    // 余额
    static double total;    // 所有账户的总金额
protected:
    Account(const Date& date, const std::string& id);
    void record(const Date& date, double amount, const std::string& desc);
    void error(const std::string& msg) const;
public:
    const std::string& getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    // 纯虚函数
    virtual void deposit(const Date& date, double amount,
        const std::string& desc) = 0;
    virtual void withdraw(const Date& date, double amount,
        const std::string& desc) = 0;
    virtual void settle(const Date& date) = 0;
    virtual void show() const;
    virtual ~Account() {}
};

// 包含派生类的头文件
#include "savingsaccount.h"
#include "creditaccount.h"

#endif // __ACCOUNT_H__