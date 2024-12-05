/*
2337. Move Pieces to Obtain a String
    You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
    The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
    The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
    Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

    Example :
    Input: start = "_L__R__R_", target = "L______RR"
    Output: true
    Explanation: We can obtain the string target from start by doing the following moves:
    - Move the first piece one step to the left, start becomes equal to "L___R__R_".
    - Move the last piece one step to the right, start becomes equal to "L___R___R".
    - Move the second piece three steps to the right, start becomes equal to "L______RR".
    Since it is possible to get the string target from start, we return true.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        if (start == target) {
            return true;
        }
        int Left = 0;
        int Right = 0;
        
        for (int i = 0; i < start.length(); i++) {
            char curr = start[i];
            char goal = target[i];
            if (curr == 'R') {
                if (Left > 0) {
                    return false;
                }
                Right++;
            }
            if (goal == 'L') {
                if (Right > 0) {
                    return false;
                }
                Left++;
            }
            if (goal == 'R') {
                if (Right == 0) {
                    return false;
                }
                Right--;
            }
            if (curr == 'L') {
                if (Left == 0) {
                    return false;
                }
                Left--;
            }
        }
        return Left == 0 && Right == 0;
    }
};