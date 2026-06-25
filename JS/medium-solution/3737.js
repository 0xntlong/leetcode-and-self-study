/**
3737. Count Subarrays With Majority Element I
    You are given an integer array nums and an integer target.
    Return the number of subarrays of nums in which target is the majority element.
    The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.
    Example :

    Input: nums = [1,2,2,3], target = 2
    Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
    nums[1..1] = [2]
    nums[2..2] = [2]
    nums[1..2] = [2,2]
    nums[0..2] = [1,2,2]
    nums[1..3] = [2,2,3]
    So there are 5 such subarrays.
 */



/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var countMajoritySubarrays = function(nums, target) {
    let balance = 0;
    const cnt = new Map();
    cnt.set(0, 1);
    let res = 0;
    let curr = 0;
    for (const x of nums) {
        if (x === target) {
            curr += cnt.get(balance) || 0;
            balance++;
        } else {
            balance--;
            curr -= cnt.get(balance) || 0;
        }
        cnt.set(balance, (cnt.get(balance) || 0) + 1);
        res += curr;
    }
    return res;
};