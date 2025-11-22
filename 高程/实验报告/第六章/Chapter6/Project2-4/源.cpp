#include<iostream>
#include<iomanip>
using namespace std;

void selectionSort(int* const, const int);
void swap(int* const, int* const);

int main()
{
    const int arraySize = 10;
    int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    cout << "Data items in original order\n";
    for (int i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    selectionSort(a, arraySize);

    cout << "\nData items in ascending order\n";
    for (int i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    cout << endl;
    return 0;
}

void selectionSort(int* const array, const int size)
{
    int smallest;

    for (int i = 0; i < size - 1; i++)
    {
        smallest = i;

        for (int index = i + 1; index < size; index++)
        {
            if (array[index] < array[smallest])
                smallest = index;
        }

        swap(&array[i], &array[smallest]);
    }
}

void swap(int* const element1Ptr, int* const element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}