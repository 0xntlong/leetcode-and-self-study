/**
1358. Number of Substrings Containing All Three Characters
    Given a string s consisting only of characters a, b and c.
    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Example :
    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
 */
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> dp(3, 0);
        int left = 0, res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            dp[s[i] - 'a']++;
            while (dp[0] > 0 && dp[1] > 0 && dp[2] > 0) {
                res += n - i;
                dp[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }
};