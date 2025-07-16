/**
3201. Find the Maximum Length of Valid Subsequence I
    You are given an integer array nums.
    A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
    Return the length of the longest valid subsequence of nums.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [1,2,3,4]
    Output: 4
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4].
 */

 #include <vector>
#include <algorithm>
using namespace std;

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