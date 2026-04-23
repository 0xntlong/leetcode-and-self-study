/**
2615. Sum of Distances
    You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
    Return the array arr.
    Example :
    Input: nums = [1,3,1,1,2]
    Output: [5,0,3,4,0]
    Explanation: 
    When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
    When i = 1, arr[1] = 0 because there is no other index with value 3.
    When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
    When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
    When i = 4, arr[4] = 0 because there is no other index with value 2. 
 */


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var distance = function(nums) {
    const d = new Map();
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (!d.has(nums[i])) 
            d.set(nums[i], []);
        d.get(nums[i]).push(i);
    }
    const res = new Array(n).fill(0);
    for (let v of d.values()) {
        if (v.length > 1) {
            const c = v.length;
            let i = v[0];
            let sum = v.reduce((a, b) => a + b, 0);
            res[i] = sum - c * i;
            let x = 0, y = c - 2;
            for (let k = 1; k < c; k++) {
                const nidx = v[k];
                res[nidx] = res[i] + (x - y) * (nidx - i);
                x++;
                y--;
                i = nidx;
            }
        }
    }
    return res;
};