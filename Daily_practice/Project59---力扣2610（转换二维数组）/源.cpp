#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums) {
	unordered_map<int, int>count_map;

	//数出nums中每个数字的出现次数
	for (int num : nums) {
		count_map[num]++;
	}

	//定义一个输出结果
	vector<vector<int>> result;

	while (!count_map.empty()) {
		vector<int>row;

		//用来记录每个数字是否放入row中
		unordered_set<int>used_in_rows;

		for (auto it = count_map.begin(); it != count_map.end();) {
			if (used_in_rows.find(it->first) == used_in_rows.end()) {
				used_in_rows.insert(it->first);
				row.push_back(it->first);

				//减少指针指向的数据的出现次数
				it->second--;

				if (it->second == 0) {
					it = count_map.erase(it);
				}
				else {
					it++;
				}
			}
			else {
				it++;
			}
		}
		result.push_back(row);

		//清除操作
		row.clear();
		used_in_rows.clear();

	}
	return result;

}

int main() {
	vector<int> nums = { 1, 3, 4, 1, 2, 3, 1 };

	vector<vector<int>> result = findMatrix(nums);

	// 打印结果
	cout << "[";
	for (const auto& row : result) {
		cout << "[";
		for (size_t i = 0; i < row.size(); ++i) {
			cout << row[i];
			if (i < row.size() - 1) cout << ", ";
		}
		cout << "]";
		if (&row != &result.back()) cout << ", ";
	}
	cout << "]" << endl;

	return 0;
}