#include<iostream>
using namespace std;

int main()
{
    short score[10] = { 84, 65, 77, 60, 88, 86, 92, 93, 70, 66 };
    short* p1 = &score[0];

    cout << "Initial p1 points to: " << *p1 << " at address: " << p1 << endl;

    p1++; // Ö¸Õë¼Ó1
    cout << "After p1++: " << *p1 << " at address: " << p1 << endl;

    p1--; // Ö¸Õë¼õ1
    cout << "After p1--: " << *p1 << " at address: " << p1 << endl;

    cout << endl;


    long int* p2;
    p2 = (long int*)&score[0];
    p2++;
    cout << *p2 << " " << p2 << endl;
    p2--;
    cout << *p2 << " " << p2 << endl;


    return 0;
}