/**
3487. Maximum Unique Subarray Sum After Deletion
    You are given an integer array nums.
    You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
    All elements in the subarray are unique.
    The sum of the elements in the subarray is maximized.
    Return the maximum sum of such a subarray.

    Example :
    Input: nums = [1,2,3,4,5]
    Output: 15
    Explanation:
    Select the entire array without deleting any element to obtain the maximum sum.
 */


#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        if (maxVal < 0){
            return maxVal;
        }
        unordered_set<int> Set(nums.begin(), nums.end());
        int res = 0;
        for (int num : Set){
            if (num >= 0){
                res += num;
            }
        }
        return res;
    }
};