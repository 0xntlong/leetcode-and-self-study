/*
1861. Rotating the Box
    You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
    A stone '#'
    A stationary obstacle '*'
    Empty '.'
    The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
    It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
    Return an n x m matrix representing the box after the rotation described above.

    Example :
    Input: box = [["#",".","#"]]
    Output: [["."],
            ["#"],
            ["#"]]
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
        vector<vector<char>> rotate(cols, vector<char>(rows, '.'));
        for (int col = 0; col < rows; col++){
            int end_point = cols - 1;
            for (int c = cols - 1; c >= 0; c--){
                if (box[col][c] == '#'){
                    rotate[end_point][rows - col - 1] = '#';
                    end_point--;
                } else if (box[col][c] == '*'){
                    rotate[c][rows - col - 1] = '*';
                    end_point = c - 1;
                }
            }
        }
        return rotate;
    }
};