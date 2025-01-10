/*
916. Word Subsets
    You are given two string arrays words1 and words2.
    A string b is a subset of string a if every letter in b occurs in a including multiplicity.
    For example, "wrr" is a subset of "warrior" but is not a subset of "world".
    A string a from words1 is universal if for every string b in words2, b is a subset of a.
    Return an array of all the universal strings in words1. You may return the answer in any order.

    Example :
    Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
    Output: ["facebook","google","leetcode"]
*/

#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    inline bool isUniverse(array<int, 26>& s1, array<int, 26>& s2){
        for (int i = 0; i < 26; i++)
            if (s1[i] < s2[i])
                return 0;
        return 1;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        array<int, 26> maxFreq={0};
        for (auto& word : words2){
            array<int, 26> freq = {0};
            for (char c : word){
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++){
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        vector<string> res;
        res.reserve(words1.size());
        for (auto& word : words1){
            array<int, 26> freq{0};
            for (char c : word){
                freq[c - 'a']++;
            }
            if (isUniverse(freq, maxFreq)){
                res.push_back(word);
            }
        }
        return res;
    }
};