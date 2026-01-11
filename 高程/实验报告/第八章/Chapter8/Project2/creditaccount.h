#pragma once
// creditaccount.h
#ifndef __CREDITACCOUNT_H__
#define __CREDITACCOUNT_H__
#include "account.h"

class CreditAccount : public Account {
private:
    Accumulator acc;    // 用于计算利息的累加器
    double credit;      // 信用额度
    double rate;        // 欠款的日利率
    double fee;         // 信用卡年费
public:
    CreditAccount(const Date& date, const string& id, double credit,
        double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {  // 可用信用额度
        return (balance < 0) ? credit + balance : credit;
    }
    virtual void deposit(const Date& date, double amount, const string& desc);
    virtual void withdraw(const Date& date, double amount, const string& desc);
    virtual void settle(const Date& date);
    virtual void show() const;
};

#endif // __CREDITACCOUNT_H__