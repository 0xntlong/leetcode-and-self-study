/**
3548. Equal Sum Grid Partition II

    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

    Each of the two resulting sections formed by the cut is non-empty.
    The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
    If a cell is discounted, the rest of the section must remain connected.
    Return true if such a partition exists; otherwise, return false.

    Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

    Example :
    Input: grid = [[1,4],[2,3]]
    Output: true
    Explanation:



    A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
 */



function canPartitionGrid(grid: number[][]): boolean {
    let total: number = 0;
    let rows: number = grid.length;
    if (rows === 0) 
        return false;
    let cols: number = grid[0].length;

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            total += grid[i][j];
        }
    }
    const rotate = (g: number[][]): number[][] => {
        const r = g.length;
        const c = g[0].length;
        const tmp: number[][] = Array.from({ length: c }, () => new Array(r).fill(0));
        for (let i = 0; i < r; i++) {
            for (let j = 0; j < c; j++) {
                tmp[j][r - 1 - i] = g[i][j];
            }
        }
        return tmp;
    };

    let currentGrid = grid;

    for (let r = 0; r < 4; r++) {
        const visited = new Set<number>();
        visited.add(0);
        let vals: number = 0;
        const rLen = currentGrid.length;
        const cLen = currentGrid[0].length;

        if (rLen < 2) {
            currentGrid = rotate(currentGrid);
            continue;
        }

        if (cLen === 1) {
            for (let i = 0; i < rLen - 1; i++) {
                vals += currentGrid[i][0];
                const flag = vals * 2 - total;
                if (flag === 0 || flag === currentGrid[0][0] || flag === currentGrid[i][0]) {
                    return true;
                }
            }
        } else {
            for (let i = 0; i < rLen - 1; i++) {
                for (let j = 0; j < cLen; j++) {
                    visited.add(currentGrid[i][j]);
                    vals += currentGrid[i][j];
                }
                
                const flag = vals * 2 - total;
                
                if (i === 0) {
                    if (flag === 0 || flag === currentGrid[0][0] || flag === currentGrid[0][cLen - 1]) {
                        return true;
                    }
                } else if (visited.has(flag)) {
                    return true;
                }
            }
        }
        currentGrid = rotate(currentGrid);
    }

    return false;
}