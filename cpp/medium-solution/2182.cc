/*
2182. Construct String With Repeat Limit
    You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
    Return the lexicographically largest repeatLimitedString possible.
    A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

    Example :
    Input: s = "cczazcc", repeatLimit = 3
    Output: "zzcccac"
    Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
    The letter 'a' appears at most 1 time in a row.
    The letter 'c' appears at most 3 times in a row.
    The letter 'z' appears at most 2 times in a row.
    Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
    The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
    Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
*/


#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char c : s){
            freq[c]++;
        }
        priority_queue<pair<char, int>> max_heap;
        for (auto [char_c, count] : freq){
            max_heap.push({char_c, count});
        }
        string result;
        while (!max_heap.empty()){
            auto [char1, count1] = max_heap.top();
            max_heap.pop();
            int use_count = min(count1, repeatLimit);
            result.append(use_count, char1);
            count1 -= use_count;
            if (count1 > 0){
                if (max_heap.empty()){
                    break;
                }
                auto [char2, count2] = max_heap.top();
                max_heap.pop();
                result.push_back(char2);
                count2--;
                if(count2 > 0){
                    max_heap.push({char2, count2});
                }
                max_heap.push({char1, count1});
            }
        }
        return result;
    }
};