/**
1878. Get Biggest Three Rhombus Sums in a Grid
    You are given an m x n integer matrix grid​​​.
    A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
    Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
    Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

    Example :
    Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
    Output: [228,216,211]
    Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
    - Blue: 20 + 3 + 200 + 5 = 228
    - Red: 200 + 2 + 10 + 4 = 216
    - Green: 5 + 200 + 4 + 2 = 211
 */


class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                sums.insert(grid[i][j]);

                int k = 1;
                while (true) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                        break;

                    int total = 0;

                    for (int t = 0; t < k; t++)
                        total += grid[i - k + t][j + t];

                    for (int t = 0; t < k; t++)
                        total += grid[i + t][j + k - t];

                    for (int t = 0; t < k; t++)
                        total += grid[i + k - t][j - t];

                    for (int t = 0; t < k; t++)
                        total += grid[i - t][j - k + t];

                    sums.insert(total);
                    k++;
                }
            }
        }

        vector<int> result(sums.begin(), sums.end());
        sort(result.rbegin(), result.rend());

        if (result.size() > 3)
            result.resize(3);

        return result;
    }   
};