/**
1840. Maximum Building Height
    You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
    However, there are city restrictions on the heights of the new buildings:
    The height of each building must be a non-negative integer.
    The height of the first building must be 0.
    The height difference between any two adjacent buildings cannot exceed 1.
    Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
    It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
    Return the maximum possible height of the tallest building.

    Example :
    Input: n = 5, restrictions = [[2,1],[4,1]]
    Output: 2
    Explanation: The green area in the image indicates the maximum allowed height for each building.
    We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
 */


/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
var maxBuilding = function(n, restrictions) {
    if (restrictions.length === 0) {
        return n - 1;
    }

    restrictions.sort((a, b) => a[0] - b[0]);

    let idx = 1, h = 0;

    for (let i = 0; i < restrictions.length; i++) {
        const x = restrictions[i][0];
        const y = restrictions[i][1];

        restrictions[i][1] = Math.min(y, x - idx + h);

        idx = x;
        h = restrictions[i][1];
    }

    for (let i = restrictions.length - 2; i >= 0; i--) {
        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]
        );
    }

    let res = n - restrictions[restrictions.length - 1][0] + restrictions[restrictions.length - 1][1];

    idx = 1;
    h = 0;

    for (const [x, y] of restrictions) {
        const steps = x - idx - Math.abs(y - h);
        const higher = Math.max(y, h);
        res = Math.max(res, higher + Math.floor(steps / 2));
        idx = x;
        h = y;
    }
    return res;
};