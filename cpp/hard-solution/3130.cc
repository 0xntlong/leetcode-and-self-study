/**
3130. Find All Possible Stable Binary Arrays II
    You are given 3 positive integers zero, one, and limit.
    A binary array arr is called stable if:
    The number of occurrences of 0 in arr is exactly zero.
    The number of occurrences of 1 in arr is exactly one.
    Each subarray of arr with a size greater than limit must contain both 0 and 1.
    Return the total number of stable binary arrays.
    Since the answer may be very large, return it modulo 109 + 7.

    Example:
    Input: zero = 1, one = 1, limit = 2
    Output: 2
    Explanation:
    The two possible stable binary arrays are [1,0] and [0,1].


 */


class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;

        auto comp = [&](int i) {
            std::vector<long long> ways(i + 1, 0);
            std::vector<long long> prev(i + 1, 0);
            prev[0] = 1;

            for (int k = 1; k <= i; k++) {
                std::vector<long long> curr(i + 1, 0);
                long long pref = 0;
                
                for (int j = 1; j <= i; j++) {
                    pref = (pref + prev[j - 1]) % mod;
                    
                    if (j - limit - 1 >= 0) {
                        pref = (pref - prev[j - limit - 1] + mod) % mod;
                    }
                    curr[j] = pref;
                }
                ways[k] = curr[i];
                prev = curr;
            }
            return ways;
        };

        std::vector<long long> Zero = comp(zero);
        std::vector<long long> One = comp(one);
        
        long long ans = 0;
        for (int a = 1; a <= zero; a++) {
            if (a <= one) {
                ans = (ans + Zero[a] * One[a]) % mod;
            }
            if (a - 1 >= 1 && a - 1 <= one) {
                ans = (ans + Zero[a] * One[a - 1]) % mod;
            }
        }

        for (int a = 1; a <= zero; a++) {
            if (a <= one) {
                ans = (ans + Zero[a] * One[a]) % mod;
            }
            if (a + 1 <= one) {
                ans = (ans + Zero[a] * One[a + 1]) % mod;
            }
        }

        return ans % mod;
    }
};