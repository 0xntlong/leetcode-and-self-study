/**
3886. Sum of Sortable Integers
    You are given an integer array nums of length n.
    An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:
    Partition nums into consecutive subarrays of length k.
    Cyclically rotate each subarray independently any number of times to the left or to the right.
    Return an integer denoting the sum of all possible sortable integers k.

    Example :
    Input: nums = [3,1,2]
    Output: 3
    Explanation:​​​​​​​
    For n = 3, possible divisors are 1 and 3.
    For k = 1: each subarray has one element. No rotation can sort the array.
    For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
    Only k = 3 is sortable. Hence, the answer is 3.
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var sortableIntegers = function(nums) {
    if (nums.length === 0) {
        return 0;
    }

    const N = nums.length;

    const divisors = [];

    for (let i = 1; i * i <= N; i++) {
        if (N % i === 0) {
            divisors.push(i);

            if (N / i !== i) {
                divisors.push(N / i);
            }
        }
    }

    let answer = 0;

    for (const d of divisors) {
        let r = 0;
        let l = 0;
        let valid = true;

        let prev_max = -Infinity;

        while (r < N) {
            const start = r;
            r += d;

            let drops = 0;
            let curr_max = -Infinity;
            let curr_min = Infinity;

            while (l < r) {
                if (l + 1 < r && nums[l] > nums[l + 1]) {
                    if (drops < 1 && nums[start] >= nums[r - 1]) {
                        drops++;
                    } else {
                        valid = false;
                        break;
                    }
                }

                curr_min = Math.min(curr_min, nums[l]);
                curr_max = Math.max(curr_max, nums[l]);
                l++;
            }

            if (!valid) {
                break;
            }

            if (curr_min < prev_max) {
                valid = false;
                break;
            }

            prev_max = curr_max;
        }

        if (valid) {
            answer += d;
        }
    }

    return answer;
};