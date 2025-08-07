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


function maxCollectedFruits(fruits: number[][]): number {
    const n = fruits.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        res += fruits[i][i];
    }

    let dpBottom: number[] = [fruits[n - 1][0], 0, 0];
    let dpRight: number[] = [fruits[0][n - 1], 0, 0];
    let maxReach = 2;

    for (let i = 1; i < n - 1; i++) {
        const newDpBottom: number[] = new Array(maxReach + 2).fill(0);
        const newDpRight: number[] = new Array(maxReach + 2).fill(0);

        for (let j = 0; j < maxReach; j++) {
            let maxB = dpBottom[j];
            if (j - 1 >= 0) maxB = Math.max(maxB, dpBottom[j - 1]);
            if (j + 1 < dpBottom.length) maxB = Math.max(maxB, dpBottom[j + 1]);
            newDpBottom[j] = maxB + fruits[n - 1 - j][i];

            let maxR = dpRight[j];
            if (j - 1 >= 0) maxR = Math.max(maxR, dpRight[j - 1]);
            if (j + 1 < dpRight.length) maxR = Math.max(maxR, dpRight[j + 1]);
            newDpRight[j] = maxR + fruits[i][n - 1 - j];
        }

        dpBottom = newDpBottom;
        dpRight = newDpRight;

        if (maxReach - n + 4 + i <= 1) maxReach++;
        if (maxReach - n + 3 + i > 1) maxReach--;
    }

    return res + dpRight[0] + dpBottom[0];
};