/*
2981. Find Longest Special Substring That Occurs Thrice I 
    You are given a string s that consists of lowercase English letters.
    A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
    Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
    A substring is a contiguous non-empty sequence of characters within a string.

    Example :
    Input: s = "aaaa"
    Output: 2
    Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
    It can be shown that the maximum length achievable is 2.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool substring(const string& s, int n, int x){
        vector<int> count(26, 0);
        int curr = 0;
        for (int i = 0; i < n; i++){
            while (s[curr] != s[i])
                curr++;
            if (i - curr + 1 >= x)
                count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 2)
                return true;
            }
        return false;
    }
public:
    int maximumLength(string s) {
        int n = s.size();
        int left = 1, right = n;
        if (!substring(s, n, left))
            return -1;
        while (left + 1 < right){
            int mid = ( left + right) / 2;
            if (substring(s, n, mid))
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};