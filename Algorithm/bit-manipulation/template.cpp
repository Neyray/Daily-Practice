// ============================================================
// Topic : Bit Manipulation / Bitmask / Bitset DP
// Dir   : Algorithm/bit-manipulation/
// 顺序：191 -> 231 -> 136 -> 338 -> 78 -> 318 -> 416 -> 1143
// 先明确每个二进制位的含义，再考虑如何同时更新多个状态。
// 1143 是研究任务；本模板只给出状态含义和公式，不预先完成解法。
// ============================================================

#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// 191：每次清除最低位的 1，Time O(popcount(n)) / Space O(1)。
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n &= n - 1;
        ++count;
    }
    return count;
}

// 231：正整数且二进制只有一位为 1；短路求值排除非正整数。
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 136：其余元素均出现两次，异或抵消，Time O(n) / Space O(1)。
int singleNumber(const vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

// 338：清除最低位的 1 后，剩下的状态已知。输入 n >= 0。
// Time O(n) / Space O(n)。
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) dp[i] = dp[i & (i - 1)] + 1;
    return dp;
}

// 78：第 i 位表示是否选择 nums[i]，Time O(n * 2^n)。
// 这里使用 uint64_t 演示小规模子集枚举，移位数必须小于 64。
vector<vector<int>> subsets(const vector<int>& nums) {
    const size_t n = nums.size();
    if (n >= 64) throw length_error("subset mask requires fewer than 64 elements");
    vector<vector<int>> result;
    const uint64_t limit = uint64_t{1} << n;
    for (uint64_t mask = 0; mask < limit; ++mask) {
        vector<int> subset;
        for (size_t i = 0; i < n; ++i) {
            if ((mask & (uint64_t{1} << i)) != 0) subset.push_back(nums[i]);
        }
        result.push_back(subset);
    }
    return result;
}

// 318：输入为小写英文字母单词；第 c - 'a' 位表示字母是否出现。
// Time O(所有单词总长度 + 单词数^2) / Space O(单词数)。
int maxProduct(const vector<string>& words) {
    vector<uint32_t> masks(words.size(), 0);
    for (size_t i = 0; i < words.size(); ++i) {
        for (char c : words[i]) masks[i] |= uint32_t{1} << (c - 'a');
    }
    int result = 0;
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if ((masks[i] & masks[j]) == 0) {
                result = max(result, static_cast<int>(words[i].size() * words[j].size()));
            }
        }
    }
    return result;
}

// 416：输入为正整数；bits[s] 表示和 s 可达，初始只有和 0 可达。
// bits << num 基于旧状态生成新状态，再合并，因此每个数只用一次。
// std::bitset 容量在编译期确定；这里支持 target < Capacity，超出则报错。
// 典型实现按机器字并行更新；空间 O(Capacity) 位。
template <size_t Capacity = 10001>
bool canPartition(const vector<int>& nums) {
    static_assert(Capacity > 0, "bitset capacity must be positive");
    long long sum = 0;
    for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;
    const auto target = static_cast<unsigned long long>(sum / 2);
    if (target >= Capacity) throw length_error("target exceeds bitset capacity");
    bitset<Capacity> bits;
    bits.set(0);
    for (int num : nums) bits |= bits << num;
    return bits[static_cast<size_t>(target)];
}

// 1143：先完成普通二维 DP，再单独实现位并行版本（见 1143.cpp）。
// 固定 text2，第 j 位对应 text2[j]，从最低位起按下标递增编码。
// mask[c] 的第 j 位为 1，当且仅当 text2[j] == c。
// S 初始为 0；处理 text1 的每个字符后：
//   S 的第 j 位 = dp[i][j + 1] - dp[i][j]（取值只有 0 或 1）。
// 对当前字符 c，使用旧 S 同时计算：
//   X = S | mask[c]
//   Y = (S << 1) | 1
//   S = X & ~(X - Y)
// 最终答案为 popcount(S)，不是 S 的整数值。
// 减法通过借位寻找状态上升的位置，与 416 的可达和转移不同。
// C++ 单个 uint64_t 只能容纳最多 64 个位置；更长字符串须分块，
// 正确传递跨字移位进位和减法借位，并裁掉末尾超出字符串长度的位。
// 不可把 std::bitset 直接代入上式：它不提供二进制减法运算符。
