/**
1039. Minimum Score Triangulation of Polygon
    You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
    Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
    You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
    Return the minimum possible score that you can achieve with some triangulation of the polygon.

    Example :
    Input: values = [1,2,3]
    Output: 6
    Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
 */





/**
 * @param {number[]} values
 * @return {number}
 */
var minScoreTriangulation = function(values) {
    const n = values.length;
    if (n === 3){
        return values[0] * values[1] * values[2];
    }
    const dp = Array.from({length : n}, () => Array(n).fill(0));
    for (let d = 2; d < n; d++){
        for (let i = 0; i + d < n; i++){
            let j = i + d;
            let e = values[i] * values[j];
            let best = Infinity;
            for (let k = i + 1; k < j; k++){
                let cand = e * values[k] + dp[i][k] + dp[k][j];
                best = Math.min(best, cand);
            }
            dp[i][j] = best;
        }
    }
    return dp[0][n - 1];
};