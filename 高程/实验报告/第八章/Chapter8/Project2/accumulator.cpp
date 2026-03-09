// accumulator.cpp
#include "accumulator.h"
#include <iostream>
using namespace std;

// 构造函数
Accumulator::Accumulator(const Date& date, double value)
    : lastDate(date), value(value), sum(0) {
}

// 改变数值
void Accumulator::change(const Date& date, double newValue) {
    // 累加之前的值
    sum = getSum(date);
    lastDate = date;
    value = newValue;
}

// 重置数值
void Accumulator::reset(const Date& date, double newValue) {
    lastDate = date;
    value = newValue;
    sum = 0;
}