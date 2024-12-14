/*
2062. Count Vowel Substrings of a String
    A substring is a contiguous (non-empty) sequence of characters within a string.
    A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
    Given a string word, return the number of vowel substrings in word.

    Example :
    Input: word = "aeiouu"
    Output: 2
    Explanation: The vowel substrings of word are as follows (underlined):
    - "aeiouu"
    - "aeiouu"
*/

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int curVowel(string&s, int a){
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> count;
        int i = 0;
        for (int j = 0; j < n; j++){
                if (!isVowel(s[j])){
                i = j + 1;
                count.clear();
                continue;
            }
            count[s[j]]++;
            for (; count.size() > a; i++){
                if (--count[s[i]] == 0)
                    count.erase(s[i]);
            }
            ans += j - i + 1;
        }
        return ans;
    }
public:
    int countVowelSubstrings(string word) {
        return curVowel(word, 5) - curVowel(word, 4);
    }
};