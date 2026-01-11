#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
int removeDuplicate(vector<T>& nums) {
	if (nums.empty())
		return 0;

	int k = 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1]) {
			nums[k] = nums[i];
			++k;
		}
	}
	return k;
}

int main() {
	std::vector<int> nums = { 1, 1, 2, 2, 3, 4, 4, 5 };  // 测试数组
	int expectedNums[] = { 1, 2, 3, 4, 5 };  // 期望的结果数组

	int k = removeDuplicate(nums);  // 调用函数
	assert(k == 5);  // 验证k值是否正确

	for (int i = 0; i < k; ++i) {  // 验证nums中的前k个元素是否与期望值一致
		assert(nums[i] == expectedNums[i]);
	}

	std::cout << "All assertions passed!" << std::endl;
	return 0;
}