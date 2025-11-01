/*给你字符串 s 和整数 k 。

请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

英文中的 元音字母 为（a, e, i, o, u）
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxVowels(string s, int k) {
	int n = s.length();
	int ans = 0, vowels = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u') {
			vowels++;
		}
		if (i < k - 1)continue;
		ans = max(ans, vowels);
		if (s[i - k + 1] == 'a' || s[i - k + 1] == 'o' || s[i - k + 1] == 'i' || s[i - k + 1] == 'e' || s[i - k + 1] == 'u') {
			vowels--;
		}
	}
	return ans;
}

int main() {
	string s = "abshfiuhsdiuhsihfgisd";
	int k = 3;

	cout << maxVowels(s, k) << endl;

	return 0;
}