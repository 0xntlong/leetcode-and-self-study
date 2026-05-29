/**
3300. Minimum Element After Replacement With Digit Sum
    You are given an integer array nums.
    You replace each element in nums with the sum of its digits.
    Return the minimum element in nums after all replacements.

    Example :
    Input: nums = [10,12,13,14]
    Output: 1
    Explanation:
    nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
 */


class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int n : nums){
            int curr = 0;
            while (n > 0){
                curr += n % 10;
                n /= 10;
            }
            res = min(res, curr);
        }
        return res;
    }
};