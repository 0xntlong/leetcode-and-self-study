/**
3423. Maximum Difference Between Adjacent Elements in a Circular Array
    Given a circular array nums, find the maximum absolute difference between adjacent elements.
    Note: In a circular array, the first and last elements are adjacent.

    Example 1:
    Input: nums = [1,2,4]
    Output: 3
    Explanation:
    Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(nums[0]);
        int maxDiff = 0;
        for (int i = 0; i < n; i++){
            maxDiff = max(maxDiff, abs(nums[i] - nums[i + 1]));
        }
        return maxDiff;
    }
};