/**
3381. Maximum Subarray Sum With Length Divisible by K
    You are given an array of integers nums and an integer k.
    Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

    Example :
    Input: nums = [1,2], k = 1
    Output: 3
    Explanation:
    The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.
 */


#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> min_prefix(k, LLONG_MAX / 2);
        long long prefix = 0;
        long long res = LLONG_MIN;
        min_prefix[k - 1] = 0;
        for (int i = 0; i < n; i++){
            prefix += nums[i];
            long long& mod_min = min_prefix[i % k];
            res = max(res, prefix - mod_min);
            mod_min = min(prefix, mod_min);
        }
        return res;
    }
};