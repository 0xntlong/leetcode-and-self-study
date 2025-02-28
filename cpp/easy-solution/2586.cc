/*
2586. Count the Number of Vowel Strings in Range
    You are given a 0-indexed array of string words and two integers left and right.
    A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
    Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

    Example :
    Input: words = ["are","amy","u"], left = 0, right = 2
    Output: 2
    Explanation: 
    - "are" is a vowel string because it starts with 'a' and ends with 'e'.
    - "amy" is not a vowel string because it does not end with a vowel.
    - "u" is a vowel string because it starts with 'u' and ends with 'u'.
    The number of vowel strings in the mentioned range is 2.
*/

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        int vowelStrings(vector<string>& words, int left, int right) {
            unordered_set<char> vowels = {'a', 'e', 'u', 'i', 'o'};
            int count = 0;
            for (int i = left; i <= right; i++){
                string word = words[i];
                if (vowels.count(word.front()) && vowels.count(word.back())){
                    count++;
                }
            }
            return count;
        }
    };