/**
1727. Largest Submatrix With Rearrangements
    You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
    Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

    Example :
    Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    Output: 4
    Explanation: You can rearrange the columns as shown above.
    The largest submatrix of 1s, in bold, has an area of 4.
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto& row : matrix) {

            for (int j = 0; j < n; j++)
                heights[j] = row[j] ? heights[j] + 1 : 0;

            vector<int> sortedH = heights;
            sort(sortedH.begin(), sortedH.end(), greater<int>());

            for (int j = 0; j < n; j++)
                maxArea = max(maxArea, sortedH[j] * (j + 1));
        }

        return maxArea;
    }
};