#include<iostream>
#include<iomanip>
using namespace std;

void selectionSort(int[], const int, bool(*)(int, int));
void swap(int* const, int* const);
bool ascending(int, int);
bool descending(int, int);

int main()
{
    const int arraySize = 10;
    int order;
    int counter;
    int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    cout << "Enter 1 to sort in ascending order,\n"
        << "Enter 2 to sort in descending order: ";
    cin >> order;

    cout << "\nData items in original order\n";
    for (counter = 0; counter < arraySize; counter++)
        cout << setw(4) << a[counter];

    if (order == 1)
    {
        selectionSort(a, arraySize, ascending);
        cout << "\nData items in ascending order\n";
    }
    else
    {
        selectionSort(a, arraySize, descending);
        cout << "\nData items in descending order\n";
    }

    for (counter = 0; counter < arraySize; counter++)
        cout << setw(4) << a[counter];

    cout << endl;
    return 0;
}

void selectionSort(int work[], const int size, bool(*compare)(int, int))
{
    int smallestOrLargest;

    for (int i = 0; i < size - 1; i++)
    {
        smallestOrLargest = i;

        for (int index = i + 1; index < size; index++)
        {
            if (!(*compare)(work[smallestOrLargest], work[index]))
                smallestOrLargest = index;
        }

        swap(&work[smallestOrLargest], &work[i]);
    }
}

void swap(int* const element1Ptr, int* const element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

bool ascending(int a, int b)
{
    return a < b;
}

bool descending(int a, int b)
{
    return a > b;
}