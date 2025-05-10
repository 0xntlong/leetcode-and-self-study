/**
2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
    You are given two arrays nums1 and nums2 consisting of positive integers.
    You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.
    Return the minimum equal sum you can obtain, or -1 if it is impossible.
    Example :
    Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
    Output: 12
    Explanation: We can replace 0's in the following way:
    - Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
    - Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
    Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
 */


function minSum(nums1: number[], nums2: number[]): number {
    let sum1 : number = 0, sum2 : number = 0;
    for (let num of nums1){
        sum1 += num;
    }
    for (let num of nums2){
        sum2 += num;
    }
    const zero1 : number = nums1.filter(x => x === 0).length;
    const zero2 : number = nums2.filter(x => x === 0).length;
    
    if ((zero1 === 0 && sum1 < sum2 + zero2) || (zero2 === 0 && sum2 < sum1 + zero1)){
        return -1;
    }
    return Math.max(sum1 + zero1, sum2 + zero2);
};