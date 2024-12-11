/*
2006. Count Number of Pairs With Absolute Difference K
    Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
    The value of |x| is defined as:
    x if x >= 0.
    -x if x < 0.

    Example :
    Input: nums = [1,2,2,1], k = 1
    Output: 4
    Explanation: The pairs with an absolute difference of 1 are:
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
*/

#include <vector>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if ((i < j) && abs(nums[i] - nums[j]) == k)
                    res++;
            }
        }
        return res;
    }
};