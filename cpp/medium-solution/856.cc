/**
856. Score of Parentheses
    Given a balanced parentheses string s, return the score of the string.
    The score of a balanced parentheses string is based on the following rule:
    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
    Example :
    Input: s = "()"
    Output: 1
 */

#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0, b=0, p=0;
        for(char c: s){
            if (c=='('){
                b++;
                p=1;
            }
            else {
                b--;
                score+=p<<b;
                p=0;
            }
        }
        return score;
    }
};