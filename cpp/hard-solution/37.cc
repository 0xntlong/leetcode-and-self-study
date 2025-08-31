/*
37. Sudoku Solver
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.

    

    Example 1:


    Input: board = [["5","3",".",".","7",".",".",".","."],
                    ["6",".",".","1","9","5",".",".","."],
                    [".","9","8",".",".",".",".","6","."],
                    ["8",".",".",".","6",".",".",".","3"],
                    ["4",".",".","8",".","3",".",".","1"],
                    ["7",".",".",".","2",".",".",".","6"],
                    [".","6",".",".",".",".","2","8","."],
                    [".",".",".","4","1","9",".",".","5"],
                    [".",".",".",".","8",".",".","7","9"]]

    Output:         [["5","3","4","6","7","8","9","1","2"],
                    ["6","7","2","1","9","5","3","4","8"],
                    ["1","9","8","3","4","2","5","6","7"],
                    ["8","5","9","7","6","1","4","2","3"],
                    ["4","2","6","8","5","3","7","9","1"],
                    ["7","1","3","9","2","4","8","5","6"],
                    ["9","6","1","5","3","7","2","8","4"],
                    ["2","8","7","4","1","9","6","3","5"],
                    ["3","4","5","2","8","6","1","7","9"]]
*/


#include <unordered_set>
#include <array>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        array<unordered_set<int>, 9> rows, cols, boxes;
        for (int i = 0; i < 9; i++){
            for (int d = 1; d <= 9; d++){
                rows[i].insert(d);
                cols[i].insert(d);
                boxes[i].insert(d);
            }
        }
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    int v = board[i][j] - '0';
                    rows[i].erase(v);
                    cols[j].erase(v);
                    boxes[(i / 3) * 3 + (j / 3)].erase(v);
                }
            }
        }
        function<bool(int, int)> backtrack = [&](int i, int j) -> bool {
            if (board[i][j] != '.'){
                if (i == 8 && j == 8)
                    return true;
                if (j < 8)
                    return backtrack(i, j + 1);
                else
                    return backtrack(i + 1, 0);
            }
            int b = (i / 3) * 3 + (j / 3);
            vector<int> candidates;
            for (int d = 1; d <= 9; d++){
                if (rows[i].count(d) && cols[j].count(d) && boxes[b].count(d)){
                    candidates.push_back(d);
                }
            }
            for (int d : candidates){
                board[i][j] = char('0' + d);
                rows[i].erase(d);
                cols[j].erase(d);
                boxes[b].erase(d);
                bool done = false;
                if (i == 8 && j == 8)
                    done = true;
                else if (j < 8)
                    done = backtrack(i, j + 1);
                else 
                    done = backtrack(i + 1, 0);
                if (done)
                    return true;
                board[i][j] = '.';
                rows[i].insert(d);
                cols[j].insert(d);
                boxes[b].insert(d);
            }
            return false;
        };
        backtrack(0, 0);
    }
};