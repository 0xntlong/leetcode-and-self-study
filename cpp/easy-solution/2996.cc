/**
2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
    You are given a 0-indexed array of integers nums.
    A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.
    Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

    Example :
    Input: nums = [1,2,3,2,5]
    Output: 6
    Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
*/



class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = nums[0];
        int n = nums.size();

        if (n == 1) {
            return prefix + 1;
        }

        int i = 1;

        while (i < n && nums[i] == nums[i - 1] + 1) {
            prefix += nums[i];
            i++;
        }

        unordered_set<int> present(nums.begin(), nums.end());

        while (present.count(prefix)) {
            prefix++;
        }

        return prefix;
    }
};