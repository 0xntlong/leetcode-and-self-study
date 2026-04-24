/**
2833. Furthest Point From Origin
    You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

    In the ith move, you can choose one of the following directions:
    move to the left if moves[i] = 'L' or moves[i] = '_'
    move to the right if moves[i] = 'R' or moves[i] = '_'
    Return the distance from the origin of the furthest point you can get to after n moves.

    Example :
    Input: moves = "L_RL__R"
    Output: 3
    Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
 */

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0;
        int space = 0;
        for (char c : moves){
            if (c == 'L'){
                left++;
            } else if (c == 'R'){
                right++;
            } else {
                space++;
            }
        }
        return (abs(left - right) + space);
    }
};