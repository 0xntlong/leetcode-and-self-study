/**
1900. The Earliest and Latest Rounds Where Players Compete
    There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

    The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.

    For example, if the row consists of players 1, 2, 4, 6, 7
    Player 1 competes against player 7.
    Player 2 competes against player 6.
    Player 4 automatically advances to the next round.
    After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

    The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

    Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.

    Example :

    Input: n = 11, firstPlayer = 2, secondPlayer = 4
    Output: [3,4]
    Explanation:
    One possible scenario which leads to the earliest round number:
    First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    Second round: 2, 3, 4, 5, 6, 11
    Third round: 2, 3, 4
    One possible scenario which leads to the latest round number:
    First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    Second round: 1, 2, 3, 4, 5, 6
    Third round: 1, 2, 4
    Fourth round: 2, 4
 */



/**
 * @param {number} n
 * @param {number} firstPlayer
 * @param {number} secondPlayer
 * @return {number[]}
 */
var earliestAndLatest = function(n, firstPlayer, secondPlayer) {
    return DFS(n, Math.min(firstPlayer, secondPlayer), Math.max(firstPlayer, secondPlayer));
    function DFS(n, left, right){
        if (left + right === n + 1)
            return [1, 1];
        if (n === 3 || n === 4)
            return [2, 2];
        if (left - 1 > n - right){
            let temp = n + 1 - left;
            left = n + 1 - right;
            right = temp;
        }    
        const nextRound = Math.floor((n + 1) / 2);
        let minRound = n, maxRound = 1;
        if (right * 2 <= n + 1){
            const preL = left - 1;
            const gap = right - left - 1;
            for (let i = 0; i <= preL; i++){
                for (let j = 0; j <= gap; j++){
                    const [resMin, resMax] = DFS(nextRound, i + 1, i + j + 2);
                    minRound = Math.min(minRound, 1 + resMin);
                    maxRound = Math.max(maxRound, 1 + resMax);
                }
            }
        } else {
            const preR = n + 1 - right;
            const preL = left - 1;
            const mid = preR - left - 1;
            const innerGap = right - preR - 1;
            for (let i = 0; i <= preL; i++) {
                for (let j = 0; j <= mid; j++) {
                    const pos1 = i + 1;
                    const pos2 = i + j + 1 + Math.floor((innerGap + 1) / 2) + 1;
                    const [resMin, resMax] = DFS(nextRound, pos1, pos2);
                    minRound = Math.min(minRound, 1 + resMin);
                    maxRound = Math.max(maxRound, 1 + resMax);
                }
            }
        }
        return [minRound, maxRound];
    }
};