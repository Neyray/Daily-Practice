#include<iostream>
#include<cmath>
using namespace std;
class WrongInput {};

void main()
{
    double triangle(double, double, double);
    double a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        try
        {
            if (a < 0 || b < 0 || c < 0) throw WrongInput();
            else cout << triangle(a, b, c) << endl;
        }
        catch (WrongInput) {
            cout << "输入错误！";
        }
        catch (double)
        {
            cout << "a=" <<a << "b="<<b << "c="<< c << ";不满足三角形三边条件!" << endl;
        }
        cout << "end" << endl;
    }
}

double triangle(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    if (a + b < c || c + b < a || a + c < b) throw a;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}