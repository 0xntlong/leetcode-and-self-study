/*
1614. Maximum Nesting Depth of the Parentheses
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

    Example :
    Input: s = "(1+(2*3)+((8)/4))+1"
    Output: 3
    Explanation:
    Digit 8 is inside of 3 nested parentheses in the string.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        stack<char> Stack;
        int depth = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                Stack.push(s[i]);
                if (depth < Stack.size()){
                    depth = Stack.size();
                }
            }
            else if (s[i] == ')'){
                Stack.pop();
            }
        }
        return depth;
    }
};