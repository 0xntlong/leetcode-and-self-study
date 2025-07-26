/**
3480. Maximize Subarrays After Removing One Conflicting Pair
    You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.
    Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].
    Return the maximum number of subarrays possible after removing exactly one conflicting pair.
    Example :
    Input: n = 4, conflictingPairs = [[2,3],[1,4]]
    Output: 9
    Explanation:
    Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
    There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
    The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
*/



/**
 * @param {number} n
 * @param {number[][]} conflictingPairs
 * @return {number}
 */
var maxSubarrays = function(n, conflictingPairs) {
    const conflict = Array.from({length : n + 1}, () => []);
    for (const [u, v] of conflictingPairs){
        conflict[Math.max(u, v)].push(Math.min(u, v));
    }
    let res = 0;
    let maxDiff = 0, maxLeft = 0;
    const prefix = new Array(n + 1).fill(0);
    for (let r = 1; r <= n; r++){
        for (const l of conflict[r]){
            if (l > maxDiff){
                const temp = maxDiff;
                maxDiff = l;
                maxLeft = temp;
            } else if (l > maxLeft){
                maxLeft = l;
            }
        }
        res += r - maxDiff;
        if (maxDiff > 0){
            prefix[maxDiff] += maxDiff - maxLeft;
        }
    }
    const maxBonus = Math.max(...prefix);
    return res + maxBonus;
};