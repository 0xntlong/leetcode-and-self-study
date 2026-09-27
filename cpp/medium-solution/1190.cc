/**
1190. Reverse Substrings Between Each Pair of Parentheses
    You are given a string s that consists of lower case English letters and brackets.
    Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.
    Example :
    Input: s = "(abcd)"
    Output: "dcba"
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack = {""};

        for (char ch : s) {
            if (ch == '(') {
                stack.push_back("");
            }
            else if (ch == ')') {
                string temp = stack.back();
                stack.pop_back();

                reverse(temp.begin(), temp.end());
                stack.back() += temp;
            }
            else {
                stack.back() += ch;
            }
        }

        return stack[0];
    }
};