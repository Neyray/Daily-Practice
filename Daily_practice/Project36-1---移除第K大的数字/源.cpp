#include <iostream>
#include <vector>
#include <algorithm>

// Function to remove the k-th largest element from the vector
void removeKthLargest(std::vector<int>& arr, int k) {
    // Step 1: Sort the array in descending order to find the k-th largest element
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end(), std::greater<int>());

    // Check if k is within the bounds
    if (k <= 0 || k > sortedArr.size()) {
        std::cerr << "Error: k is out of bounds" << std::endl;
        return;
    }

    // The k-th largest element
    int kthLargest = sortedArr[k - 1];

    // Step 2: Remove the k-th largest element from the original array
    auto it = std::find(arr.begin(), arr.end(), kthLargest);
    if (it != arr.end()) {
        arr.erase(it);
    }
}

int main() {
    // Example array
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int k = 3; // For example, we want to remove the 3rd largest number

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeKthLargest(arr, k);

    std::cout << "Array after removing the " << k << "rd largest element: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
