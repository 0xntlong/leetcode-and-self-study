/*
1351. Count Negative Numbers in a Sorted Matrix
    Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    Example:
    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.
*/

#include <vector>
using namespace std; 
class Solution {
public:
    int matrix(const vector<int> & row){
        int x = 0, y = row.size();
        while (x < y){
            int mid = x + (y - x) / 2;
            if (row[mid] < 0){
                y = mid;
            } else {
                x = mid + 1;
            }
        }
        return row.size() - x;
    }
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        for (const auto & row : grid) {
            count += matrix(row);
        }
        return count;
    }
};