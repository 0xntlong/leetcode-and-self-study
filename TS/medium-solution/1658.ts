/**
1658. Minimum Operations to Reduce X to Zero
    You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
    Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
    Example :
    Input: nums = [1,1,4,2,3], x = 5
    Output: 2
    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
 */



function minOperations(nums: number[], x: number): number {
    let total = 0;

    for (const num of nums) {
        total += num;
    }

    const target = total - x;

    if (target < 0) {
        return -1;
    }

    let left = 0;
    let currentSum = 0;
    let maxLen = -1;

    for (let right = 0; right < nums.length; right++) {
        currentSum += nums[right];

        while (currentSum > target && left <= right) {
            currentSum -= nums[left];
            left++;
        }

        if (currentSum === target) {
            maxLen = Math.max(maxLen, right - left + 1);
        }
    }

    if (maxLen === -1) {
        return -1;
    }

    return nums.length - maxLen;
}