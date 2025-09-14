#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        char currentChar = s[end];

        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {

            //charIndexMap[currentChar]返回的是该字符上一次出现的位置
            //不能写成start+=1,例如：bcadefa------------start的值为0，发现有重复字符a时，若加一，仍有重复字符；此时应在上一个位置处加一
            start = charIndexMap[currentChar] + 1;
        }

        charIndexMap[currentChar] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    std::string s;
    std::cout << "请输入一个字符串: ";
    std::cin >> s;

    int length = lengthOfLongestSubstring(s);
    std::cout << "不含有重复字符的最长子串的长度是: " << length << std::endl;

    return 0;
}
