#pragma once
// accumulator.h
#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__
#include "date.h"
class Accumulator {    //将某个数值按日累加
private:
    Date lastDate;    //上次变更数值的时期
    double value;    //数值的当前值
    double sum;    //数值按日累加之和
public:
    double getSum(const Date& date) const {
        return sum + value * (date - lastDate);
    }
    //该类其它成员函数的原型和实现与例7-10完全相同，不再重复给出
};
#endif // __ACCUMULATOR_H__