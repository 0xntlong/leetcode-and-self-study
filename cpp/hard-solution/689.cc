/*
689. Maximum Sum of 3 Non-Overlapping Subarrays
    Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
    Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

    Example :
    Input: nums = [1,2,1,2,6,7,5,1], k = 2
    Output: [0,3,5]
    Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
    We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
*/

#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sum_k(n - k + 1, 0), left(n - 3 * k + 1, -1);
        int maxK = sum_k[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        left[0] = 0;
        for (int i = 1; i < n - k + 1; i++){
            sum_k[i] = sum_k[i - 1] - nums[i - 1] + nums[i + k -1];
            if (i > n - 3 * k)
                continue;
            if (maxK < sum_k[i]){
                maxK = sum_k[i];
                left[i] = i;
            } else left[i] = left[i - 1];
        }
        vector<int> right(n - 3 * k + 1, -1);
        maxK = sum_k.back();
        right.back() = n - k;
        for (int i = n - k - 1; i >= 2 * k; i--){
            if (maxK <= sum_k[i]){
                maxK = sum_k[i];
                right[i - 2 * k] = i;
            } else 
                right[i - 2 * k] = right[i + 1 - 2 * k];
        }
        vector<int> res (3, -1);
        int max_3k= 0;
        for (int i = 0; i <= n - 3 * k; i++){
            int sum_3k = sum_k[left[i]] + sum_k[i + k] + sum_k[right[i]];
            if (sum_3k > max_3k){
                max_3k = sum_3k;
                res = {left[i], i + k, right[i]};
            }
        }
        return res;
    }
};