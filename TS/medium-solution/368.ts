/**
368. Largest Divisible Subset
    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.
    Example :
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
 */


    function largestDivisibleSubset(nums: number[]): number[] {
        nums.sort((a, b) => a - b);
        const n = nums.length;
        const len: number[] = new Array(n).fill(1);
        const prev: number[] = new Array(n).fill(-1);
        let maxLen = 0;
        let maxIdx = -1;
    
        for (let i = 0; i < n; i++){
            for (let j = i + 1; j < n; j++){
                if (nums[j] % nums[i] === 0 && len[j] < len[i] + 1){
                    len[j] = len[i] + 1;
                    prev[j] = i;
                }
            }
            if (len[i] > maxLen){
                maxLen = len[i];
                maxIdx = i;
            }
        }
        const ans: number[] = [];
        for (let j = maxIdx; j !== -1; j = prev[j]){
            ans.push(nums[j]);
        }
        return ans.reverse();
    };