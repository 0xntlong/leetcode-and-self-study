/**
3548. Equal Sum Grid Partition II

    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

    Each of the two resulting sections formed by the cut is non-empty.
    The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
    If a cell is discounted, the rest of the section must remain connected.
    Return true if such a partition exists; otherwise, return false.

    Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

    Example :
    Input: grid = [[1,4],[2,3]]
    Output: true
    Explanation:



    A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotation(const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> tmp(cols, vector<int>(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                tmp[j][rows - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        int rows = grid.size();
        if (rows == 0) 
            return false;
        int cols = grid[0].size();

        for (const auto& row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        for (int r = 0; r < 4; r++) {
            unordered_set<long long> visited;
            visited.insert(0);
            long long vals = 0;
            rows = grid.size();
            cols = grid[0].size();
            if (rows < 2) {
                grid = rotation(grid);
                continue;
            }
            if (cols == 1) {
                for (int i = 0; i < rows - 1; ++i) {
                    vals += grid[i][0];
                    long long flag = vals * 2 - total;
                    if (flag == 0 || flag == grid[0][0] || flag == grid[i][0]) {
                        return true;
                    }
                }
            } else {
                for (int i = 0; i < rows - 1; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        visited.insert(grid[i][j]);
                        vals += grid[i][j];
                    }
                    
                    long long flag = vals * 2 - total;

                    if (i == 0) {
                        if (flag == 0 || flag == grid[0][0] || flag == grid[0][cols - 1]) {
                            return true;
                        }
                    } else {
                        if (visited.find(flag) != visited.end()) {
                            return true;
                        }
                    }
                }
            }
            grid = rotation(grid);
        }

        return false;
    }
};