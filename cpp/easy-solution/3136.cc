/**
3136. Valid Word
    A word is considered valid if:
    It contains a minimum of 3 characters.
    It contains only digits (0-9), and English letters (uppercase and lowercase).
    It includes at least one vowel.
    It includes at least one consonant.
    You are given a string word.
    Return true if word is valid, otherwise, return false.
    Notes:
    'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
    A consonant is an English letter that is not a vowel.

    Example :
    Input: word = "234Adas"
    Output: true
    Explanation:
    This word satisfies the conditions.
 */


#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        string vowels = "aeiouAEIOU";
        bool has_vowels = false;
        bool has_cons = false;
        for (char c : word){
            if (!isalnum(c)){
                return false;
            }
            if (isalpha(c)){
                if (vowels.find(c) != string::npos){
                    has_vowels = true;
                } else {
                    has_cons = true;
                }
            }
        }
        return has_vowels && has_cons;
    }
};