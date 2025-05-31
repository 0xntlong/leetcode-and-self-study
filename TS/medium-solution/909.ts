/**
909. Snakes and Ladders
    You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
    You start on square 1 of the board. In each move, starting from square curr, do the following:
    Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
    This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
    If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
    The game ends when you reach the square n2
    A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.
    Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
    For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
    Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.
 */


function snakesAndLadders(board: number[][]): number {
    const n = board.length;
    const cell: number[] = new Array(n * n).fill(-1);

    for (let i = n - 1; i >= 0; i -= 2) {
        for (let j = 0; j < n; j++) {
            cell[(n - 1 - i) * n + j] = board[i][j] - 1;
            if (i - 1 >= 0) {
                cell[(n - i) * n + (n - 1 - j)] = board[i - 1][j] - 1;
            }
        }
    }

    const visited: number[] = new Array(n * n).fill(-1);
    const queue: number[] = [];
    queue.push(0);
    visited[0] = 0;

    while (queue.length > 0) {
        const curr = queue.shift()!;
        if (curr === n * n - 1) {
            return visited[curr];
        }
        const maxStep = Math.min(6, n * n - 1 - curr);
        for (let i = 1; i <= maxStep; i++) {
            let nextPos = curr + i;
            if (cell[nextPos] !== -2) {
                nextPos = cell[nextPos];
            }
            if (visited[nextPos] === -1) {
                visited[nextPos] = visited[curr] + 1;
                queue.push(nextPos);
            }
        }
    }

    return -1;
};