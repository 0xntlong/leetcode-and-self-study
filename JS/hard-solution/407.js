/*
407. Trapping Rain Water II
    Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
    
    Example :
    Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.
*/



/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    const m = heightMap.length;
    const n = heightMap[0].length;
    const volume = Array.from({ length: m }, (_, i) => heightMap[i].slice());

    let upt = true, init = true;
    while (upt) {
        upt = false;
        for (let i = 1; i < m - 1; i++) {
            for (let j = 1; j < n - 1; j++) {
                const val = Math.max(heightMap[i][j], Math.min(volume[i - 1][j], volume[i][j - 1]));
                if (init || volume[i][j] > val) {
                    volume[i][j] = val;
                    upt = true;
                }
            }
        }

        init = false;
        for (let i = m - 2; i >= 1; i--) {
            for (let j = n - 2; j >= 1; j--) {
                const val = Math.max(heightMap[i][j], Math.min(volume[i + 1][j], volume[i][j + 1]));
                if (volume[i][j] > val) {
                    volume[i][j] = val;
                    upt = true;
                }
            }
        }
    }

    let res = 0;
    for (let i = 1; i < m - 1; i++) {
        for (let j = 1; j < n - 1; j++) {
            if (volume[i][j] > heightMap[i][j]) {
                res += volume[i][j] - heightMap[i][j];
            }
        }
    }
    return res;
};