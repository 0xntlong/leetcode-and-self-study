/**
1262. Greatest Sum Divisible by Three
    Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

    Example 1:
    Input: nums = [3,6,5,1,8]
    Output: 18
    Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int num : nums) {
            vector<int> prev = dp; 
            for (int cur : prev) {
                int s = cur + num;
                dp[s % 3] = max(dp[s % 3], s);
            }
        }
        return dp[0];
    }
};