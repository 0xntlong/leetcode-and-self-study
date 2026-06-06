/**
2574. Left and Right Sum Differences
    You are given a 0-indexed integer array nums of size n.
    Define two arrays leftSum and rightSum where:
    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
    Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.
    Example :
    Input: nums = [10,4,8,3]
    Output: [15,1,11,22]
    Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
    The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
 */


function leftRightDifference(nums: number[]): number[] {
    let prefix = 0;
    let suffix = nums.reduce((a, b) => a + b, 0);
    const res: number[] = [];
    for (const i of nums) {
        prefix += i;
        res.push(Math.abs(prefix - suffix));
        suffix -= i;
    }
    return res;
};