/**
1563. Stone Game V
    There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
    In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row
    The game ends when there is only one stone remaining. Alice's score is initially zero.
    Return the maximum score that Alice can obtain.
    Example :
    Input: stoneValue = [6,2,3,4,5,5]
    Output: 18
    Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
    In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
    The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
 */

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private:
    int search(const vector<int>& prefix, int leftBound, int rightBound) {
        int total = prefix[rightBound + 1] - prefix[leftBound];
        int start = leftBound;

        int left = leftBound;
        int right = rightBound;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int leftSum = prefix[mid + 1] - prefix[start];

            if (leftSum * 2 >= total) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<vector<int>> left(n, vector<int>(n, 0));

        vector<vector<int>> right(n,vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            left[i][i] = stoneValue[i];
            right[i][i] = stoneValue[i];
        }

        for (int length = 1; length < n; length++) {
            for (int i = 0; i < n - length; i++) {
                int j = i + length;

                int k = search(prefix, i, j);

                int total = prefix[j + 1] - prefix[i];
                int leftHalf = prefix[k + 1] - prefix[i];

                if (leftHalf * 2 == total) {
                    dp[i][j] = max(
                        left[i][k],
                        right[k + 1][j]
                    );
                } else {
                    int leftBest =
                        k == i ? 0 : left[i][k - 1];

                    int rightBest =
                        k == j ? 0 : right[k + 1][j];

                    dp[i][j] = max(
                        leftBest,
                        rightBest
                    );
                }

                left[i][j] = max(
                    left[i][j - 1],
                    total + dp[i][j]
                );

                right[i][j] = max(
                    right[i + 1][j],
                    total + dp[i][j]
                );
            }
        }

        return dp[0][n - 1];
    }
};