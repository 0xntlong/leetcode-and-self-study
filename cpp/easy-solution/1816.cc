/*
1816. Truncate Sentence
    A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).
    For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
    You are given a sentence s and an integer k. You want to truncate s such that it contains only the first k words. Return s after truncating it.
    Example :
    Input: s = "Hello how are you Contestant", k = 4
    Output: "Hello how are you"
    Explanation:
    The words in s are ["Hello", "how" "are", "you", "Contestant"].
    The first 4 words are ["Hello", "how", "are", "you"].
    Hence, you should return "Hello how are you".
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string str = "";
        string ans = "";
        int i = 0;
        int n = s.length();
        while (i < n){
            if (s[i] != ' '){
                str += s[i];
            } else {
                if (k > 1){
                    ans = ans + str + " ";
                    str = "";
                    k--;
                } else {
                    break;
                }
            }
            i++;
        }
        ans += str;
        return ans;
    }
};