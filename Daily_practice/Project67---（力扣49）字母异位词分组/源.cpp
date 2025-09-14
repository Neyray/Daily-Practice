/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>>mp;
	for (string& str : strs) {
		string key = str;
		sort(key.begin(), key.end());
		mp[key].emplace_back(str);
	}

	vector<vector<string>>ans;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		ans.emplace_back(it->second);
	}
	return ans;
}