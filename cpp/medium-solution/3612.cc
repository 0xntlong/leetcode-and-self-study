/**
3612. Process String with Special Operations I
    You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

    Build a new string result by processing s according to the following rules from left to right:

    If the letter is a lowercase English letter append it to result.
    A '*' removes the last character from result, if it exists.
    A '#' duplicates the current result and appends it to itself.
    A '%' reverses the current result.
    Return the final string result after processing all characters in s.

    

    Example 1:

    Input: s = "a#b%*"

    Output: "ba"

    Explanation:

    i	s[i]	Operation	Current result
    0	'a'	Append 'a'	"a"
    1	'#'	Duplicate result	"aa"
    2	'b'	Append 'b'	"aab"
    3	'%'	Reverse result	"baa"
    4	'*'	Remove the last character	"ba"
    Thus, the final result is "ba".
 */

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (char c : s) {
            if (c == '*') {
                if (!res.empty()) 
                    res.pop_back();
            } else if (c == '#') {
                res += res;
            } else if (c == '%') {
                reverse(res.begin(), res.end());
            } else {
                res += c;
            }
        }
        return res;
    }
};