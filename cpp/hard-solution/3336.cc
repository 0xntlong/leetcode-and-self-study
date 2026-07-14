/**
3336. Find the Number of Subsequences With Equal GCD
    You are given an integer array nums.
    Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:
    The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
    The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
    Return the total number of such pairs.
    Since the answer may be very large, return it modulo 109 + 7.

    Example:
    Input: nums = [1,2,3,4]
    Output: 10
    Explanation:
    The subsequence pairs which have the GCD of their elements equal to 1 are:
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
 */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1000000007;
        int m = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> newDp(m + 1, vector<int>(m + 1, 0));

            for (int g1 = 0; g1 <= m; g1++) {
                int nextGcd1 = gcd(g1, num);

                for (int g2 = 0; g2 <= m; g2++) {
                    int ways = dp[g1][g2];

                    if (ways == 0) {
                        continue;
                    }

                    int nextGcd2 = gcd(g2, num);

                    newDp[g1][g2] = (newDp[g1][g2] + ways) % MOD;
                    newDp[nextGcd1][g2] = (newDp[nextGcd1][g2] + ways) % MOD;
                    newDp[g1][nextGcd2] = (newDp[g1][nextGcd2] + ways) % MOD;
                }
            }

            dp = move(newDp);
        }

        int ans = 0;

        for (int g = 1; g <= m; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};