//»¹Ã»¿´£¡£¡£¡
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int left = i;
            int right = n - 1;
            int max_j = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long sum_val = prefix[mid + 1] - prefix[i];
                int length = mid - i + 1;
                long long product = sum_val * length;
                if (product < k) {
                    max_j = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (max_j != -1) {
                result += (max_j - i + 1);
            }
        }
        return result;
    }
};