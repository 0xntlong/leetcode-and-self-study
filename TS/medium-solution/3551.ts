/**
3551. Minimum Swaps to Sort by Digit Sum
    You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.
    Return the minimum number of swaps required to rearrange nums into this sorted order.
    A swap is defined as exchanging the values at two distinct positions in the array.
    Example :
    Input: nums = [37,100]
    Output: 1
    Explanation:
    Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
    Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
    Thus, the minimum number of swaps required to rearrange nums is 1.
 */



function minSwaps(nums: number[]): number {
    const n = nums.length;
    const arr: number[][] = [];

    for (let i = 0; i < n; i++) {
        let curr = nums[i];
        let digitSum = 0;

        while (curr > 0) {
            digitSum += curr % 10;
            curr = Math.floor(curr / 10);
        }

        arr.push([digitSum, nums[i], i]);
    }

    arr.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }

        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }

        return a[2] - b[2];
    });

    const perm: number[] = arr.map(item => item[2]);

    const visited: boolean[] = new Array(n).fill(false);
    let cycles = 0;

    for (let i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        cycles++;
        let j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = perm[j];
        }
    }

    return n - cycles;

};