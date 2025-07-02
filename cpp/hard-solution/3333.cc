/**
3333. Find the Original Typed String II
    Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
    You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
    Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
    Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: word = "aabbccdd", k = 7
    Output: 5
    Explanation:
    The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 */



#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> cnt;
        int64_t total = 1;
        int64_t mod = 1e9 + 7;
        for (int i = 0; i < word.size(); ){
            int j = i;
            while (word.size() > i++){
                if (word[i] != word[j])
                    break;
            }
            if (i > j + 1){
                cnt.push_back(i - j - 1);
                total = total * (i - j) % mod;
            }
            k--;
        }
        if (k <= 0){
            return total;
        }
        vector<int64_t> dp(k, 0);
        dp[0] = 1;
        for (int c : cnt){
            for (int i = 1; i < k; i++){
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            }
            for (int i = k - 1; i > c; i--){
                dp[i] = (dp[i] - dp[i - c - 1] + mod) % mod;
            }
        }
        for (int i = 1; i < k; i++){
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        return (total - dp[k - 1] + mod) % mod;
    }
};