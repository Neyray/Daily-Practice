#include <iostream>
#include <vector>
#include <algorithm>

// Function to remove the top K largest elements from the vector
void removeTopKLargest(std::vector<int>& arr, int k) {
    // Step 1: Sort the array in descending order to find the top K largest elements
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end(), std::greater<int>());

    // Check if k is within the bounds
    if (k <= 0 || k > sortedArr.size()) {
        std::cerr << "Error: k is out of bounds" << std::endl;
        return;
    }

    // The top K largest elements
    std::vector<int> topKLargest(sortedArr.begin(), sortedArr.begin() + k);

    // Step 2: Remove the top K largest elements from the original array
    for (int num : topKLargest) {
        auto it = std::find(arr.begin(), arr.end(), num);
        while (it != arr.end()) {
            arr.erase(it);
            //÷ÿµ„
            it = std::find(arr.begin(), arr.end(), num);
        }
    }
}

int main() {
    // Example array
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int k = 3; // For example, we want to remove the top 3 largest numbers

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeTopKLargest(arr, k);

    std::cout << "Array after removing the top " << k << " largest elements: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
