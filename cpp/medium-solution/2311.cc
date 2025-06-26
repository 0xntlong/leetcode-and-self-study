/**
2311. Longest Binary Subsequence Less Than or Equal to K
    You are given a binary string s and a positive integer k.
    Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
    Note:
    The subsequence can contain leading zeroes.
    The empty string is considered to be equal to 0.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

    Example :

    Input: s = "1001010", k = 5
    Output: 5
    Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
    Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
    The length of this subsequence is 5, so 5 is returned.
 */



class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<int> zeros(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0')
                zeros[i] = zeros[i - 1] + 1;
            else
                zeros[i] = zeros[i - 1];
        }
        int j = n - 1;
        long long sum = 0;
        int maxm = 0;
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '1') {
                while (j - i > 30) {
                    if (s[j] == '1')
                        sum -= pow(2, j - i);
                    j--;
                }
                sum += (1LL << (j - i));
            }
            while (j > i && sum > k) {
                if (s[j] == '1')
                    sum -= (1LL << (j - i));
                j--;
            }
            maxm = max(maxm, j - i + 1 + zeros[i]);
        }
        return maxm;
    }
};