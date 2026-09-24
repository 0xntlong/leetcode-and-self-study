/**
3550. Smallest Index With Digit Sum Equal to Index
    You are given an integer array nums.
    Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
    If no such index exists, return -1.
    Example :
    Input: nums = [1,3,2]
    Output: 2
    Explanation:
    For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestIndex = function(nums) {
    const ans = [];

    for (let i = 0; i < nums.length; i++) {
        let res = 0;

        while (nums[i] > 0) {
            res += nums[i] % 10;
            nums[i] = Math.floor(nums[i] / 10);
        }

        if (res === i) {
            ans.push(i);
        }
    }

    ans.sort((a, b) => a - b);

    if (ans.length === 0) {
        return -1;
    } else {
        return ans[0];
    }

};