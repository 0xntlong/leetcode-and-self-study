/**
2975. Maximum Square Area by Removing Fences From a Field
    There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.
    Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).
    Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.
    Since the answer may be large, return it modulo 109 + 7.
    Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

    Example :
    Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
    Output: 4
    Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
 */



/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} hFences
 * @param {number[]} vFences
 * @return {number}
 */
var maximizeSquareArea = function(m, n, hFences, vFences) {
    const mod = 1_000_000_007n;
    hFences.push(1, m);
    vFences.push(1, n);
    hFences.sort((a, b) => a - b);
    vFences.sort((a, b) => a - b);
    const set = new Set();
    for (let i = 0; i < hFences.length; i++){
        for (let j = i + 1; j < hFences.length; j++){
            set.add(hFences[j] - hFences[i]);
        }
    }
    let maxArea = -1;
    for (let i = 0; i < vFences.length; i++){
        for (let j = i + 1; j < vFences.length; j++){
            const d = vFences[j] - vFences[i];
            if (set.has(d)){
                maxArea = Math.max(maxArea, d);
            }
        }
    }
    if (maxArea === -1)
        return -1;
    return Number((BigInt(maxArea) * BigInt(maxArea)) % mod);
}; 