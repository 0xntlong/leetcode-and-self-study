/**
3191. Minimum Operations to Make Binary Array Elements Equal to One I
    You are given a binary array nums.
    You can do the following operation on the array any number of times (possibly zero):
    Choose any 3 consecutive elements from the array and flip all of them.
    Flipping an element means changing its value from 0 to 1, and from 1 to 0.
    Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

    Example :
    Input: nums = [0,1,1,1,0,0]
    Output: 3
    Explanation:
    We can do the following operations:
    Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
    Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
    Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let count = 0;
    let n = nums.length;
    for (let i = 0; i < n; i++){
        if (nums[i] === 0){
            count++;
            if (i + 2 >= n){
                return -1;
            }
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
        }
    }
    return count;
};