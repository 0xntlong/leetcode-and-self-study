/**
3300. Minimum Element After Replacement With Digit Sum
    You are given an integer array nums.
    You replace each element in nums with the sum of its digits.
    Return the minimum element in nums after all replacements.

    Example :
    Input: nums = [10,12,13,14]
    Output: 1
    Explanation:
    nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
 */


function minElement(nums: number[]): number {
    let res: number = Infinity;
    for (let x of nums) {
        let curr: number = 0;
        while (x > 0) {
            curr += x % 10;
            x = Math.floor(x / 10);
        }
        res = Math.min(res, curr);
    }
    return res;
};