/**
2267. Check if There Is a Valid Parentheses String Path
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.
    You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
    The path starts from the upper left cell (0, 0).
    The path ends at the bottom-right cell (m - 1, n - 1).
    The path only ever moves down or right.
    The resulting parentheses string formed by the path is valid.
    Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

    Example :
    Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
    Output: true
    Explanation: The above diagram shows two possible paths that form valid parentheses strings.
    The first path shown results in the valid parentheses string "()(())".
    The second path shown results in the valid parentheses string "((()))".
    Note that there may be other valid parentheses string paths.
 */


#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int lim = (m + n) >> 1;

        if (((m + n) & 1) == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        bitset<101> mask;
        for (int i = 0; i <= lim; i++) mask.set(i);

        vector<bitset<101>> dp(n);

        dp[0].set(1);
        int p = 1;

        for (int j = 1; j < n; j++) {
            p += grid[0][j] == '(' ? 1 : -1;

            if (p < 0 || p > lim) break;

            dp[j].set(p);
        }

        p = 1;

        for (int i = 1; i < m; i++) {
            p += grid[i][0] == '(' ? 1 : -1;

            if (dp[0].none() || p < 0 || p > lim)
                dp[0].reset();
            else {
                dp[0].reset();
                dp[0].set(p);
            }

            for (int j = 1; j < n; j++) {
                dp[j] |= dp[j - 1];

                if (grid[i][j] == '(')
                    dp[j] = (dp[j] << 1) & mask;
                else
                    dp[j] >>= 1;
            }
        }

        return dp[n - 1].test(0);
    }
};