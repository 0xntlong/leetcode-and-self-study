/**
 3363. Maximum Fruits Collected by Children
    There is a game dungeon comprised of n x n rooms arranged in a grid.
    You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

    The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
    The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
    The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
    The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
    When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
    Return the maximum number of fruits the children can collect from the dungeon.

    Example 1:
    Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
    Output: 100
    Explanation:
    In this example:
    The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
    The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
    The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
    In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.
 */



#include <vector>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            res += fruits[i][i];
        }
        vector<int> dp_bottom = {fruits[n-1][0], 0, 0};
        vector<int> dp_right = {fruits[0][n-1], 0, 0};
        int max_reach = 2;
        for (int i = 1; i < n - 1; i++){
            vector<int> new_dp_bottom(max_reach + 2, 0);
            vector<int> new_dp_right(max_reach + 2, 0);
            for (int j = 0; j < max_reach; j++){
                int max_b = dp_bottom[j];
                if (j - 1 >= 0)
                    max_b = max(max_b, dp_bottom[j - 1]);
                if (j + 1 < dp_bottom.size())
                    max_b = max(max_b, dp_bottom[j + 1]);
                new_dp_bottom[j] = max_b + fruits[n - 1 - j][i];
                int max_r = dp_right[j];
                if (j - 1 >= 0)
                    max_r = max(max_r, dp_right[j - 1]);
                if (j + 1 < dp_right.size())
                    max_r = max(max_r, dp_right[j + 1]);
                new_dp_right[j] = max_r + fruits[i][n - 1 - j];
            }
            dp_bottom = new_dp_bottom;
            dp_right = new_dp_right;
            if (max_reach - n + 4 + i <= 1)
                max_reach++;
            if (max_reach - n + 3 + i > 1)
                max_reach--;
        }
        return res + dp_right[0] + dp_bottom[0];
    }
};