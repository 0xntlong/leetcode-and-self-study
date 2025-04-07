/*
416. Partition Equal Subset Sum
    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
    Example :
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum & 1)
                return 0;
            int mid = sum / 2;
            bitset<10001> dp;
            dp[mid] = 1;
            for (int x : nums){
                dp |= dp >> x;
                if (dp[0])
                    return 1;
            }
            return dp[0];
        }
    };