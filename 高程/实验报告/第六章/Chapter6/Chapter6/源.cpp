#include<iostream>
using namespace std;

void staticArrayInit(void);
void automaticArrayInit(void);
const int arraySize = 3;

int main()
{
    cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
    return 0;
}

void staticArrayInit(void)
{
    static int array1[arraySize];

    cout << "Values on entering staticArrayInit:\n";

    for (int i = 0; i < arraySize; i++)
        cout << "array1[" << i << "] = " << array1[i] << "  ";

    cout << "\nValues on exiting staticArrayInit:\n";
    for (int i = 0; i < arraySize; i++)
    {
        array1[i] += 5;
        cout << "array1[" << i << "] = " << array1[i] << "  ";
    }
    cout << endl;
}

void automaticArrayInit(void)
{
    int array2[arraySize] = { 1, 2, 3 };

    cout << "Values on entering automaticArrayInit:\n";
    for (int i = 0; i < arraySize; i++)
        cout << "array2[" << i << "] = " << array2[i] << "  ";

    cout << "\nValues on exiting automaticArrayInit:\n";

    for (int i = 0; i < arraySize; i++)
    {
        array2[i] += 5;
        cout << "array2[" << i << "] = " << array2[i] << "  ";
    }
    cout << endl;
}