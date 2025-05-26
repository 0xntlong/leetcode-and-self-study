/*
2131. Longest Palindrome by Concatenating Two Letter Words
    You are given an array of strings words. Each element of words consists of two lowercase English letters.
    Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
    Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
    A palindrome is a string that reads the same forward and backward.
    Example :
    Input: words = ["lc","cl","gg"]
    Output: 6
    Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
    Note that "clgglc" is another longest palindrome that can be created.
 */

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26] = {0};
        for (const string& w : words){
            int a = w[0] - 'a';
            int b = w[1] - 'a';
            freq[a][b]++;
        }
        int total = 0;
        bool center = false;
        for (int i = 0; i < 26; i++){
            total += (freq[i][i] / 2) * 4;
            if (freq[i][i] % 2 == 1){
                center = true;
            }
            for (int j = i + 1; j < 26; j++){
                int pairs = min(freq[i][j], freq[j][i]);
                total += pairs * 4;
            }
        }
        if (center)
            total += 2;
        return total;
    }
};