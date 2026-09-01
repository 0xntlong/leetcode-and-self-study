/**
3568. Minimum Moves to Clean the Classroom
    You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
    'S': Starting position of the student
    'L': Litter that must be collected (once collected, the cell becomes empty)
    'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
    'X': Obstacle the student cannot pass through
    '.': Empty space
    You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.
    Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.
    Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.
    Example :
    Input: classroom = ["S.", "XL"], energy = 2
    Output: 2
    Explanation:
    The student starts at cell (0, 0) with 2 units of energy.
    Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
    A valid sequence of moves to collect all litter is as follows:
    Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
    Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
    The student collects all the litter using 2 moves. Thus, the output is 2.
 */



function minMoves(classroom: string[], energy: number): number {
    const m: number = classroom.length;
    const n: number = classroom[0].length;

    const litterId: number[][] = Array.from({ length: m }, () => new Array(n).fill(-1));

    let k: number = 0;
    let sr: number = 0;
    let sc: number = 0;

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            if (classroom[r][c] === 'S') {
                sr = r;
                sc = c;
            } else if (classroom[r][c] === 'L') {
                litterId[r][c] = k++;
            }
        }
    }

    if (k === 0) {
        return 0;
    }

    const fullMask: number = (1 << k) - 1;

    const best: number[][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => new Array(1 << k).fill(-1))
    );

    const queue: number[][] = [];
    let front: number = 0;

    best[sr][sc][0] = energy;
    queue.push([sr, sc, 0, energy, 0]);

    const dirs: number[][] = [[-1, 0], [1, 0], [0, -1], [0, 1]];

    while (front < queue.length) {
        const [r, c, mask, e, moves] = queue[front++];

        for (const [dr, dc] of dirs) {
            const nr: number = r + dr;
            const nc: number = c + dc;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (classroom[nr][nc] === 'X') {
                continue;
            }

            let ne: number = e - 1;

            if (ne < 0) {
                continue;
            }

            let nmask: number = mask;

            if (classroom[nr][nc] === 'R') {
                ne = energy;
            }

            if (classroom[nr][nc] === 'L') {
                nmask |= 1 << litterId[nr][nc];
            }

            if (nmask === fullMask) {
                return moves + 1;
            }

            if (ne <= best[nr][nc][nmask]) {
                continue;
            }

            best[nr][nc][nmask] = ne;
            queue.push([nr, nc, nmask, ne, moves + 1]);
        }
    }

    return -1;
};