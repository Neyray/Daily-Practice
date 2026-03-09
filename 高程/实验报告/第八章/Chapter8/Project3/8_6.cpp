#include <iostream>
#include <cmath>
using namespace std;


#define PI 3.14159

class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerim() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
    double getPerim() const override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
    double getPerim() const override {
        return 2 * PI * radius;
    }
};

int main() {
    Rectangle r1(3, 4);
    Circle c1(5);

    cout << "r1:" << r1.getArea() << " " << r1.getPerim() << endl;
    cout << "c1:" << c1.getArea() << " " << c1.getPerim() << endl;
}