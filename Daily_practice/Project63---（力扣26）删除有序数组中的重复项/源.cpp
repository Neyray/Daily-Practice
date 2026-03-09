/*给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//快慢指针---有序数组
int remove_Duplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < n) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}


int removeDuplicates(vector<int>& nums) {
	int size = nums.size();
	//分成两部分处理
	//第一部分用来预处理，标明每个元素是否是第一个出现的
	unordered_map<int, bool>in_map(size);
	for (int i = 0; i < size; ++i) {
		in_map[i] = false;//false表明是第一个出现的
	}

	for (int i = 0; i < size; ++i) {
		int num = nums[i];
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] == num) {
                in_map[j] = true;
            }
        }
	}

	//第二部分根据预处理的结果进行重新排布
	int curr = 0;//更新的节点
	for (int k = 0; k < size; ++k) {
		if (in_map[k] == true) {
			continue;
		}
		else {
			nums[curr] = nums[k];
			curr++;
		}
	}

	return curr;
}

int main() {
    // 测试用例1：示例1的输入
    vector<int> nums1 = { 1, 1, 2 };
    cout << "输入数组: [1, 1, 2]" << endl;
    int k1 = removeDuplicates(nums1);
    cout << "新长度: " << k1 << endl;
    cout << "修改后的数组: [";
    for (int i = 0; i < nums1.size(); ++i) {
        if (i < k1) cout << nums1[i];
        else cout << "_";
        if (i < nums1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // 测试用例2：示例2的输入
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "输入数组: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]" << endl;
    int k2 = removeDuplicates(nums2);
    cout << "新长度: " << k2 << endl;
    cout << "修改后的数组: [";
    for (int i = 0; i < nums2.size(); ++i) {
        if (i < k2) cout << nums2[i];
        else cout << "_";
        if (i < nums2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // 测试用例3：自定义测试
    vector<int> nums3 = { 1, 2, 2, 3, 4, 4, 4, 5 };
    cout << "输入数组: [1, 2, 2, 3, 4, 4, 4, 5]" << endl;
    int k3 = removeDuplicates(nums3);
    cout << "新长度: " << k3 << endl;
    cout << "修改后的数组: [";
    for (int i = 0; i < nums3.size(); ++i) {
        if (i < k3) cout << nums3[i];
        else cout << "_";
        if (i < nums3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    

    return 0;
}