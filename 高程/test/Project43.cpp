// ≈≈–ÚÀ„∑®£∫—°‘Ò≈≈–Ú + øÏÀŸ≈≈–Ú
#include <iostream>
#include <vector>
using namespace std;

// —°‘Ò≈≈–Ú
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

// øÏÀŸ≈≈–Ú
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, choice;
    cin >> n >> choice;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (choice == 1) {
        selectionSort(arr);
    }
    else {
        quickSort(arr, 0, n - 1);
    }

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}