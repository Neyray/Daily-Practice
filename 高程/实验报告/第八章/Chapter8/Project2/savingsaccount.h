#pragma once
// savingsaccount.h
#ifndef __SAVINGSACCOUNT_H__
#define __SAVINGSACCOUNT_H__
#include "account.h"

class SavingsAccount : public Account {
private:
    Accumulator acc;    // 用于计算利息的累加器
    double rate;        // 存款的年利率
public:
    SavingsAccount(const Date& date, const string& id, double rate);
    double getRate() const { return rate; }
    virtual void deposit(const Date& date, double amount, const string& desc);
    virtual void withdraw(const Date& date, double amount, const string& desc);
    virtual void settle(const Date& date);
    virtual void show() const;
};

#endif // __SAVINGSACCOUNT_H__