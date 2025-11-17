/*
1347. Minimum Number of Steps to Make Two Strings Anagram
    Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
    
    Example :
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
*/


function kLengthApart(nums: number[], k: number): boolean {
    if (k === 0) {
        return true;
    }

    let prev: number = -1;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 1) {
            if (prev !== -1 && i - prev - 1 < k) {
                return false;
            }
            prev = i;
        }
    }

    return true;
};