/**
960. Delete Columns to Make Sorted III
    You are given an array of n strings strs, all of the same length.
    We may choose any deletion indices, and we delete all the characters in those indices for each string.
    For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
    Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

    Example :
    Input: strs = ["babca","bbazb"]
    Output: 3
    Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
    Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
    Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs[0].size();
        int rows = strs.size();
        vector<int> dp(cols, 1);
        for (int c = 1; c < cols; c++){
            for (int j = 0; j < c; j++){
                bool valid = true;
                for (int r = 0; r < rows; r++){
                    if (strs[r][j] > strs[r][c]){
                        valid = false;
                        break;
                    }
                }
                if (valid){
                    dp[c] = max(dp[c], dp[j] + 1);
                }
            }
        }
        return cols - *max_element(dp.begin(), dp.end());
    }
};