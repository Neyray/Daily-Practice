#include<iostream>
using namespace std;

int main()
{
    short score[10] = { 84, 65, 77, 60, 88, 86, 92, 93, 70, 66 };
    short* p1 = &score[0];
    short* p2 = score + 4;

    cout << p2 - p1 << endl;

    long int* p3, * p4;
    p3 = (long int*)&score[0];
    p4 = (long int*)(score + 4);

    cout << p4 - p3 << endl;

    return 0;
}