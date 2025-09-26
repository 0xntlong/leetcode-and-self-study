/**
611. Valid Triangle Number
    Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
    Example 1:
    Input: nums = [2,2,3,4]
    Output: 3
    Explanation: Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3
 */




/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let count = 0;
    if (n <= 2){
        return 0;
    }
    for (let k = 2; k < n; k++){
        let i = 0;
        let j = k - 1;
        while (i < j){
            if (nums[i] + nums[j] > nums[k]){
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
};