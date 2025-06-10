/*
3442. Maximum Difference Between Even and Odd Frequency I
    You are given a string s consisting of lowercase English letters.
    Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.
    Return this maximum difference.


    Example :
    Input: s = "aaaaabbc"
    Output: 3
    Explanation:
    The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
    The maximum difference is 5 - 2 = 3.
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDifference(string s) {
        int odd = -1;
        int even = INT_MAX;
        vector<int> freq(26);
        for (char c : s){
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++){
            if (freq[i] % 2){
                odd = max(odd, freq[i]);
            } else if (freq[i]){
                even = min(even, freq[i]);
            }
        }
        return odd - even;
    }
};