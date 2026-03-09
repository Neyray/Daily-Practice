#include<iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;  // ´¿Ðéº¯Êý
    virtual ~Shape() {}
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}
    double getArea() override { return width * height; }
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double r = 0) : radius(r) {}
    double getArea() override { return 3.14159 * radius * radius; }
};

class Square : public Rectangle {
public:
    Square(double side = 0) : Rectangle(side, side) {}
};

int main() {
    Rectangle rect(5, 3);
    Circle circle(4);
    Square square(6);

    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Square area: " << square.getArea() << endl;

    return 0;
}