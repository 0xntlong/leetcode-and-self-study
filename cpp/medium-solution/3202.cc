/**
3202. Find the Maximum Length of Valid Subsequence II
    You are given an integer array nums and a positive integer k.
    A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
    Return the length of the longest valid subsequence of nums.

    Example:
    Input: nums = [1,2,3,4,5], k = 2
    Output: 5
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4, 5].

 */


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int count = 1;
        int prev = nums[0];
        for (int i  = 0; i < nums.size(); i++){
            if (nums[i] % 2 == 1){
                odd++;
            } else {
                even++;
            }
            if (i >= 1 && nums[i] % 2 != prev % 2){
                count++;
                prev = nums[i];
            }
        }
        return max({odd, even, count});
    }
};