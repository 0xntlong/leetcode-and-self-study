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




function stoneGameV(stoneValue: number[]): number {
    const n: number = stoneValue.length;

    const prefix: number[] = new Array(n + 1).fill(0);

    for (let i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + stoneValue[i - 1];
    }

    const search = (leftBound: number, rightBound: number): number => {
        const total: number = prefix[rightBound + 1] - prefix[leftBound];

        const start: number = leftBound;

        let left: number = leftBound;
        let right: number = rightBound;

        while (left < right) {
            const mid: number = left + Math.floor((right - left) / 2);

            const leftSum: number = prefix[mid + 1] - prefix[start];

            if (leftSum * 2 >= total) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    };

    const dp: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));

    const left: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));

    const right: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        left[i][i] = stoneValue[i];
        right[i][i] = stoneValue[i];
    }

    for (let length = 1; length < n; length++) {
        for (let i = 0; i < n - length; i++) {
            const j: number = i + length;

            const k: number = search(i, j);

            const total: number = prefix[j + 1] - prefix[i];

            const leftHalf: number = prefix[k + 1] - prefix[i];

            if (leftHalf * 2 === total) {
                dp[i][j] = Math.max(left[i][k], right[k + 1][j]);
            } else {
                const leftBest: number = k === i ? 0 : left[i][k - 1];

                const rightBest: number = k === j ? 0 : right[k + 1][j];

                dp[i][j] = Math.max(leftBest, rightBest);
            }

            left[i][j] = Math.max(left[i][j - 1], total + dp[i][j]);

            right[i][j] = Math.max(right[i + 1][j], total + dp[i][j]);
        }
    }

    return dp[0][n - 1];
};