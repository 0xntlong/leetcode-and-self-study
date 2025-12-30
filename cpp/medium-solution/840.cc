/**
840. Magic Squares In Grid
    A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
    Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
    Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

    Example :
    Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
    Output: 1
    Explanation: 
    The following subgrid is a 3 x 3 magic square:
    while this one is not:
    In total, there is only one magic square inside the given grid.
 */



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int x = (int)grid.size();
        int y = (int)grid[0].size();
        int count = 0;
        auto isMagicSquare = [&](int r, int c) -> bool {
            vector<int> s;
            s.reserve(9);
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    s.push_back(grid[r + i][c + j]);
                }
            }
            vector<int> sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            for (int i = 0; i < 9; i++){
                if (sortedS[i] != i + 1)
                    return false;
            }
            return (
                s[0] + s[1] + s[2] == 15 &&
                s[3] + s[4] + s[5] == 15 &&
                s[6] + s[7] + s[8] == 15 &&
                s[0] + s[3] + s[6] == 15 &&
                s[1] + s[4] + s[7] == 15 &&
                s[2] + s[5] + s[8] == 15 &&
                s[0] + s[4] + s[8] == 15 &&
                s[2] + s[4] + s[6] == 15
            );
        };
        for (int i = 0; i <= x - 3; i++){
            for (int j = 0; j <= y - 3; j++){
                if (isMagicSquare(i, j))
                    count++;
            }
        }
        return count;
    }
};