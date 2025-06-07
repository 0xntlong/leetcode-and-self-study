/*
3170. Lexicographically Minimum String After Removing Stars
    You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
    While there is a '*', do the following operation:
    Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
    Return the lexicographically smallest resulting string after removing all '*' characters.

    Example :
    Input: s = "aaba*"
    Output: "aab"
    Explanation:
    We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 */

#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    string clearStars(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        vector<vector<int>> alpha (26, vector<int>());
        char ch;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '*'){
                ch = pq.top();
                s[alpha[ch - 'a'].back()] = '!';
                alpha[ch - 'a'].pop_back();
                if (alpha[ch - 'a'].size() == 0){
                    pq.pop();
                }
                continue;
            }
            if (alpha[s[i] - 'a'].size() == 0){
                pq.push(s[i]);
            }
            alpha[s[i] - 'a'].push_back(i);
        }
        string res = "";
        for (char c : s){
            if (c >= 'a'){
                res += c;
            }
        }
        return res;
    }
};