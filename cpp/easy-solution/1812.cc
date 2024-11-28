/*
1812. Determine Color of a Chessboard Square
    You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.
    Return true if the square is white, and false if the square is black.
    The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.

    Example :
    Input: coordinates = "a1"
    Output: false
    Explanation: From the chessboard above, the square with coordinates "a1" is black, so return false.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a' + 1;
        int row = coordinates[1] - '0';
        return (row + col) % 2 == 1;
    }
};