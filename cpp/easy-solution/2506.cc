/*
2506. Count Pair Of Similiar Strings
    You are given a 0-indexed string array words.
    Two strings are similar if they consist of the same characters.
    For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
    However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
    Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.

    Example :
    Input: words = ["aba","aabb","abcd","bac","aabc"]
    Output: 2
    Explanation: There are 2 pairs that satisfy the conditions:
    - i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
    - i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
*/

#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> freq;
        for (auto& word : words){
            int mask = 0;
            for (auto& c : word)
                mask |= 1 << (c - 'a');
            ans += freq[mask]++;
        }
        return ans;
    }
};