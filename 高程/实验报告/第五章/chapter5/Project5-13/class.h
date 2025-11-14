#pragma once
#ifndef CLASS_H
#define CLASS_H

// 前向声明（避免头文件相互包含）
class X;
class Y;
class Z;

// 全局友元函数声明（在 X 中要作为 friend 使用）
void h(X*);

class Y {
public:
    void g(X* px); // 成员函数声明（稍后在 class.cpp 中定义）
};

class Z {
public:
    void f(X* px); // 成员函数声明
};

class X {
private:
    int i;
public:
    X(int v = 0);
    void print() const;

    // 友元声明
    friend void Y::g(X*); // Y::g 是 X 的友元函数
    friend class Z;       // Z 是友元类
    friend void h(X*);    // 全局函数 h 是友元
};

#endif
