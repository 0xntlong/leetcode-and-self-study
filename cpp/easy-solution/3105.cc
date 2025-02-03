/*
3105. Longest Strictly Increasing or Strictly Decreasing Subarray
    You are given an array of integers nums. Return the length of the longest 
    subarray of nums which is either strictly increasing or strictly decreasing
    
    Example 1:
    Input: nums = [1,4,3,3,2]
    Output: 2
    Explanation:
    The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
    The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
    Hence, we return 2.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int res = 0;
        int inc = 1, dec = 1;
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i - 1]){
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]){
                dec++;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            res = max({res, inc, dec});
        }
        return res;
    }
};