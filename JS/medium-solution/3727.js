/**
3727. Maximum Alternating Sum of Squares
    You are given an integer array nums. You may rearrange the elements in any order.
    The alternating score of an array arr is defined as:
    score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
    Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
    Example :
    Input: nums = [1,2,3]
    Output: 1
    Explanation:
    A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
    The alternating score is calculated as:
    score = 22 - 12 + 32 = 4 - 1 + 9 = 12
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAlternatingSum = function(nums) {
    const n = nums.length;
    const h = Math.floor(n / 2);

    const arr = nums.map(x => Math.abs(x));
    arr.sort((a, b) => a - b);

    let ans = 0;

    for (let i = 0; i < n; i++) {
        ans += (i < h ? -1 : 1) * arr[i] * arr[i];
    }

    return ans;
};