/**
3660. Jump Game IX
    You are given an integer array nums.

    From any index i, you can jump to another index j under the following rules:
    Jump to index j where j > i is allowed only if nums[j] < nums[i].
    Jump to index j where j < i is allowed only if nums[j] > nums[i].
    For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.
    Return an array ans where ans[i] is the maximum value reachable starting from index i.
    Example:
    Input: nums = [2,1,3]
    Output: [2,2,3]
    Explanation:
    For i = 0: No jump increases the value.
    For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
    For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump increases the value.
    Thus, ans = [2, 2, 3].
 */

#include <vector>

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            res.push_back(max(res.back(), nums[i]));
        }

        int min_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (res[i] > nums[min_idx]) {
                res[i] = res[min_idx];
            }
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
        }
        return res;
    }
};