/*
3025. Find the Number of Ways to Place People I
    You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].
    Count the number of pairs of points (A, B), where
    A is on the upper left side of B, and
    there are no other points in the rectangle (or line) they make (including the border).
    Return the count.

    Example:
    Input: points = [[1,1],[2,2],[3,3]]
    Output: 0
    Explanation:
    There is no way to choose A and B so A is on the upper left side of B.
*/



function numberOfPairs(points: number[][]): number {
    points.sort((a, b) => (b[0] - a[0]) || (a[1] - b[1])); 
    const n = points.length;
    let res = 0;
    for (let i = 0; i < n - 1; i++) {
        let y = Infinity;
        for (let j = i + 1; j < n; j++) {
            if (y > points[j][1] && points[j][1] >= points[i][1]) {
                res++;
                y = points[j][1];
            }
        }
    }
    return res;
};