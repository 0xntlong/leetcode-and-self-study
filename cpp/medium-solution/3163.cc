/*
3163. String Comperssion III
    Given a string word, compress it using the following algorithm: 
    Begin with an empty string comp. While word is not empty, use the following operation:
    Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
    Append the length of the prefix followed by c to comp.
    Return the string comp.

    Example :
    Input: word = "abcde"
    Output: "1a1b1c1d1e"
    Explanation:
    Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
    For each prefix, append "1" followed by the character to comp.
*/


#include <string>
using namespace std;
class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1, n = word.size();
        char idx = word[0];
        for (int i = 1; i < n; i++){
            if (word[i] == idx && count < 9)
                count++;
            else {
                comp.push_back(count + '0');
                comp.push_back(idx);
                idx = word[i];
                count = 1;
            }
        }
        comp.push_back(count + '0');
        comp.push_back(idx);
        return comp;
    }
};