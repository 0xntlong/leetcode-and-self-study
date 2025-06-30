/**
594. Longest Harmonious Subsequence
    We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
    Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

    Example :
    Input: nums = [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation:
    The longest harmonious subsequence is [3,2,2,2,3].
 */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        for (int l = 0, r = 0; r < n; r++){
            while (l < r && nums[l] < nums[r] - 1){
                l++;
            }
            if (nums[l] == nums[r] - 1){
                maxLen = max(maxLen, r - l + 1);
            }
        }
        return maxLen;
    }
};