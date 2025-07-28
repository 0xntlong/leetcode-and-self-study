/**
2044. Count Number of Maximum Bitwise-OR Subsets
    Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
    The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

    Example:
    Input: nums = [3,1]
    Output: 2
    Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
    - [3]
    - [3,1]
 */



    /**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    let count = 0;
    let maxOr = 0;
    for (const num of nums){
        maxOr |= num;
    }
    const backTrack = (currOr, index) => {
        if (currOr === maxOr){
            count += 1 << (nums.length - index);
            return;
        }
        for (let i = index; i < nums.length; i++){
            backTrack(currOr | nums[i], i + 1);
        }
    };
    backTrack(0, 0);
    return count;
};