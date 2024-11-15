/*
1668. Maximum Repeating Substring
    For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.
    Given strings sequence and word, return the maximum k-repeating value of word in sequence.

    Example 1:
    Input: sequence = "ababc", word = "ab"
    Output: 2
    Explanation: "abab" is a substring in "ababc".
*/

#include <string>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.size();
        int n = word.size();
        int Max = INT_MIN;
        int res = 0;
        for (int i = 0; i <= m - n; i++){
            if (sequence.substr(i, n) == word){
                res++;
                i += (n - 1);
            } else {
                if(res){
                    Max = max(Max, res);
                    i -= n - 1;
                    res = 0;
                }
            }
        }
        Max = max(Max, res);
        return Max;
    }
};