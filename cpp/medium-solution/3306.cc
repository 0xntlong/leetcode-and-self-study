/*
3306. Count of Substrings Containing Every Vowel and K Consonants II
    You are given a string word and a non-negative integer k.
    Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

    Example :
    Input: word = "aeioqq", k = 1
    Output: 0
    Explanation:
    There is no substring with every vowel.
*/

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            int n = word.size();
            std::unordered_set<char> vowels = {'a','e','i','o','u'};
            std::unordered_map<char, int> vowelCount;
            int cons = 0, left = 0, count = 0;
            long long substr = 0;
            auto minus = [&](char c){
                if (vowels.count(c)){
                    if (--vowelCount[c] == 0){
                        vowelCount.erase(c);
                    }
                } else {
                    cons--;
                }
            };
            for (char c : word){
                if (vowels.count(c)){
                    vowelCount[c]++;
                } else {
                    cons++;
                    count = 0;
                }
                while (cons > k){
                    minus(word[left]);
                    left++;
                }
                while (cons == k && vowelCount.size() == 5){
                    count++;
                    minus(word[left]);
                    left++;
                }
                substr += count;
            }
            return substr;
        }
    };