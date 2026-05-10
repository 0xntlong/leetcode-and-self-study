/**
2770. Maximum Number of Jumps to Reach the Last Index
    You are given a 0-indexed array nums of n integers and an integer target.
    You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:
    0 <= i < j < n
    -target <= nums[j] - nums[i] <= target
    Return the maximum number of jumps you can make to reach index n - 1.
    If there is no way to reach index n - 1, return -1.
    Example :
    Input: nums = [1,3,6,4,1,2], target = 2
    Output: 3
    Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
    - Jump from index 0 to index 1. 
    - Jump from index 1 to index 3.
    - Jump from index 3 to index 5.
    It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3. 
 */




class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (-target <= nums[i] - nums[j] &&
                    nums[i] - nums[j] <= target) {
                    if (dp[j] > -1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};