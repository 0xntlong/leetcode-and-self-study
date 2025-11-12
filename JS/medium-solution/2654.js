/**
2654. Minimum Number of Operations to Make All Array Elements Equal to 1
    You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
    Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
    Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
    The gcd of two integers is the greatest common divisor of the two integers.

    Example :
    Input: nums = [2,6,3,4]
    Output: 4
    Explanation: We can do the following operations:
    - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
    - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
    - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
    - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
 */


 /**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    const gcd = (a, b) => {
        while (b !== 0) {
            const t = a % b;
            a = b;
            b = t;
        }
        return Math.abs(a);
    };
    const n = nums.length;
    let cnt1 = 0;
    for (const i of nums) 
        if (i === 1) 
            cnt1++;
    if (cnt1 > 0) 
        return n - cnt1;

    let g = 0;
    for (const i of nums) 
        g = gcd(g, i);
    if (g > 1) 
        return -1;

    let res = Number.POSITIVE_INFINITY;
    for (let i = 0; i < n; i++) {
        let cur = 0;
        for (let j = i; j < n; j++) {
            cur = gcd(cur, nums[j]);
            if (cur === 1) {
                res = Math.min(res, j - i + 1);
                break;
            }
        }
    }
    return (res - 1) + (n - 1);
};