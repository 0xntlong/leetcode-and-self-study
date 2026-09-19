/**
1401. Circle and Rectangle Overlapping
    You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
    Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

    Example :
    Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
    Output: true
    Explanation: Circle and rectangle share the point (1,0).

 */



/**
 * @param {number} radius
 * @param {number} xCenter
 * @param {number} yCenter
 * @param {number} x1
 * @param {number} y1
 * @param {number} x2
 * @param {number} y2
 * @return {boolean}
 */
var checkOverlap = function(radius, xCenter, yCenter, x1, y1, x2, y2) {
    const x = Math.max(x1, Math.min(xCenter, x2));
    const y = Math.max(y1, Math.min(yCenter, y2));

    return (xCenter - x) ** 2 + (yCenter - y) ** 2 <= radius ** 2;
};