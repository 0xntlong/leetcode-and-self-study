/*
1106. Parsing A Boolean Expression
    A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
    't' that evaluates to true.
    'f' that evaluates to false.
    '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
    '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    Given a string expression that represents a boolean expression, return the evaluation of that expression.

    It is guaranteed that the given expression is valid and follows the given rules.
    Example:
    Input: expression = "&(|(f))"
    Output: false
    Explanation: 
    First, evaluate |(f) --> f. The expression is now "&(f)".
    Then, evaluate &(f) --> f. The expression is now "f".
    Finally, return false.
*/

#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack;
        for (char i : expression){
            if (i != ')' && i != ',')
                stack.push(i);
            else if (i == ')'){
                vector<bool> child;
                while (!stack.empty() && stack.top() != '('){
                    char op = stack.top();
                    stack.pop();
                    if (op == 't')
                        child.push_back(true);
                    else child.push_back(false);
                }
                stack.pop();
                if(!stack.empty()){
                    char op = stack.top();
                    stack.pop();
                    bool idx = child[0];
                    if (op == '&'){
                        for (bool j : child)
                            idx &= j;
                    } else if (op == '|'){
                        for (bool j : child)
                            idx |= j;
                    } else {
                        idx = !idx;
                    }
                    if (idx)
                        stack.push('t');
                    else 
                        stack.push('f');
                
                }
            }
        }
        return stack.top() == 't' ? true : false;
    }
};