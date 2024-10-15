/**
 * 20. Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example:
 * Input: s = "()"
 * Output: true
 */

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> sym;
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
            return false;
        }
        for (char i : s) {
            if (i == '(' || i == '[' || i == '{') {
                sym.push(i);
            } 
            else if (!sym.empty() && (sym.top() == '(' || sym.top() == '[' || sym.top() == '{')) {
                if ((i == ')' && sym.top() == '(') || (i == ']' && sym.top() == '[') || (i == '}' && sym.top() == '{')) {
                    sym.pop(); 
                } else {
                    return false; 
                }
            } else {
                return false; 
            }
        }
        return sym.empty();
    }
};