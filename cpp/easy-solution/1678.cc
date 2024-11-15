/*
1678. Goal Parser Interpretation
    You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
    Given the string command, return the Goal Parser's interpretation of command.

    Example 1:
    Input: command = "G()(al)"
    Output: "Goal"
    Explanation: The Goal Parser interprets the command as follows:
    G -> G
    () -> o
    (al) -> al
    The final concatenated result is "Goal".
*/

#include <string>
using namespace std;
class Solution {
public:
    string interpret(string command) {
        int i, len = command.length();
        string res = "";
        for (i = 0; i < len; i++){
            if (command[i] == 'G'){
                res += command[i];
            } else if (command[i] == '(' && command[i + 1] == ')'){
                res += "o";
                i++;
            }
            else {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};