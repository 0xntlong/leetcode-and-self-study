/**
75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Example :
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
 */


/**
 Do not return anything, modify nums in-place instead.
 */
function sortColors(nums: number[]): void {
    let count : number[] = [0, 0, 0];
    for (let num of nums){
        count[num]++;
    }
    let idx = 0; 
    for (let i = 0; i < count.length; i++){
        while (count[i] > 0){
            nums[idx++] = i;
            count[i]--;
        }
    }
};