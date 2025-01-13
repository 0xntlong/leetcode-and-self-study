/*
2423 Remove Letter To Equalize Frequency
    You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.
    Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.
    Note:
    The frequency of a letter x is the number of times it occurs in the string.
    You must remove exactly one letter and cannot choose to do nothing.
    Example :
    Input: word = "abcc"
    Output: true
    Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
*/

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for (char c : word){
            freq[c]++;
        }
        for (auto& [Charkey, count] : freq){
            freq[Charkey]--;
            unordered_map<int, int> Count;
            for (const auto& [key, value] : freq){
                if (value > 0){
                    Count[value]++;
                }
            }
            if (Count.size() == 1){
                freq[Charkey]++;
                return true;
            }
            freq[Charkey]++;
        }
        return false;
    }
};