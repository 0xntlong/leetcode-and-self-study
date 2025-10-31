/**
3289. The Two Sneaky Numbers of Digitville    
    In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.
    As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.

    Example 1:
    Input: nums = [0,1,1,0]
    Output: [0,1]
    Explanation:
    The numbers 0 and 1 each appear twice in the array.
 */


function getSneakyNumbers(nums: number[]): number[] {
    const res : number[] = new Array(2);
    let count = 0;
    for (let i = 0; i < nums.length; i++){
        for (let j = i + 1; j < nums.length; j++){
            if (nums[i] === nums[j]){
                res[count] = nums[i];
                count++;
                break;
            }
        }
    }
    return res;
};