/**
3362. Zero Array Transformation III
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
    Each queries[i] represents the following action on nums:
    Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.
    Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

    Example :
    Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
    Output: 1
    Explanation:
    After removing queries[2], nums can still be converted to a zero array.
    Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
    Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
*/


/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var maxRemoval = function(nums, queries) {
    queries.sort((a, b) => a[0] - b[0]);
    let heap = new MaxPriorityQueue();
    let edges = new Array(nums.length + 1).fill(0);
    
    let cnt = 0;
    for (let i = 0, j = 0; i < nums.length; i++){
        cnt += edges[i];
        while (j < queries.length && queries[j][0] === i){
            heap.push(queries[j][1]);
            j++;
        }
        while (cnt < nums[i] && !heap.isEmpty() && heap.front() >= i){
            cnt += 1;
            edges[heap.pop() + 1] -= 1;
        }
        if (cnt < nums[i]){
            return -1;
        }

    }
    return heap.size();
};