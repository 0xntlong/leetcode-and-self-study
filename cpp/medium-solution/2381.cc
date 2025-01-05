/*
2381. Shifting Letters II 
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
Return the final string after all such shifts to s are applied.

Example :
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int sz = shifts.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < sz; i++){
            auto& shift = shifts[i];
            int start = shift[0];
            int end = shift[1] + 1;
            int direction = shift[2] == 1 ? 1 : - 1;
            diff[start] += direction;
            diff[end] -= direction;
        }
        partial_sum(diff.begin(), diff.end(), diff.begin());
        for (int i = 0; i < n; i++){
            char& c = s[i];
            c = (diff[i] + c - 'a') % 26 + 'a';
            if (c < 'a')
                c += 26;
            
        }
        return s;
    }
};