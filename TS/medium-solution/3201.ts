/**
3201. Find the Maximum Length of Valid Subsequence I
    You are given an integer array nums.
    A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
    Return the length of the longest valid subsequence of nums.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [1,2,3,4]
    Output: 4
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4].
 */




function maximumLength(nums: number[]): number {
    let odd = 0;
    let even = 0;
    let count = 1;
    let prev = nums[0];
    for (let i = 0; i < nums.length; i++){
        if (nums[i] % 2 === 1){
            odd++;
        } else {
            even++;
        }
        if (i >= 1 && nums[i] % 2 !== prev % 2){
            count++;
            prev = nums[i];
        }
    }
    return Math.max(odd, even, count);
};