#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//快速排序
int partition(vector<int>& arr, int low, int high) {
	//定下一个比较的基准
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
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
		int mid = partition(arr, low, high);
		quickSort(arr, low, mid - 1);
		quickSort(arr, mid + 1, high);
	}
}

void Sort(vector<int>& arr) {
	quickSort(arr, 0, arr.size() - 1);
}


//归并排序
void mergeSort(vector<int>& arr, int left, int mid, int right) {
	vector<int>temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (int p = 0; p < k; ++p) {
		arr[left + p] = temp[p];
	}
}

void merge(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge(arr, left, mid);
		merge(arr, mid + 1, right);

		mergeSort(arr, left, mid, right);
	}
}

//二分查找
int binarySearch(vector<int>& arr, int target, int left, int right) {
	if (left > right)return -1;

	int mid = left + (right - left) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] > target) {
		return binarySearch(arr, target, left, mid - 1);
	}
	else {
	    return binarySearch(arr, target, mid + 1, right);
	}
}


