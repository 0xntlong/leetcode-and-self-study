/**
678. Valid Parenthesis String
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
    The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Example :
    Input: s = "()"
    Output: true
 */



#include <string>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        vector<int> left;
        vector<int> star;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left.push_back(i);
            }
            else if (s[i] == '*') {
                star.push_back(i);
            }
            else if (s[i] == ')') {
                if (!left.empty()) {
                    left.pop_back();
                }
                else if (!star.empty()) {
                    star.pop_back();
                }
                else {
                    return false;
                }
            }
        }

        while (!left.empty() && !star.empty() &&
               left.back() < star.back()) {
            left.pop_back();
            star.pop_back();
        }

        if (!left.empty()) {
            return false;
        }

        return true;
    }
};