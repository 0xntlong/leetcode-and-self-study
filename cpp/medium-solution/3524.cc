/**
3524. Find X Value of Array I
    You are given an array of positive integers nums, and a positive integer k.
    You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.
    You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k.
    Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.
    A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
    A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
    Note that the prefix and suffix to be chosen for the operation can be empty.
    Example :
    Input: nums = [1,2,3,4,5], k = 3
    Output: [9,2,4]
    Explanation:
    For x = 0, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove nums[2] == 3.
    For x = 1, the possible operations are:
    Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1].
    Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
    For x = 2, the possible operations are:
    Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2].
    Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes [2].
    Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5].
    Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
 */


#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) {
            return {1LL * n * (n + 1) / 2};
        }

        vector<long long> ans(k, 0);
        vector<long long> freq(k, 0);

        for (int x : nums) {
            int r = x % k;
            vector<long long> freq2(k, 0);

            ans[r]++;

            for (int j = 0; j < k; j++) {
                int prod = (j * r) % k;

                freq2[prod] += freq[j];
                ans[prod] += freq[j];
            }

            freq2[r]++;
            freq = freq2;
        }

        return ans;
    }
};