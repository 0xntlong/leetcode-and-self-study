/**
3702. Longest Subsequence With Non-Zero Bitwise XOR
    You are given an integer array nums.
    Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
    Example :
    Input: nums = [1,2,3]
    Output: 2
    Explanation:
    One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<int> zeros(n, 0);

        if (nums == zeros) {
            return 0;
        }

        int x = 0;

        for (int num : nums) {
            x ^= num;
        }

        return x ? n : n - 1;
    }
};