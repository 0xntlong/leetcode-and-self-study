/**
921. Minimum Add to Make Parentheses Valid
    A parentheses string is valid if and only if:
    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.
    You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
    Return the minimum number of moves required to make s valid.

    Example :
    Input: s = "())"
    Output: 1
 */


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> stack;
        int res = 0;

        for (char c : s) {
            if (c == '(') {
                stack.push_back(c);
            }
            else if (!stack.empty() && c == ')') {
                stack.pop_back();
            }
            else if (c == ')') {
                res++;
            }
        }

        return stack.size() + res;
    }
};