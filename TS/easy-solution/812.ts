/**
812. Largest Triangle Area
    Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

    Example:

    Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    Output: 2.00000
    Explanation: The five points are shown in the above figure. The red triangle is the largest.
 */




function largestTriangleArea(points: number[][]): number {
    let maxArea = 0;
    const n = points.length;
    for (let i = 0; i < n; i++){
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; j++){
            const [x2, y2] = points[j];
            for (let k = j + 1; k < n; k++){
                const[x3, y3] = points[k];
                const curr = Math.abs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
                maxArea = Math.max(maxArea, curr);
            }
        }
    }
    return maxArea;
};