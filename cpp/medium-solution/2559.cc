/*
2559. Count Vowel Strings in Ranges
    You are given a 0-indexed array of strings words and a 2D array of integers queries.
    Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
    Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
    Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

    Example :
    Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
    Output: [2,3,0]
    Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
    The answer to the query [0,2] is 2 (strings "aba" and "ece").
    to query [1,4] is 3 (strings "ece", "aa", "e").
    to query [1,1] is 0.
    We return [2,3,0].
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const unsigned vowels = 1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
        const int n = words.size(), query = queries.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + (((1 << (words[i][0] - 'a'))& vowels) && ((1<<(words[i].back() - 'a'))& vowels));
        }
        vector<int> ans(query, 0);
        for (int i = 0 ; i < query; i++){
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }
        return ans;
    }
};