/**
2221. Find Triangular Sum of an Array
    You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
    The triangular sum of nums is the value of the only element present in nums after the following process terminates:
    Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
    For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
    Replace the array nums with newNums.
    Repeat the entire process starting from step 1.
    Return the triangular sum of nums.

    Example :
    Input: nums = [1,2,3,4,5]
    Output: 8
    Explanation:
    The above diagram depicts the process from which we obtain the triangular sum of the array.
 */


#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = (int)nums.size() - 1;
        vector<int> comb(n + 1, 0);
        comb[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                comb[j] = (comb[j] + comb[j - 1]) % 10;
            }
        }
        int res = 0;
        for (int k = 0; k <= n; ++k) {
            res = (res + nums[k] * comb[k]) % 10;
        }
        return res;
    }
};