/**
1498. Number of Subsequences That Satisfy the Given Sum Condition
    You are given an array of integers nums and an integer target.
    Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

    Example :
    Input: nums = [3,5,6,7], target = 9
    Output: 4
    Explanation: There are 4 subsequences that satisfy the condition.
    [3] -> Min value + max value <= target (3 + 3 <= 9)
    [3,5] -> (3 + 5 <= 9)
    [3,5,6] -> (3 + 6 <= 9)
    [3,6] -> (3 + 6 <= 9)
 */




function numSubseq(nums: number[], target: number): number {
    const mod = 1e9 + 7;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const pows = Array(n).fill(1);
    for (let i = 1; i < n; i++){
        pows[i] = (pows[i - 1] * 2) % mod;
    }
    let left = 0, right = n - 1, res = 0;
    while (left <= right){
        if (nums[left] + nums[right] > target){
            right--;
        } else {
            res = (res + pows[right - left]) % mod;
            left++;
        }
    }
    return res;
};