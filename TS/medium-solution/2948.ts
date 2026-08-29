/*
2948. Make Lexicographically Smallest Array by Swapping Elements
    You are given a 0-indexed array of positive integers nums and a positive integer limit.
    In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
    Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
    An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

    Example :
    Input: nums = [1,5,3,9,8], limit = 2
    Output: [1,3,5,8,9]
    Explanation: Apply the operation 2 times:
    - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
    - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
    We cannot obtain a lexicographically smaller array by applying any more operations.
    Note that it may be possible to get the same result by doing different operations.

*/


function lexicographicallySmallestArray(nums: number[], limit: number): number[] {
    const n: number = nums.length;
    const pairs: number[][] = [];

    for (let i = 0; i < n; i++) {
        pairs.push([nums[i], i]);
    }

    pairs.sort((a, b) => a[0] - b[0]);

    let l: number = 0;

    while (l < n) {
        let r: number = l + 1;

        while (r < n && pairs[r][0] - pairs[r - 1][0] <= limit) {
            r++;
        }

        const group: number[] = [];

        for (let i = l; i < r; i++) {
            group.push(pairs[i][1]);
        }

        group.sort((a, b) => a - b);

        for (let i = 0; i < group.length; i++) {
            nums[group[i]] = pairs[l + i][0];
        }

        l = r;
    }

    return nums;
};