/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters
    Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.
    It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
    Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

    Example 1:
    Input: s = "?zs"
    Output: "azs"
    Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
*/


#include <string>
using namespace std;
class Solution {
public:
    bool isValid(int i, int n) {
        return (i >= 0 && i < n);
    }
    string modifyString(string s) {
        int n = s.size();
        if (n == 1 && s[0] == '?') {
            return "a";
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (isValid(i + 1, n) && isValid(i - 1, n)) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (s[i - 1] != c && s[i + 1] != c) {
                            s[i] = c;
                            break;
                        }
                    }
                }
                else if (!isValid(i + 1, n) && isValid(i - 1, n)) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (s[i - 1] != c) {
                            s[i] = c;
                            break;
                        }
                    }
                }
            
                else if (isValid(i + 1, n) && !isValid(i - 1, n)) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (s[i + 1] != c) {
                            s[i] = c;
                            break;
                        }
                    }
                }
                else {
                    s[i] = 'a';  
                }
            }
        }
        
        return s;
    }
};