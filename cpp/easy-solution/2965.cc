/*
2965. Find Missing and Repeated Values
    You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
    Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
    Example 1:
    Input: grid = [[1,3],[2,2]]
    Output: [2,4]
    Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
*/

#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> res(2);
            vector<int> num(n * n + 1, 0);
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (num[grid[i][j]] == 1){
                        res[0] = grid[i][j];
                    } else {
                        num[grid[i][j]] = 1;
                    }
                }
            }
            for (int i = 1; i <= n * n; i++){
                if (num[i] == 0){
                    res[1] = i;
                    break;
                }
            }
            return res;
        }
    };