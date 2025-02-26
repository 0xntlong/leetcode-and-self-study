/*
1749. Maximum Absolute Sum of Any Subarray
    You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
    Return the maximum absolute sum of any (possibly empty) subarray of nums.
    Note that abs(x) is defined as follows:
    If x is a negative integer, then abs(x) = -x.
    If x is a non-negative integer, then abs(x) = x.
    
    Example 1:
    Input: nums = [1,-3,2,3,-4]
    Output: 5
    Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int maxSum = 0, minSum = 0;
            for (int i : nums){
                maxSum = max(0, maxSum + i);
                minSum = min(0, minSum + i);
            }
            return maxSum - minSum;
        }
    };