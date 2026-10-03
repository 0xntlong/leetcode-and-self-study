/**
32. Longest Valid Parentheses
    Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
    Example :
    Input: s = "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()".
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack = {-1};
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            }
            else {
                stack.pop_back();

                if (stack.empty()) {
                    stack.push_back(i);
                }
                else {
                    max_len = max(max_len, i - stack.back());
                }
            }
        }

        return max_len;
    }
};